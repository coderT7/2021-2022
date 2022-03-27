#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include<stack>
using namespace std;
void select_sort(int* arr, int n)
{
	int begin = 0, end = n - 1;
	while (begin < end)
	{
		int maxi = begin, mini = begin;
		//遍历一遍数组找最大值和最小值的下标
		for (int i = begin; i <= end; i++)
		{
			if (arr[maxi] < arr[i])
				maxi = i;
			if (arr[mini] > arr[i])
				mini = i;
		}
		//将最大值放到最左边，最小值放到最右边
		swap(arr[begin], arr[mini]);
		//如果最大值的下标与begin重叠则会造成最大值的下标上的数是最小值，故需进行调整
		if (maxi == begin)
			maxi = mini;
		swap(arr[maxi], arr[end]);
		begin++;
		end--;
	}
}
static int get_mid_index(int* arr, int left, int right)
{
	int mid = (left + right) >> 1;
	if (arr[left] < arr[mid])
	{
		if (arr[mid] < arr[right])
			return mid;
		else if (arr[left] > arr[right])
			return left;
		else
			return right;
	}
	else//left > mid
	{
		if (arr[mid] > arr[right])
			return mid;
		else if (arr[left] < arr[right])
			return left;
		else
			return right;
	}
}

//前后指针法
int part_sort_3(int* arr, int left, int right)
{
	int index = get_mid_index(arr, left, right);
	//swap(arr[index], arr[left]);

	int cur = left + 1, prev = left;
	int keyi = left;
	while (cur <= right)
	{
		//++prev与cur相等时，就相当于自己与自己交换，没有意义，故加上该条件
		if (arr[cur] < arr[keyi] && ++prev != cur)
			swap(arr[prev], arr[cur]);
		cur++;
	}
	swap(arr[prev], arr[keyi]);
	return prev;
}

void quick_sort(int* arr, int left, int right)
{
	//当区间不存在时，即不需要再继续进行递归
	if (left > right)
		return;

	int keyIndex = part_sort_3(arr, left, right);
	quick_sort(arr, left, keyIndex - 1);
	quick_sort(arr, keyIndex + 1, right);
	
}
void TestOP()
{
	srand((unsigned int)time(NULL));
	const int N = 100000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	int* a3 = (int*)malloc(sizeof(int) * N);
	int* a4 = (int*)malloc(sizeof(int) * N);
	int* a5 = (int*)malloc(sizeof(int) * N);
	int* a6 = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; ++i)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
	}
	int begin1 = clock();
	select_sort(a1, N);
	int end1 = clock();
	//int begin2 = clock();
	//my_shell_sort(a2, N);
	//int end2 = clock();
	//int begin3 = clock();
	//quick_sort_nonR(a3, N);
	//int end3 = clock();
	//int begin4 = clock();
	//heap_sort(a4, N);
	//int end4 = clock();
	int begin5 = clock();
	quick_sort(a1, 0, N - 1);
	int end5 = clock();
	//int begin6 = clock();
	//merge_sort_nonR(a6, N);
	//int end6 = clock();
	printf("InsertSort:%d\n", end1 - begin1);
	//printf("ShellSort:%d\n", end2 - begin2);
	//printf("SelectSort:%d\n", end3 - begin3);
	//printf("HeapSort:%d\n", end4 - begin4);
	printf("quick_sort:%d\n", end5 - begin5);
	//printf("MergeSort:%d\n", end6 - begin6);
	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
}
int main()
{
	TestOP();
	return 0;
}