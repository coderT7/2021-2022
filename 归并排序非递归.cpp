#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<iostream>
using namespace std;
//void mergerSortNonR(int arr[],int n) {
//	int gap = 1;
//	int* tmp = new int[n];
//	while (gap < n) {
//		for (int i = 0; i < n; i += 2 * gap) {
//			int begin1 = i, end1 = i + gap - 1;
//			int begin2 = i + gap, end2 = i + 2 * gap - 1;
//			int index = begin1;
//			if (end1 >= n || begin2 >= n) {
//				break;
//			}
//			else if (end2 >= n) {
//				end2 = n - 1;
//			}
//			int nums = end2 - begin1 + 1;
//			while (begin1 <= end1 && begin2 <= end2) {
//				if (arr[begin1] < arr[begin2]) {
//					tmp[index++] = arr[begin1++];
//				}
//				else {
//					tmp[index++] = arr[begin2++];
//				}
//			}
//			while (begin1 <= end1){
//				tmp[index++] = arr[begin1++];
//			}
//			while (begin2 <= end2) {
//				tmp[index++] = arr[begin2++];
//			}
//			memcpy(arr+i, tmp+i, sizeof(int) * nums);
//		}
//		gap *= 2;
//	}
//}

void mergerSortNonR(int arr[],int n) {
	int gap = 1;
	int* tmp = new int[n];
	while (gap < n) {
		for (int i = 0; i < n; i += 2 * gap) {
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;
			int index = begin1;
			if (end1 >= n) {
				end1 = n - 1;
				//修正后续为一个不存在的区间
				begin2 = n;
				end2 = n - 1;
			}
			else if (begin2 >= n) {
				begin2 = n;
				end2 = n - 1;
			}
			else if(end2 >= n) {
				end2 = n - 1;
			}
			while (begin1 <= end1 && begin2 <= end2) {
				if (arr[begin1] < arr[begin2]) {
					tmp[index++] = arr[begin1++];
				}
				else {
					tmp[index++] = arr[begin2++];
				}
			}
			while (begin1 <= end1){
				tmp[index++] = arr[begin1++];
			}
			while (begin2 <= end2) {
				tmp[index++] = arr[begin2++];
			}
		}
		memcpy(arr, tmp, sizeof(int) * n);
		gap *= 2;
	}
}

//int main()
//{
//	int arr[] = { 6,1,2,5,4,7,3,0,8 };
//	mergerSortNonR(arr, sizeof(arr) / sizeof(int));
//	for (int val : arr) {
//		cout << val << " ";
//	}
//	return 0;
//}

