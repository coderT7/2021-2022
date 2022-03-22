#include <stdio.h>
#include <stdlib.h>
//��������(�Ӵ�С��
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
				int t = b[j];//��Ҫ������ͬʱ��Ӧ������ҲҪ����
				b[j] = b[j + 1];
				b[j + 1] = t;
			}
		}
	}
}

//�������򣨴�С����
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

//����ֵ��Сװ��
int GreedySelect1(int* w, int* v, int n, int c)
{
	//����ֵ����
	DownSort(v, w, n);
	int sum = 0;//������
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

//������װ
int GreedySelect2(int* w, int* v, int n, int c)
{
	//����������
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

//̰���㷨3������ֵ�������ı�ֵ����
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
	//�Ա�ֵ��������
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

//��ӡ�����
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
	int n = 4;//��Ʒ����
	int C = 50;//�����������
	int W[] = { 20,15,12,10 };//����Ʒ����
	int V[] = { 40,60,12,30 };//����Ʒ��ֵ

	//̰���㷨1����ֵ�ߵ��ȷ�
	int d=GreedySelect1(W, V, n, C);
	printf("����ֵ��Сװ��Ϊ��(��λ����ֵ��\n");
	PrintResult(V, d);

	//̰���㷨2����������ȷ�
	d = GreedySelect2(W, V, n, C);
	printf("��������Сװ��Ϊ��(��λ��������\n");
	PrintResult(W, d);

	//̰���㷨3������ֵ�ܶ�̰������
	d = GreedySelect3(W, V, n, C);
	printf("����ֵ�������ı�ֵװ��Ϊ��(��λ��������\n");
	PrintResult(W, d);

	return 0;
}