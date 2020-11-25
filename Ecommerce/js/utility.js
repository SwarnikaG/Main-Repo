function validateEmail(){
    var emailField = document.getElementById("result").value;
    atpos = emailField.indexOf("@");
    dotpos = emailField.lastIndexOf(".");

    if (atpos < 1 || ( dotpos - atpos < 2 )) {
        document.getElementById("result").className = "email-warning";
        return false;
    }
    document.getElementById("result").className = "email-valid";
    return true;

}

$(document).ready(function(){
    $("select").change(function(){
        $(this).find("option:selected").each(function(){
            var optionValue = $(this).attr("value");
            if(optionValue){
                $(".box").not("." + optionValue).hide();
                $("." + optionValue).show();
            } 
            else{
                $(".box").hide();
            }
        });
    }).change();
});