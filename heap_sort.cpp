#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<ctime>
#include<algorithm>
using namespace std;

void AdjustDown(int* arr, int n, int root) {
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n) {
		if (child + 1 < n && arr[child] < arr[child + 1]) {
			child += 1;
		}
		if (arr[child] > arr[parent]) {
			swap(arr[child], arr[parent]);
		}
		else
			break;
		parent = child;
		child = parent * 2 + 1;
	}
}

void heap_sort(int* arr, int n) {
	
	for (int i = (n - 1 - 1) / 2; i >= 0; i--) {
		AdjustDown(arr, n, 0);
	}
	int end = n - 1;
	while (end >= 0) {
		swap(arr[0], arr[end]);
		AdjustDown(arr, end, 0);
		end--;
	}

}

int main()
{
	srand((unsigned int)time(NULL));
	int arr[10] = { 0 };
	for (int i = 0; i < 10; i++) {
		arr[i] = rand() % 20;
	}
	int n = sizeof(arr) / sizeof(arr[0]);
	heap_sort(arr, n);
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}