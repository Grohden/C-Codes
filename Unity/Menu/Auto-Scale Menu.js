//Buttons size
var sizeH:float;
var sizeW:float;

//Center the things
var Center:float;

//Y positions
var Title:float;
var ButtonPos1:float;
var ButtonPos2:float;
var ButtonPos3:float;


function Update(){
    //divides the screen in X parts , the initial pos is 1
	var initialPos:float=Screen.height/12; 
	
	//Buttons sizes
	sizeW=Screen.width/2;
	sizeH=Screen.height/16;
	
	
	//Title Position
	Title=initialPos*3;  //So I'll start from the third part of the screen (initial*thePartOfYouWant)
	
	//Buttons positions Y
	ButtonPos1=initialPos*4;
	ButtonPos2=initialPos*5;
	ButtonPos3=initialPos*6;
	
	//Center
	Center=sizeW/2;
}

function OnGUI(){
	GUI.Label (Rect (Center, Title, 50, 100), "Title");
	
//Buttons axes and size:		X		Y	  Width	 	Height
		if (GUI.Button(Rect(Center,ButtonPos1,sizeW,	sizeH),"Something 1")){}
		if (GUI.Button(Rect(Center,ButtonPos2,sizeW,	sizeH),"Something 2")){}
		if (GUI.Button(Rect(Center,ButtonPos3,sizeW,	sizeH),"Something 3")){}
}
