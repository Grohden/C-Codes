#include "../utils.h"
#include "../random/random.h"
#include "../textualGUI/textualGUI.h"
#include "../chainedList/chainedList.h"
#include "tree.h"

void main(int argc, int argv[]){
    Node *root = initTree(getRandomNumber()/100);

    int i = 50;
    while(i--){
        addValueToTree(root, getRandomNumber()/100);
    }

    system("pause");
}