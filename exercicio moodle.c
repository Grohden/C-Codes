#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include<stdbool.h>

//Variables
int numero;
bool DEBUG=false; 		//This should be a constant, but i don't know how to declare one.TODO. (and i recomend you to use this to understend the code below..)

//Functions
void br(); 				//Break Line(i'm too lazy to write more than 4 chars just for that)
int getInverse(int);	//Get Inverse Number
int * splitInt(int);	//Split a int into int[]

/*seems that i need 2 recive a long long int(have problems with big numbers). TODO LATER;
  AND WE HAVE PROBLEM WITH ARRAY SIZE DECLARATION :DDDDDDD (we don't know(yet) how to declare a relative size from the function arg)
  have lucky fixing this sh*t my future me :D.
  Hours spend here:4.
  if u r tryin to understend this, well..good luck..
 */
 
void br(){printf("\n");}

int getInverse(int num){ 
	char inverse[51];
	char normal[51];
	int rev_cont=0;	 //reverse counter.
	itoa(num,normal,10);
	int x=strlen(normal);	
	for(x=strlen(normal)-1;x>=0;x--){
		inverse[rev_cont]=normal[x];
		rev_cont++;		
	}
	
	if(DEBUG) {printf("\nNormal : %d\nInverso: %s",num,inverse);}
	return atoi(inverse); 
}

int * splitInt(int num){
	int result[51];
	char splited[51];
	itoa(num,splited,10);
	int x;
	for(x=0;x<strlen(splited);x++){	
		int a=splited[x]-'0';	//do not try atoi, won't will work.
		result[x]=a;
	}	
	return result;
}

//HERE I'M USING WHAT WE CALL 'HUE BR WAY'.
int getDecimalSize(int num){ //need to find a better name for this function.
	int x=1;
	int counter=1;
	while(x<=num){
		x=x*10;
		counter++;
	}	
	if(DEBUG){printf("Size: %d\n",counter-1);}
	return counter-1;
}

int main(){
	printf("Digite os tres numeros da conta corrente: ");
	scanf("%d",&numero); //Um problema do scanf, o digito com 0 na frente é desconsiderado, não estou com saco pra fazer gets e depois converter pra int :v.TODO.
	
	int inverso=getInverse(numero); // ^ o que me da problema aqui.
	int soma=numero+inverso;
	if(DEBUG){printf("\nSoma:%d",soma);}
	
	//BELEZA, LINDO, O C NÃO RETORNA, NÃO É CAPAZ DE RETORNAR O TAMANHO DA LINHA ABAIXO. NÃO DA PRA RETORNAR SIZEOF(*ARRAY) :))))))))))))))), hue br way então.
	//int * splited=splitInt(soma); //não funciona :3
	int size=getDecimalSize(soma);
	int limit=size;
	int counter=0;
	int result=0;
	for(counter=0;counter<limit;counter++){
		//printf("\n%d+",splited[0]); WHY THIS DONT WORK?'----------------' WTF?
		printf("\n%d*%d=%d",splitInt(soma)[counter],size,splitInt(soma)[counter]*size);
		result+=splitInt(soma)[counter]*size;
		--size;
	}
	br();
	if(DEBUG){printf("%d result.",result);}
	br();
	int PORQUE_ESSA_BELEZINHA_NAO_FUNCIONA_DIRETO_NESSA_LINHA=getDecimalSize(result)-1;
	printf("Digito Verificador:%d",(splitInt(result)[PORQUE_ESSA_BELEZINHA_NAO_FUNCIONA_DIRETO_NESSA_LINHA])); //É SERIO, C TA ME ZOANDO.
	return -0;
	
}
