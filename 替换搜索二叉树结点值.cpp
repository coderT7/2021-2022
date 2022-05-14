#define _CRT_SECURE_NO_WARNINGS 1
#if 0
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct student
{
    long int classr; int num;
    char name[30];
    char sex[10];
    char native[10];
    char academic[20];
    char major[20];
    int age;
    struct student* next;
};

struct student* creat(FILE* fp);
struct student* insert(struct student* phead, FILE* fp);

void nspnt(struct student* phead);

int main()
{

    struct student* phead = NULL;
    FILE* fp;
    fp = fopen("student.txt", "r");
    phead = creat(fp);

    phead = insert(phead, fp);
    nspnt(phead);
    return 0;
}
struct student* creat(FILE* fp)
{
    struct student* phead;
    phead = (struct student*)malloc(sizeof(struct student));
    if (phead == NULL)
        return NULL;
    int i = fscanf(fp, "%d %s %s %d %s %s %s %ld", &phead->num, phead->name, phead->sex, &phead->age, &phead->native, &phead->academic, &phead->major, &phead->classr);
    phead->next = NULL;
    return phead;
}
struct student* insert(struct student* phead, FILE* fp)
{
    struct student* node = NULL, * end = NULL;
    end = phead;
    if (end == NULL)
        return NULL;
    while (!feof(fp))
    {
        node = (struct student*)malloc(sizeof(struct student));
        if (node == NULL)
            return NULL;
        int i = fscanf(fp, "%d %s %s %d %s %s %s %ld", &node->num, node->name, node->sex, &node->age, node->native, node->academic, &node->major, &node->classr);
        end->next = node;
        end = node;
    }
    end->next = NULL;
    return phead;
};

void nspnt(struct student* phead)
{
    if (phead == NULL)
    {
        printf("error!");
        return;
    }
    else
    {
        while (phead != NULL)
        {
            printf("%d %s %s %d %s %s %s %ld\n", phead->num, phead->name, phead->sex, phead->age, phead->native, phead->academic, phead->major, phead->classr);
            phead = phead->next;
        }
    }
}
#endif
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    
};
class Solution {
public:
    int sum = 0;

    TreeNode* convertBST(TreeNode* root) {
        if (root != nullptr) {
            convertBST(root->right);
            sum += root->val;
            root->val = sum;
            convertBST(root->left);
        }
        return root;
    }
};

