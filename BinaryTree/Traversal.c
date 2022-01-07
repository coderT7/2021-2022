#include"Traversal.h"


void PrevOrder(BTNode *Tree)
{
   if(!Tree)
   {
       printf("NULL ");
       return ;
   }
   printf("%c ",Tree->val);
   PrevOrder(Tree->left);
   PrevOrder(Tree->right);
}


void InOrder(BTNode *Tree)
{
   if(!Tree)
   {
       printf("NULL ");
       return ;
   }
   InOrder(Tree->left);
   printf("%c ",Tree->val);
   InOrder(Tree->right);
}

void PostOrder(BTNode *Tree)
{

   if(!Tree)
   {
       printf("NULL ");
       return ;
   }
   PostOrder(Tree->left);
   PostOrder(Tree->right);
   printf("%c ",Tree->val);
}

int TreeSize(BTNode *Tree)
{
    return Tree == NULL ? 0 : TreeSize(Tree->left) + TreeSize(Tree->right) + 1;
}

int LeafSize(BTNode *Tree)
{
    if(!Tree)
        return 0;
    if(!Tree->left && !Tree->right)
        return 1;
    return LeafSize(Tree->left) +  LeafSize(Tree->right);
}


void LevelOrder(BTNode *Tree)
{
    if(!Tree)
        return ;
    queue<char> q;
    q.push(Tree->val);
    while(!q.empty())
    {
        char ch = q.front();
        printf("%c ",ch);
        q.pop();
        LevelOrder(Tree->left);
        LevelOrder(Tree->right);
    }
}
