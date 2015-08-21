class Color{
    constructor(public RED:Number,public GREEN:Number,public BLUE:Number)
	{}
    
    public clarify = function(alpha:Number){
            return "rgba("+this.RED+","+this.GREEN+","+this.BLUE+","+alpha+")";
    }
	
	public colorfy= function(interval:Number,object){
		 var alpha=0.1;
		 setInterval(function(){
			 object.style.style.backgroundColor=Color.clarify(alpha)
			 },interval);
		 if(alpha>0.8){alpha=0.1};
		 alpha+=0.1;		
	}
	
}


    var color=new Color(10,20,30);
	color.colorfy(1000,document.body);

 
