#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include<stdbool.h>

int numero;
bool DEBUG=false;

/*seems that i need 2 recive a long long int(have problems with conversion). TODO LATER;
  AND WE HAVE PROBLEM WITH ARRAY SIZE DECLARATION :DDDDDDD (we don't know(yet) how to declare a relative size from the function arg)
  have lucky fixing this sh*t my future me :D.
  Hours spend here:1.
 */
int getInverse(int num){ 
	char inverse[51];
	char normal[51];
	int rev_cont=0;	 //2 get inverse number by count.
	itoa(num,normal,10);
	int x=strlen(normal);
		
	for(x=strlen(normal)-1;x>=0;x--){
		inverse[rev_cont]=normal[x];
		if(DEBUG) {printf("\ninverse %c | normal  %c",inverse[rev_cont],normal[rev_cont]);}
		rev_cont++;		
	}
	if(DEBUG) {printf("\n%s",inverse);}
	return atoi(inverse); 
}

int * splitInt(int num){
	int result[51];
	char splited[51];
	itoa(num,splited,10);
	
	int x;
	for(x=0;x<strlen(splited);x++){
		result[x]=atoi(splited[x]);			
	}	
	
	return result;
}



int main(){
	printf("Digite os tres numeros da conta corrente: ");
	scanf("%d",&numero);
	printf("\nInverso: %d",getInverse(numero));
	int soma=numero+getInverse(numero);
	
}





	


