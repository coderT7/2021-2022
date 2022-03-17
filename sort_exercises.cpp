#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<algorithm>
#include<ctime>
#include<cstdlib>
using namespace std;

//ֱ�Ӳ�������
void insert_sort(int* arr, int n) {
	//nΪ�����䣬i���ֻ���ߵ�n-2��Ȼ����n-1��λ�õ�ֵ���н���
	for (int i = 0; i < n - 1; i++) {

		int end = i;
		int tmp = arr[end + 1];
		while (end >= 0) {
			if (arr[end] > tmp) {
				arr[end + 1] = arr[end];
				end--;
			}
			else
				break;
		}
		arr[end + 1] = tmp;
	}
}



//��������shell_sort)
void shell_sort(int* arr, int n) {
	int gap = n;
	//ÿ�γ�2��󶼻����0
	while (gap > 1) {
		gap /= 2;
		for (int i = 0; i < n - gap; i++) {
			int end = i;
			int tmp = arr[end + gap];
			while (end >= 0) {
				//��ǰend��ָ���������е����һ��Ԫ��
				if (arr[end] > tmp) {
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


//ֱ��ѡ������selete_sort)
void selete_sort(int* arr, int n) {
	
	int begin = 0; int end = n - 1;
	while (begin < end) {
		int maxi = begin, mini = begin;
		for (int i = begin; i <= end; i++) {
			if (arr[i] > arr[maxi]) {
				maxi = i;
			}
			if (arr[i] < arr[mini]) {
				mini = i;
			}
		}
		swap(arr[begin], arr[mini]);
		if (begin == maxi) {
			maxi = mini;
		}
		swap(arr[end], arr[maxi]);
		begin++;
		end--;
	}
}

static void AdjustDown(int* arr, int n, int root) {
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n) {
		//�Һ��Ӵ��ڲ�ȥѰ���Һ���
		if (child + 1 < n && arr[child + 1] > arr[child]) {
			child += 1;
		}
		if (arr[child] > arr[parent]) {
			swap(arr[child], arr[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}

//ѡ������heap_sort)
void heap_sort(int* arr, int n) {
	//���������ȼ���Ҫ����,�����µ����㷨�����ԣ���Ҫ�ӵ�����һ����Ҷ�ӽ�㿪ʼ���н���
	for (int i = (n - 1 - 1) / 2; i >= 0; i--) {
		AdjustDown(arr, n, i);
	}

	int end = n - 1;
	while (end >= 0) {
		swap(arr[0], arr[end]);
		AdjustDown(arr, end, 0);
		end--;
	}
}


//ð������(bullet_sort)
void bullet_sort(int* arr, int n) {
	for (int i = 0; i < n - 1; i++) {
		int flag = true;
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
				flag = false;
			}
		}
		if (flag) {
			break;
		}
	}
}

//�Ƚ�����quick_sort)
//ǰ��ָ�뷨
int part_sort_1(int* arr, int left, int right) {
	int cur = left;
	int next = left + 1;
	int keyi = left;
	while (next <= right) {
		if (arr[next] < arr[keyi] && ++cur != next) {
			swap(arr[cur], arr[next]);
		}
		next++;
	}
	swap(arr[cur], arr[keyi]);
	return cur;
}
//����ָ�뷨
int part_sort_2(int* arr, int left, int right) {
	int begin = left, end = right;
	int keyi = left;
	//begin��end������˵�����˿����Ѿ�����
	while (begin < end) {
		//�ȴ��ұ߿�ʼ��С���ٴ���߿�ʼ�Ҵ�˳�򽻻�����ɲ�������?��
		while (begin < end && arr[end] >= arr[keyi]) {
			end--;
		}
		while (begin < end && arr[begin] <= arr[keyi]) {
			begin++;
		}
		swap(arr[begin], arr[end]);
	}
	swap(arr[keyi], arr[begin]);
	return begin;
}
//�ڿӷ�
int part_sort_3(int* arr, int left, int right) {
	int begin = left, end = right;
	int pivot = left, keyi = left;
	while (begin < end) {
		while (begin < end && arr[end] >= arr[keyi]) {
			end--;
		}
		arr[pivot] = arr[end];
		pivot = end;
		while (begin < end && arr[begin] <= arr[keyi]) {
			begin++;
		}
		arr[pivot] = arr[begin];
		pivot = begin;
	}
	pivot = begin;
	arr[pivot] = arr[keyi];
	return pivot;
}
void quick_sort(int* arr, int left, int right) {
	if (left > right) {
		return;
	}
	int index = part_sort_3(arr, left, right);
	quick_sort(arr, left, index - 1);
	quick_sort(arr, index + 1, right);
}


static void _merge_sort(int* arr, int left, int right, int* tmp) {
	if (left >= right) {
		return;
	}
	//��������Ӧ��Ϊ[left,mid]��[mid+1,right]������Ϊ[left,mid-1]��[mid,right]�����ѭ��
	//��Ϊ����������ʱ���Ѿ�����ȥ����1������Ҫ��ǰ���ǰ�ָ�
	int mid = (left + right) >> 1;
	_merge_sort(arr, left, mid, tmp);
	_merge_sort(arr, mid + 1, right, tmp);

	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int index = left;
	while (begin1 <= end1 && begin2 <= end2) {
		if (arr[begin1] < arr[begin2]) {
			tmp[index++] = arr[begin1++];
		}
		else
			tmp[index++] = arr[begin2++];
	}
	while (begin1 <= end1) {
		tmp[index++] = arr[begin1++];
	}
	while (begin2 <= end2) {
		tmp[index++] = arr[begin2++];
	}
	for (int i = left; i <= right; i++) {
		arr[i] = tmp[i];
	}
}
void merge_sort(int* arr, int n) {
	int* tmp = (int*)malloc(sizeof(int) * n);
	_merge_sort(arr, 0, n - 1, tmp);
	free(tmp);
}

int main()
{
	srand((unsigned int)time(NULL));
	int arr[5] = { 0 };
	for (int i = 0; i < 5; i++) {
		arr[i] = rand() % 20;
	}
	merge_sort(arr, 5);
	for (int i = 0; i < 5; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}