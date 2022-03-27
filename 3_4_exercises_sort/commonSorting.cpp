#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include<stack>
using namespace std;
//时间复杂度O(N^2)，即逆序为最坏的情况；有序的情况即为最好的情况，时间复杂度为O(N)
void insert_sort(int* arr, int n)
{
	//最后一次end如果走到n-1则end+1即为n，此时访问就造成了越界，所以end只能走到end-2，故i<n-1
	for (int i = 0; i < n - 1; i++)
	{
		//外层循环控制有序序列的长度
		int end = i;
		int tmp = arr[end + 1];
		//内层循环寻找tmp所放置的位置
		while (end >= 0)
		{
			if (tmp < arr[end])//升序
			{
				arr[end + 1] = arr[end];//大小不符合要求，则将end位置的值往后移
				end--;
			}
			else
				break;
		}
		arr[end + 1] = tmp;//插入到有序数组
	}
}
//希尔排序，对插入排序的优化：进行多组插入排序
//整体时间复杂度为O(N*logN)
void my_shell_sort(int* arr, int n)
{
	int gap = n;//gap与数组长度相关，则可更好的提高效率
	while (gap > 1)
	{
		//gap每次除2时循环进行log2N次
		gap /= 2;//每次都先将gap除2，最后gap一定会到1
		//gap很大时，预排序大概要交换O(N)次（因为gap很大，每次沉底的很快，一个数只用交换1-2次）
		//gap很小时，此时数组已经接近有序，预排序也大概要进行O(N)次
		
		//同时对多组进行预排序
		for (int i = 0; i < n - gap; i++)
		{
			//以下代码整体思路上即为直接插入排序
			int end = i;
			int tmp = arr[end + gap];
			while (end >= 0)
			{
				if (tmp < arr[end])
				{
					arr[end + gap] = arr[end];//end位置的值移动到end+gap的位置上
					end -= gap;//每次end移动gap个位置
				}
				else
					break;
			}
			arr[end + gap] = tmp;
		}
	}
}
//直接选择排序（最简单的排序）
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

