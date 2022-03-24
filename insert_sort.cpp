#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<cassert>
#include<algorithm>
#include<ctime>
using namespace std;

void insert_sort(int* arr, int n) {
	assert(arr);
	//ÿ��Ҫ��������������������еĺ�һ�������i�ߵ���n-1����ǰn-1�������������У���Ҫ����һ��������n�����������������
	//����Ϊ��Ϊ�����䣬���Ե�n����������֮��Ŀռ䣬����������������ڴ����Խ��
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