
//detecting mouse press

for(var i=0;i< document.querySelectorAll(".drum").length ;i++){
    document.querySelectorAll(".drum")[i].addEventListener("click",function(){
        var buttonLetter = this.innerHTML;
        playSound(buttonLetter);
        animation(buttonLetter);
        
    });
    

}

//detecting key press

document.addEventListener("keypress", function(event){

playSound(event.key);
animation(event.key);

});

//playing sound

function playSound(key){
switch(key){
    case "w":
        var crash = new Audio("sounds/crash.mp3");
        crash.play();
        break;
    case "a":
        var kick_bass = new Audio("sounds/kick-bass.mp3");
        kick_bass.play();
        break;   
    case "s":
        var snare = new Audio("sounds/snare.mp3");
        snare.play();
        break; 
    case "d":
        var tom_1 = new Audio("sounds/tom-1.mp3");
        tom_1.play();
        break; 
    case "j":
        var tom_2 = new Audio("sounds/tom-2.mp3");
        tom_2.play();
        break;  
    case "k":
        var tom_3 = new Audio("sounds/tom-3.mp3");
        tom_3.play();
        break;   
    case "l":
        var tom_4 = new Audio("sounds/tom-4.mp3");
        tom_4.play();
        break;        
    default : console.log(buttonLetter);
}
}


// adding animation
function animation(currentKey){

    var activeButton = document.querySelector("." + currentKey);  // to find out which key is pressed or clicked

    activeButton.classList.add("pressed"); // adding "pressed" css class to the active button to show animation


    //now here is a problem once animation is added it live there forever but animation should return to orginal state after some time
    // so we have to add some timeout 
    // to remove the pressed class that be added after some time 

    setTimeout(function(){
        activeButton.classList.remove("pressed")
    },100);
    


}










