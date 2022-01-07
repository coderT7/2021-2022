#include"Traversal.h"


int main()
{
    BTNode *A = (BTNode*)malloc(sizeof(BTNode));
    A->left = NULL;
    A->right = NULL;
    A->val = 'A';
    
    BTNode *B = (BTNode*)malloc(sizeof(BTNode));
    B->left = NULL;
    B->right = NULL;
    B->val = 'B';
   
    BTNode *C = (BTNode*)malloc(sizeof(BTNode));
    C->left = NULL;
    C->right = NULL;
    C->val = 'C';
    
    BTNode *D = (BTNode*)malloc(sizeof(BTNode));
    D->left = NULL;
    D->right = NULL;
    D->val = 'D';
    
    BTNode *E = (BTNode*)malloc(sizeof(BTNode));
    E->left = NULL;
    E->right = NULL;
    E->val = 'E';
    
    BTNode *F = (BTNode*)malloc(sizeof(BTNode));
    F->left = NULL;
    F->right = NULL;
    F->val = 'F';

    A->left = B;
    A->right = C;
    B->left = D;
    B->right = E;
    E->right = F;
    PrevOrder(A);
    printf("\n");
    InOrder(A);
    printf("\n");
    PostOrder(A);
    printf("\n");
    LevelOrder(A);
    printf("\n");
    printf("TreeSize:%d\n",TreeSize(A));
    printf("LeafSize:%d\n",LeafSize(A));
    return 0;
}
