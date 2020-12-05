
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
    var text = filecontent.value;
    let url = "https://api.textgears.com/spelling?key=1gVny1rfj02gy7kY&text=" + text + "!&language=en-GB";	
    let response = await fetch(url);	
    if (response.ok) {	
        console.log(response.json()); 	
    }	
}	
