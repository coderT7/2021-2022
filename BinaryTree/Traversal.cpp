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
    queue<BTNode*> q;
    //先将根节点入队列，为后续层序遍历埋下“种子”
    if(Tree)
        q.push(Tree);
    //队列不为空则不断的取数据和入数据
    while(!q.empty())
    {
        BTNode *front = q.front();
        q.pop();
        printf("%c ",front->val);
        //根节点的左子树不为空则将其入队列
        if(front->left)
            q.push(front->left);
        //右子树不为空则将其入队列
        if(front->right)
            q.push(front->right);
    }
}
