#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include<stack>
using namespace std;
//ʱ�临�Ӷ�O(N^2)��������Ϊ������������������Ϊ��õ������ʱ�临�Ӷ�ΪO(N)
void insert_sort(int* arr, int n)
{
	//���һ��end����ߵ�n-1��end+1��Ϊn����ʱ���ʾ������Խ�磬����endֻ���ߵ�end-2����i<n-1
	for (int i = 0; i < n - 1; i++)
	{
		//���ѭ�������������еĳ���
		int end = i;
		int tmp = arr[end + 1];
		//�ڲ�ѭ��Ѱ��tmp�����õ�λ��
		while (end >= 0)
		{
			if (tmp < arr[end])//����
			{
				arr[end + 1] = arr[end];//��С������Ҫ����endλ�õ�ֵ������
				end--;
			}
			else
				break;
		}
		arr[end + 1] = tmp;//���뵽��������
	}
}
//ϣ�����򣬶Բ���������Ż������ж����������
//����ʱ�临�Ӷ�ΪO(N*logN)
void my_shell_sort(int* arr, int n)
{
	int gap = n;//gap�����鳤����أ���ɸ��õ����Ч��
	while (gap > 1)
	{
		//gapÿ�γ�2ʱѭ������log2N��
		gap /= 2;//ÿ�ζ��Ƚ�gap��2�����gapһ���ᵽ1
		//gap�ܴ�ʱ��Ԥ������Ҫ����O(N)�Σ���Ϊgap�ܴ�ÿ�γ��׵ĺܿ죬һ����ֻ�ý���1-2�Σ�
		//gap��Сʱ����ʱ�����Ѿ��ӽ�����Ԥ����Ҳ���Ҫ����O(N)��
		
		//ͬʱ�Զ������Ԥ����
		for (int i = 0; i < n - gap; i++)
		{
			//���´�������˼·�ϼ�Ϊֱ�Ӳ�������
			int end = i;
			int tmp = arr[end + gap];
			while (end >= 0)
			{
				if (tmp < arr[end])
				{
					arr[end + gap] = arr[end];//endλ�õ�ֵ�ƶ���end+gap��λ����
					end -= gap;//ÿ��end�ƶ�gap��λ��
				}
				else
					break;
			}
			arr[end + gap] = tmp;
		}
	}
}
//ֱ��ѡ��������򵥵�����
void select_sort(int* arr, int n)
{
	int begin = 0, end = n - 1;
	while (begin < end)
	{
		int maxi = begin, mini = begin;
		//����һ�����������ֵ����Сֵ���±�
		for (int i = begin; i <= end; i++)
		{
			if (arr[maxi] < arr[i])
				maxi = i;
			if (arr[mini] > arr[i])
				mini = i;
		}
		//�����ֵ�ŵ�����ߣ���Сֵ�ŵ����ұ�
		swap(arr[begin], arr[mini]);
		//������ֵ���±���begin�ص����������ֵ���±��ϵ�������Сֵ��������е���
		if (maxi == begin)
			maxi = mini;
		swap(arr[maxi], arr[end]);
		begin++;
		end--;
	}
}

//���µ�����ʱ�临�Ӷ�Ϊÿ��Ľ�����*ÿ��������µ����Ĵ���=n-log(n+1)->��ʱ�临�Ӷ�ΪO(N)
static void AdjustDown(int* arr, int n, int root)
{
	//�����
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		//�ҳ����Һ��Ӵ����һ���븸�׽��бȽ�
		if (child + 1 < n && arr[child + 1] > arr[child])
			child += 1;
		//����ѣ����Ѷ�������������ÿ���ڵ��ֵ����
		if (arr[parent] < arr[child])
		{
			swap(arr[parent], arr[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}
//�����ʱ�临�Ӷ�ΪO(N*logN)
void heap_sort(int* arr, int n)
{
	//�ӵ�һ����Ҷ�ӽ�㿪ʼ���е���
	//����ʱ�临�Ӷ�ΪO(N)
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
		AdjustDown(arr, n, i);
	int end = n - 1;
	//ѡ����ʱ�临�Ӷ�ΪO(logN)
	//���µ����㷨�������߶ȴΣ�logN�Σ�
	while (end >= 0)
	{
		swap(arr[0], arr[end]);
		AdjustDown(arr, end, 0);
		end--;
	}
}
//ð������
void bullet_sort(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		int flag = 1;
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
				flag = 0;
			}
		}
		if (flag)
			break;
	}
}
//���������ڿӷ���
//���εݹ���Ҫ����n�Σ����������ÿ�εķֳ�����������ʱ���ܶ��֣�
//��һ��Ҫ����logN�εݹ飬��ʱ�临�Ӷ�ΪO(N*logN)
//�������¼�������������������Ϊÿ��ѡ��keyֵ�������ֻ���ź�һ�����֣����ܽ�����������ֳ�������
//��ʱʱ��ʱ�临�Ӷ�ΪO(N^2)

