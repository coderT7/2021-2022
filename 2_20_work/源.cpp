#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#include<stdio.h>
#include<string.h>

int my_strlen(char* arr)
{
	int count = 0;
	int index = 0;
	while (arr[index++])
		count++;
	return count;
}
void my_strcpy(char* arr1, char* arr2)
{
	int index1 = 0, index2 = 0;
	while (arr1[index1])
		index1++;
	while (arr2[index2])
		arr1[index1++] = arr2[index2++];
}
int main()
{
	char arr1[100] = { 0 };
	char arr2[100] = { 0 };
	scanf("%s%s", arr1,arr2);
	int len = my_strlen(arr1);
	cout << len << endl;
	my_strcpy(arr1, arr2);
	cout << arr1;
	return 0;
}