//向下调整的时间复杂度为每层的结点个数*每个结点向下调整的次数=n-log(n+1)->故时间复杂度为O(N)
static void AdjustDown(int* arr, int n, int root)
{
	//建大堆
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		//找出左右孩子大的那一个与父亲进行比较
		if (child + 1 < n && arr[child + 1] > arr[child])
			child += 1;
		//建大堆，即堆顶比左右子树的每个节点的值都大
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
//整体的时间复杂度为O(N*logN)
void heap_sort(int* arr, int n)
{
	//从第一个非叶子结点开始进行调整
	//建堆时间复杂度为O(N)
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
		AdjustDown(arr, n, i);
	int end = n - 1;
	//选数的时间复杂度为O(logN)
	//向下调整算法最多调整高度次（logN次）
	while (end >= 0)
	{
		swap(arr[0], arr[end]);
		AdjustDown(arr, end, 0);
		end--;
	}
}
//冒泡排序
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
//快速排序（挖坑法）
//单次递归需要进行n次，理想情况下每次的分成左右两部分时都能二分，
//故一共要进行logN次递归，故时间复杂度为O(N*logN)
//最坏的情况下即数据是有序的情况，因为每次选的key值都排完后都只能排好一个数字，不能将整个区域均分成两部分
//此时时间时间复杂度为O(N^2)

//快速排序优化一：三数取中
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
//挖坑法
int part_sort_1(int* arr, int left, int right)
{
	//int index = get_mid_index(arr, left, right);
	//swap(arr[index], arr[left]);
	int begin = left, end = right;
	int pivot = begin;//左边先为坑
	int key = arr[begin];//并将区域内最左边的值作为key值
	while (begin < end)
	{
		//begin<end防止在找数字时end--直到end < begin了还没退出循环
		while (begin < end && arr[end] >= key)//先从右边开始找比key值小的
			end--;
		arr[pivot] = arr[end];//当右边找到比key值小的则填入左边的坑中
		pivot = end;//被填入的数值的原位置则变成坑

		while (begin < end && arr[begin] <= key)//再从左边开始找比key值大的
			begin++;
		arr[pivot] = arr[begin];//当左边找到比key值大的则填入右边的坑中
		pivot = begin;//被填入的数值的原位置则变成坑
	}
	pivot = begin;//最后begin和end相遇或相交的位置即为key值最后要填入的坑的位置
	arr[pivot] = key;//填入key值

	return pivot;
}
//左右指针法
int part_sort_2(int* arr, int left, int right)
{
	//int index = get_mid_index(arr, left, right);
	//swap(arr[index], arr[left]);

	int begin = left, end = right;
	int keyi = begin;
	while (begin < end)
	{
		//arr[keyi]<=arr[end]的等号如果不加可能会导致死循环
		//不加等号则导致两个值都相等，end和begin一直都不进行自增，那begin始终小于end，则死循环
		while (begin < end && arr[keyi] <= arr[end])
			end--;
		while (begin < end && arr[keyi] >= arr[begin])
			begin++;
		swap(arr[begin], arr[end]);//找到了大的值和小的值则进行交换
	}
	swap(arr[keyi], arr[begin]);
	return begin;
}
//前后指针法
int part_sort_3(int* arr, int left, int right)
{
	int index = get_mid_index(arr, left, right);
	swap(arr[index], arr[left]);

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

void my_quick_sort(int* arr, int left, int right)
{
	//当区间不存在时，即不需要再继续进行递归
	if (left > right)
		return;

	int keyIndex = part_sort_3(arr, left, right);

	//进行小区间优化
	if (keyIndex - 1 - left > 13)
		my_quick_sort(arr, left, keyIndex - 1);//递归左区间
	else//到一定小的范围则改用插入排序
		insert_sort(arr + left, keyIndex - 1 - left + 1);
	if (right - (keyIndex + 1) > 13)
		my_quick_sort(arr, keyIndex + 1, right);//递归右区间
	else
		insert_sort(arr + keyIndex + 1, right - (keyIndex + 1) + 1);
}
void quick_sort_nonR(int* arr, int n)
{
	stack<int> s;
	//将数组首尾坐标先入栈
	s.push(n - 1);
	s.push(0);
	while (!s.empty())
	{
		//栈不为空说明排序区间仍存在
		int left = s.top();
		s.pop();
		int right = s.top();
		s.pop();
		int keyIndex = part_sort_3(arr, left, right);//进行单趟快排
		if (keyIndex + 1 < right)//区间未分到最后，继续入栈
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
	int mid = (left + right) >> 1;//将数组区间一分为二
	_merge_sort(arr, left, mid, tmp);//递归进行左区间的分割
	_merge_sort(arr, mid + 1, right, tmp);//递归进行右区间的分割
	//进行归并
	int begin1 = left, end1 = mid;//左区间的起始下标
	int begin2 = mid + 1, end2 = right;//右区间的起始下标
	int index = left;//临时数组的下标
	while (begin1 <= end1 && begin2 <= end2)
	{
		//将小的那个值拷贝到临时数组中
		if (arr[begin1] < arr[begin2])
			tmp[index++] = arr[begin1++];
		else
			tmp[index++] = arr[begin2++];
	}
	//将未归并完毕的数组剩下的值拷贝到临时数组里
	while (begin1 <= end1)
		tmp[index++] = arr[begin1++];
	while (begin2 <= end2)
		tmp[index++] = arr[begin2++];
	//将临时数组的值拷贝到原数组中
	for (int i = left; i <= right; i++)
		arr[i] = tmp[i];
}
void merge_sort(int* arr, int n)
{
	//临时数组
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
			//归并过程中右半区间不存在即可退出本次循环
			if (begin2 >= n)
				break;
			//归并过程中右半区间的数据个数少于左半区间，则需修正右半区间的范围
			if (end2 >= n)
				end2 = n - 1;
			while (begin1 <= end1 && begin2 <= end2)
			{
				//将小的那个值拷贝到临时数组中
				if (arr[begin1] < arr[begin2])
					tmp[index++] = arr[begin1++];
				else
					tmp[index++] = arr[begin2++];
			}
			//将未归并完毕的数组剩下的值拷贝到临时数组里
			while (begin1 <= end1)
				tmp[index++] = arr[begin1++];
			while (begin2 <= end2)
				tmp[index++] = arr[begin2++];
			//归并一部分拷贝一部分，未归并的部分则不拷贝
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
	int range = max - min + 1;//max-min是两数之间相差的个数，如“[0-9]”0到9差9个数，但实际有十个数
	int* count = (int*)malloc(sizeof(int) * range);
	memset(count, 0, sizeof(int)*range);//初始化为0
	//进行计数
	for (int i = 0; i < n; i++)
		count[arr[i] - min]++;
	//进行排序
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