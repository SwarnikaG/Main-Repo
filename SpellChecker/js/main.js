// $(document).mouseup(function(e) 
// {
//     var container = document.getElementById("suggestion");
//     if (!container.is(e.target) && container.has(e.target).length === 0) 
//     {
//         container.style.display = "none";
//     }
// });
let betterwords = new Map();

function ReadFile(files){	
    let file = inputfile.files[0];	
    let reader = new FileReader();	
    reader.readAsText(file);	
    reader.onload = function(){	
        filecontent.value = reader.result;
        spellCheck();	         
    }	
}	

async function spellCheck() {	
    let badwords=[];
    var text = filecontent.value;
    let url = "https://api.textgears.com/spelling?key=1gVny1rfj02gy7kY&text=" + text + "!&language=en-GB";	
    let response = await fetch(url);
    let user = await response.json();
    console.log(user);	
    for(const item of user.response.errors){
        badwords.push(item.bad);
        betterwords.set(item.bad,item.better);
        
    }
    console.log(badwords);
    console.log(betterwords);
    for (const [key, value] of betterwords.entries()) {
        console.log(key, value);
      }
    document.getElementById('result').innerHTML = transformContent(text, badwords);
    autoCorrect();
}	

function transformContent(content, keywords){
  let temp = content;

  keywords.forEach(keyword => {
    temp = temp.replace(new RegExp(keyword, 'ig'), wrapKeywordWithHTML(keyword, `https://www.google.com/search?q=${keyword}`));
  })

  return temp;
}

function wrapKeywordWithHTML(keyword, url){
  return `<a href="${url}" target="_blank"> <span style="font-weight: bold; color: red; font-size: 30px">  ${keyword}  </span> </a>`
}

function autoCorrect(){
    let typo_spans = document.querySelectorAll("span");

    typo_spans.forEach(
        (typo_span_i,idx)=>{
            typo_span_i.addEventListener("contextmenu",(event)=>{
                event.preventDefault();
                let ans_div = document.getElementById('suggestion');
                posDiv(ans_div,event.pageX, event.pageY);
                suggestion_content = "<ul>";
                let abc = `correct(${typo_span_i}, this);`;
                var which_typo = typo_span_i.textContent.trim();
                for (const [which_typo, value] of betterwords.entries()) {
                    suggestion_content += `<li onclick =abc>` +value +`</li>`;
                }
                suggestion_content += "<ul>";
                ans_div.innerHTML = suggestion_content;
                return false;
            });
        }
    );
}

function correct(word, ref){
    console.log(word);
    console.log(ref);
}

function posDiv(a,x,y){
    a.style.display = "block";
    a.style.position = "absolute";
    a.style.left=x+'px';
    a.style.top=y+'px';
    a.style.backgroundColor = 'whitesmoke';
}