//���������Ż�һ������ȡ��
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
//�ڿӷ�
int part_sort_1(int* arr, int left, int right)
{
	//int index = get_mid_index(arr, left, right);
	//swap(arr[index], arr[left]);
	int begin = left, end = right;
	int pivot = begin;//�����Ϊ��
	int key = arr[begin];//��������������ߵ�ֵ��Ϊkeyֵ
	while (begin < end)
	{
		//begin<end��ֹ��������ʱend--ֱ��end < begin�˻�û�˳�ѭ��
		while (begin < end && arr[end] >= key)//�ȴ��ұ߿�ʼ�ұ�keyֵС��
			end--;
		arr[pivot] = arr[end];//���ұ��ҵ���keyֵС����������ߵĿ���
		pivot = end;//���������ֵ��ԭλ�����ɿ�

		while (begin < end && arr[begin] <= key)//�ٴ���߿�ʼ�ұ�keyֵ���
			begin++;
		arr[pivot] = arr[begin];//������ҵ���keyֵ����������ұߵĿ���
		pivot = begin;//���������ֵ��ԭλ�����ɿ�
	}
	pivot = begin;//���begin��end�������ཻ��λ�ü�Ϊkeyֵ���Ҫ����Ŀӵ�λ��
	arr[pivot] = key;//����keyֵ

	return pivot;
}
//����ָ�뷨
int part_sort_2(int* arr, int left, int right)
{
	//int index = get_mid_index(arr, left, right);
	//swap(arr[index], arr[left]);

	int begin = left, end = right;
	int keyi = begin;
	while (begin < end)
	{
		//arr[keyi]<=arr[end]�ĵȺ�������ӿ��ܻᵼ����ѭ��
		//���ӵȺ���������ֵ����ȣ�end��beginһֱ����������������beginʼ��С��end������ѭ��
		while (begin < end && arr[keyi] <= arr[end])
			end--;
		while (begin < end && arr[keyi] >= arr[begin])
			begin++;
		swap(arr[begin], arr[end]);//�ҵ��˴��ֵ��С��ֵ����н���
	}
	swap(arr[keyi], arr[begin]);
	return begin;
}
//ǰ��ָ�뷨
int part_sort_3(int* arr, int left, int right)
{
	int index = get_mid_index(arr, left, right);
	swap(arr[index], arr[left]);

	int cur = left + 1, prev = left;
	int keyi = left;
	while (cur <= right)
	{
		//++prev��cur���ʱ�����൱���Լ����Լ�������û�����壬�ʼ��ϸ�����
		if (arr[cur] < arr[keyi] && ++prev != cur)
			swap(arr[prev], arr[cur]);
		cur++;
	}
	swap(arr[prev], arr[keyi]);
	return prev;
}

