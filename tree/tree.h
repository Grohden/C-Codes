
typedef struct TypeNode {
    int info;
    struct TypeNode *left;
    struct TypeNode *right;
} Node;


Node* initTree();