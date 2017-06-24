#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "tree.h"
#include "../utils.h"
#include "../SO/specifics.h"
#include "../random/random.h"

Node* initTree(){
	Node *root = calloc(1,sizeof(Node));
	root->left = NULL;
	root->right = NULL;
}