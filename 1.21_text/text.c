#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"
//void swap(int* a, int* b)
//{
//	int tmp = *a; *a = *b; *b = tmp;
//}
//
//void bullet_sort(int* arr, int len)
//{
//	for (int i = 0; i < len - 1; i++)
//	{
//		int flag = 1;
//		for (int j = 0; j < len - i - 1; j++)
//		{
//			if (arr[j] < arr[j + 1])
//			{
//				swap(&arr[j], &arr[j + 1]);
//				flag = 0;
//			}
//		}
//		if (flag) break;
//	}
//}
//void init(int* arr, int len)
//{
//	for (int i = 0; i < len; i++)
//		arr[i] = rand() % 100;
//}
//void print(int* arr, int len)
//{
//	for (int i = 0; i < len; i++)
//		printf("%d ", arr[i]);
//	printf("\n");
//}
//void reverse(int* arr, int len)
//{
//	int left = 0; int right = len - 1;
//	while (left < right)
//	{
//		int tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//		left++;
//		right--;
//	}
//}
//void arr_swap(int* arr1, int* arr2, int len)
//{
//	for (int i = 0; i < len; i++)
//	{
//		int tmp = arr1[i];
//		arr1[i] = arr2[i];
//		arr2[i] = tmp;
//	}
//}
//int main()
//{
//	srand((unsigned int)time(NULL));
//	int arr1[10] = { 0 };
//	int arr2[10] = { 0 };
//	int len = sizeof(arr1) / sizeof(int);
//	init(arr1, len); print(arr1, len);
//	init(arr2, len); print(arr2, len);
//	arr_swap(arr1, arr2, len);
//	printf("交换后：\n");
//	print(arr1, len); print(arr2, len);
//	//bullet_sort(arr, len);
//	//print(arr, len);
//	//reverse(arr,len);
//	//init(arr, len);
//	return 0;
//}

int main()
{
	srand((unsigned int)time(NULL));
	int choose = 0;
	do
	{
		system("cls");
		menu();
		scanf("%d", &choose);
		switch (choose)
		{
		case PLAY:
			game();
			system("pause");
			break;
		case EXIT:
			printf("祝您生活愉快！\n");
			break;
		}
	} while (choose);
	return 0;
}


