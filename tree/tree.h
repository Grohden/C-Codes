
typedef struct TypeNode {
    int info;
    struct TypeNode *left;
    struct TypeNode *right;
} Node;

void treeShowCentered(Node *root);
void treeShowPosFixed(Node *root);
void treeShowPreFixed(Node *root);

Node* initTree(int rootValue);

void addValueToTree(Node *root,int leafValue);