void my_quick_sort(int* arr, int left, int right)
{
	//�����䲻����ʱ��������Ҫ�ټ������еݹ�
	if (left > right)
		return;

	int keyIndex = part_sort_3(arr, left, right);

	//����С�����Ż�
	if (keyIndex - 1 - left > 13)
		my_quick_sort(arr, left, keyIndex - 1);//�ݹ�������
	else//��һ��С�ķ�Χ����ò�������
		insert_sort(arr + left, keyIndex - 1 - left + 1);
	if (right - (keyIndex + 1) > 13)
		my_quick_sort(arr, keyIndex + 1, right);//�ݹ�������
	else
		insert_sort(arr + keyIndex + 1, right - (keyIndex + 1) + 1);
}
void quick_sort_nonR(int* arr, int n)
{
	stack<int> s;
	//��������β��������ջ
	s.push(n - 1);
	s.push(0);
	while (!s.empty())
	{
		//ջ��Ϊ��˵�����������Դ���
		int left = s.top();
		s.pop();
		int right = s.top();
		s.pop();
		int keyIndex = part_sort_3(arr, left, right);//���е��˿���
		if (keyIndex + 1 < right)//����δ�ֵ���󣬼�����ջ
		{
			s.push(right);
			s.push(keyIndex + 1);
		}
		if (left < keyIndex - 1)
		{
			s.push(keyIndex - 1);
			s.push(left);
		}
	}
}
static void _merge_sort(int* arr, int left, int right, int* tmp)
{
	if (left >= right)
		return;
	int mid = (left + right) >> 1;//����������һ��Ϊ��
	_merge_sort(arr, left, mid, tmp);//�ݹ����������ķָ�
	_merge_sort(arr, mid + 1, right, tmp);//�ݹ����������ķָ�
	//���й鲢
	int begin1 = left, end1 = mid;//���������ʼ�±�
	int begin2 = mid + 1, end2 = right;//���������ʼ�±�
	int index = left;//��ʱ������±�
	while (begin1 <= end1 && begin2 <= end2)
	{
		//��С���Ǹ�ֵ��������ʱ������
		if (arr[begin1] < arr[begin2])
			tmp[index++] = arr[begin1++];
		else
			tmp[index++] = arr[begin2++];
	}
	//��δ�鲢��ϵ�����ʣ�µ�ֵ��������ʱ������
	while (begin1 <= end1)
		tmp[index++] = arr[begin1++];
	while (begin2 <= end2)
		tmp[index++] = arr[begin2++];
	//����ʱ�����ֵ������ԭ������
	for (int i = left; i <= right; i++)
		arr[i] = tmp[i];
}
void merge_sort(int* arr, int n)
{
	//��ʱ����
	int* tmp = (int*)malloc(sizeof(int) * n);
	_merge_sort(arr, 0, n - 1, tmp);
	free(tmp);
}
void merge_sort_nonR(int* arr, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	int gap = 1;
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;
			int index = i;
			//�鲢�������Ұ����䲻���ڼ����˳�����ѭ��
			if (begin2 >= n)
				break;
			//�鲢�������Ұ���������ݸ�������������䣬���������Ұ�����ķ�Χ
			if (end2 >= n)
				end2 = n - 1;
			while (begin1 <= end1 && begin2 <= end2)
			{
				//��С���Ǹ�ֵ��������ʱ������
				if (arr[begin1] < arr[begin2])
					tmp[index++] = arr[begin1++];
				else
					tmp[index++] = arr[begin2++];
			}
			//��δ�鲢��ϵ�����ʣ�µ�ֵ��������ʱ������
			while (begin1 <= end1)
				tmp[index++] = arr[begin1++];
			while (begin2 <= end2)
				tmp[index++] = arr[begin2++];
			//�鲢һ���ֿ���һ���֣�δ�鲢�Ĳ����򲻿���
			for (int j = i; j <= end2; j++)
				arr[j] = tmp[j];
		}
		gap *= 2;

	}
}

void count_sort(int* arr, int n)
{
	int max = arr[0], min = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (max < arr[i])
			max = arr[i];
		if (min > arr[i])
			min = arr[i];
	}
	int range = max - min + 1;//max-min������֮�����ĸ������硰[0-9]��0��9��9��������ʵ����ʮ����
	int* count = (int*)malloc(sizeof(int) * range);
	memset(count, 0, sizeof(int)*range);//��ʼ��Ϊ0
	//���м���
	for (int i = 0; i < n; i++)
		count[arr[i] - min]++;
	//��������
	int j = 0;
	for (int i = 0; i < range; i++)
	{
		while (count[i]--)
			arr[j++] = i + min;
	}
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
	int begin4 = clock();
	heap_sort(a2, N);
	int end4 = clock();
	int begin5 = clock();
	my_quick_sort(a2, 0, N-1);
	int end5 = clock();
	//int begin6 = clock();
	//merge_sort_nonR(a6, N);
	//int end6 = clock();
	printf("select_sort:%d\n", end1 - begin1);
	//printf("ShellSort:%d\n", end2 - begin2);
	//printf("quick_sort_nonR:%d\n", end3 - begin3);
	printf("HeapSort:%d\n", end4 - begin4);
	printf("my_quick_sort:%d\n", end5 - begin5);
	//printf("merge_sort_nonR:%d\n", end6 - begin6);
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
	//int arr[11] = { 0 };
	//for (int i = 0; i < 11; i++) {
	//	arr[i] = i;
	//}
	//my_quick_sort(arr, 0, 10);
	//for (int i = 0; i < 11; i++) {
	//	cout << arr[i] << " ";
	//}
	return 0;
}