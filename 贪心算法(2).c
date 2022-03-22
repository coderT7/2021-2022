#include <stdio.h>
#include <stdlib.h>
//降序排序(从大到小）
void DownSort(int* a, int* b, int n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < n - i-1; j++)
		{
			if (a[j] < a[j + 1])
			{
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
				int t = b[j];//按要求排序同时对应的重量也要排序
				b[j] = b[j + 1];
				b[j + 1] = t;
			}
		}
	}
}

//升序排序（从小到大）
void Sort(int* a, int* b, int n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < n - i-1; j++)
		{
			if (a[j] > a[j + 1])
			{
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
				tmp = b[j];
				b[j] = b[j + 1];
				b[j + 1] = tmp;
			}
		}
	}
}

//按价值大小装入
int GreedySelect1(int* w, int* v, int n, int c)
{
	//按价值排序
	DownSort(v, w, n);
	int sum = 0;//总重量
	int i = 0;
	for ( i = 0; i < n; i++)
	{
		if (sum < c)
		{
			sum = sum + w[i];
		}
	}
	return(i - 1);
}

//按重量装
int GreedySelect2(int* w, int* v, int n, int c)
{
	//按重量排序
	Sort(w, v, n);
	int i = 0;
	int sum = 0;
	for (i = 0; i < n; i++)
	{
		if (sum < c)
		{
			sum = sum + w[i];
		}
	}
	return (i - 1);
}

//贪心算法3：按价值和重量的比值降序
int GreedySelect3(int* w, int* v, int n, int c)
{
	int* y = NULL;
	if (n > 0) {
		y = (int*)malloc(sizeof(int) * n);
	}
	if (y == NULL)
	{
		printf("fail!\n");
		exit(-1);
	}
	int i = 0;
	for (i = 0; i < n; i++)
	{
		y[i] = (int)(v[i] / w[i]);
	}
	//对比值降序排列
	DownSort(y, w, n);
	int sum = 0;
	for (i = 0; i < n; i++)
	{
		if (sum < c)
		{
			sum = sum + w[i];
		}
	}
	free(y);
	y = NULL;
	return (i - 1);
}

//打印结果：
void PrintResult(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main()
{
	int n = 4;//物品个数
	int C = 50;//背包最大容量
	int W[] = { 20,15,12,10 };//各物品重量
	int V[] = { 40,60,12,30 };//各物品价值

	//贪心算法1：价值高的先放
	int d=GreedySelect1(W, V, n, C);
	printf("按价值大小装入为：(单位：价值）\n");
	PrintResult(V, d);

	//贪心算法2：重量轻的先放
	d = GreedySelect2(W, V, n, C);
	printf("按重量大小装入为：(单位：重量）\n");
	PrintResult(W, d);

	//贪心算法3：（价值密度贪婪法）
	d = GreedySelect3(W, V, n, C);
	printf("按价值与重量的比值装入为：(单位：重量）\n");
	PrintResult(W, d);

	return 0;
}