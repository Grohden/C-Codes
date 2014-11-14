private int[] convertStringToInt(String[] arrayString){
			int[] ArrayInt=new int[arrayString.length];
			try{
				for (int x=0;x!=arrayString.length;x++){	ArrayInt[x]=Integer.parseInt(arrayString[x]);}
				} catch(NumberFormatException exeption){
					Toast.makeText(getApplicationContext(), exeption.getLocalizedMessage()+" isnt a number", Toast.LENGTH_LONG).show();
					};
				return ArrayInt;
