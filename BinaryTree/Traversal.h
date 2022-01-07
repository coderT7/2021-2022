#pragma once 

#include<stdlib.h>
#include<stdio.h>
#include<queue>
using namespace std;


typedef char BTDataType;

typedef struct BinaryTreeNode
{
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
    BTDataType val;
}BTNode;

void PrevOrder(BTNode *Tree);

void InOrder(BTNode *Tree);

void PostOrder(BTNode *Tree);

int TreeSize(BTNode *Tree);

int LeafSize(BTNode *Tree);

void LevelOrder(BTNode *Tree);

