#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "tree.h"
#include "../../utils/utils.h"

void treeShowCentered(Node *root){
      if (root != NULL){
            treeShowCentered(root->left);
            printf(" %d ",root->info);
            treeShowCentered(root->right);
      }
}

void treeShowPosFixed(Node *root){
      if (root != NULL){
            treeShowPosFixed(root->left);
            treeShowPosFixed(root->right);
            printf(" %d ",root->info);
      }
}

void treeShowPreFixed(Node *root){
      if (root != NULL){
            printf(" %d ",root->info);
            treeShowPreFixed(root->left);
            treeShowPreFixed(root->right);
      }
}

Node* initTree(int rootValue){
	Node *root = calloc(1,sizeof(Node));
	root->info = rootValue;
	root->left = NULL;
  root->right = NULL;
  return root;
}

Node* initLeaf(int value){
	Node *leaf = calloc(1,sizeof(Node));
	leaf->info = value;
	leaf->left = NULL;
	leaf->right = NULL;
  return leaf;
}

void addValueToTree(Node *root,int leafValue){
	
	//No que tera o current da procura
	Node *leaf = root;

	//No raiz no fim dos loops
	Node *previousNode;

	while(1){
		previousNode = leaf;
		if(leafValue > leaf->info){
			leaf = leaf->right;
		} else if(leafValue < leaf->info) {
			leaf = leaf->left;
		} else {
			// Valor ja presente na arvore
			return;
		}

		if(leaf == NULL){
			break;
		}
	}

	//Inicia uma folha
	Node *addedLeaf = initLeaf(leafValue);

	if(leafValue > previousNode->info){
		previousNode->right = addedLeaf;
	} else {
		previousNode->left = addedLeaf;
	}
}