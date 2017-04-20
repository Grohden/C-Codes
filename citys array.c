#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

//DONE:exercise number 1 (show distances and the estimated time to travel between 2 citys)
//TODO:exercise number 2 (itinerary)
//DONE:exercise number 3 (show the array without repeating same travel)
//DONE:exercise number 4 (update distances)
//TODO:exercise number 5 (same as number 2, but with minimum travel distance)

//Vars
//this table is city distances. this seems to not work with 6x6, wich is the real size of the array.(maybe a '\0' version for int array?)
			 // 	A		B		C		D		E		F		G
int table[7][7]={ 	{0,		40,		35,		62,		14,		121,	145},	//A
					{40,	0,		12,		84,		25,		243,	98},	//B
					{35,	12,		0,		147, 	98,		153,	136},	//C
					{62,	84,		147,	0,		74,		256,	93},	//D
					{14,	25,		98,		74,		0,		117,	37},	//E
					{121,	243,	153,	256,	117,	0,		25},	//F
					{145,	98,		136,	93,		37,		25,		0}	 	//G
				};
bool DEBUG=true;

//Functions
int getAlphabetIndex(char letter); 						//This is for array acess, since we will be acessing the array with letters.
int distance(char first,char second);   				//This uses the function described above to give the distance between the citys.
int itinerary(char *itinerary);							//This give the time to travel from all citys on the string.
float estimatedTime(char first,char second);			//This uses distance() to return the estimated time for travel one city to another at 85 KM/H.
void showAllDistances(); 								//Show all distances one time.
void saveCity(char *city,char *toCity,int distance); 	//This Change a distance of a city to another.


//Code

void replaceDistance(char city,char toCity,int distance){
	int firstIndex	=getAlphabetIndex(city);
	int secondIndex	=getAlphabetIndex(toCity);
	if(DEBUG){printf("\n Changing distances of %c to %c, new distance: %i Km",city, toCity, table[secondIndex][firstIndex]=distance);}
	table[firstIndex][secondIndex]=distance;
	table[secondIndex][firstIndex]=distance;
}


//should return the index of the letter
int getAlphabetIndex(char letter){
	//Since strlwr/strupr recive a char[], i cant use that s**t to make some universal converter.
	
	if (letter>'A' && letter<'Z'){ //if we have upper characters
		return letter-'A';
	} else if (letter>'a' && letter<'z'){  //if we have lower characters
		return letter-'a';
	} else {
		return -1;
	}
}

int distance(char first, char second){
	int distance=table[getAlphabetIndex(first)][getAlphabetIndex(second)];
	if(DEBUG) printf("\nDistance between %c and %c: %d KM",first,second,distance);
	return distance;	
}

int itinerary(char * citys){
	int x;
	
	
	int time=0;
	int kms=0;
	
	for(x=0;x<strlen(citys)-1;x++){
		kms+=distance(citys[x],citys[x+1]);
		time+=estimatedTime(citys[x],citys[x+1]);
	}
	return time;
}

float estimatedTime(char first, char second){
			   	//Mins					KM/H
	float time= (60*(table[getAlphabetIndex(first)][getAlphabetIndex(second)])/85);
	if(DEBUG) printf("\nEstimated travel time: %.0f mins",time);
	return time;	//returning this, we have a problem with seconds convertion, wich i maybe i'll do later.
}

void showAllDistances(){
	int x=0;
	int y=0;
	int tab=0;
	int conter=0;
		
	int rows=(sizeof table/sizeof table[0])-1; //-1 coz we have +1 row and col
	int cols=rows;

	printf("\n \t \t \t Distances in km's");
	printf("\n\tA\tB\tC\tD\tE\tF\tG");
	
	for(x=0;x<=rows;x++){
		printf("\n %c\t",x+'A'); //To print the alphabet starting by A.  
		
		for(tab=conter;tab>0;tab--){printf("\t");} //To add the tabs in the print.
		
		for(y=conter;y<=cols;y++){ printf("%d\t",table[x][y]);} //to print the numbers without repeat.
		conter++;
	}


}

int main(int argc, char **argv){
	showAllDistances();
	return -0;
}
