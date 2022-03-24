#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<cassert>
#include<algorithm>
#include<ctime>
using namespace std;

void insert_sort(int* arr, int n) {
	assert(arr);
	//每次要排序的数都是在有序序列的后一个，如果i走到了n-1，则前n-1个数是有序序列，则要将后一个数（即n）插入该有序序列中
	//但因为其为开区间，所以当n是属于数组之外的空间，对其解引用则会造成内存访问越界
	for (int i = 0; i < n - 1; i++) {
		int end = i;
		int tmp = arr[end + 1];
		while (end >= 0) {
			if (tmp < arr[end]) {
				arr[end + 1] = arr[end];
				end--;
			}
			else
				break;
		}
		arr[end + 1] = tmp;
	}
}

void shell_sort(int* arr, int n) {
	int gap = n;
	while (gap > 0) {
		gap /= 2;
		for (int i = 0; i < n - gap; i++) {
			int end = i;
			int tmp = arr[end + gap];
			while (end >= 0) {
				if (tmp < arr[end]) {
					arr[end + gap] = arr[end];
					end -= gap;
				}
				else
					break;
			}
			arr[end + gap] = tmp;
		}
	}
}
int main()
{
	srand((unsigned int)time(NULL));
	int arr[10] = { 0 };
	for (int i = 0; i < 10; i++) {
		arr[i] = rand() % 20;
	}
	shell_sort(arr, 10);
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}