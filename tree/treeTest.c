#include "../utils.h"
#include "../random/random.c"
#include "tree.h"

void main(int argc, int argv[]){
    Node *root = initTree(25);

    int i = 50;
    while(i--){
        addValueToTree(root, i);
    }

    system("pause");
}