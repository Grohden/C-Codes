#include "../utils.h"
#include "../SO/specifics.h"
#include "../textualGUI/textualGUI.h"
#include "../chainedList/chainedList.h"
#include "tree.h"

ChainedList *mainMenuChain = NULL;
Node *root;

void menu(){
    //First we need to set screen size
	setScreenSize(50 * 2, 40);

    //We init the chained list
    if (mainMenuChain == NULL)
    {

        mainMenuChain = initChain();
        
        int rootValue;
        printf("Digite o numero da raiz: ");
	    scanf("%d", &rootValue);
        root = initTree(rootValue);


        //Add the items
        addToChain(mainMenuChain, (void *)"Adicionar numero");
        addToChain(mainMenuChain, (void *)"Ver caminhamento central");
        addToChain(mainMenuChain, (void *)"Ver caminhamento pos-fixado");
        addToChain(mainMenuChain, (void *)"Ver caminhamento pre-fixado");
        addToChain(mainMenuChain, (void *)"Sair");
    }

    //Draw the seletable list and wait for the response
    int selected = drawSelectableList(mainMenuChain, true);
    int newValue;

    switch (selected){
        case 0:
           
            printf("Digite o numero : ");
            scanf("%d", &newValue);
            addValueToTree(root,newValue);
            break;
        case 1:
            treeShowCentered(root);
            pause();
            break;
        case 2:
            treeShowPosFixed(root);
            pause();    
            break;
        case 3:
            treeShowPreFixed(root);
            pause();        
            break;
        case 4:
            return;
    }

    printf("\n");
    menu();
}

void main(int argc, int argv[])
{
    menu();
}