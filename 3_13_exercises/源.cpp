#define _CRT_SECURE_NO_WARNINGS 1



#include<stdio.h>
#include<stdlib.h>
//void reverse(string& str, int start, int end)
//{
//    while (start < end) {
//        swap(str[start], str[end]);
//        start += 1;
//        end -= 1;
//    }
//}
//bool is_left_rotate(string str1, string str2)
//{
//    int k = 1;
//    if (str1.size() != str2.size())
//        return false;
//    for (int i = 0; i < str1.size(); i++)
//    {
//        reverse(str1, 0, str1.size() - 1);
//        reverse(str1, 0, str1.size() - k - 1);
//        reverse(str1, str1.size() - k, str1.size() - 1);
//        if (!strcmp(str1.c_str(), str2.c_str()))
//            return true;
//    }
//    return false;
//}
//bool is_right_rotate(string str1, string str2)
//{
//    int k = 1;
//    if (str1.size() != str2.size())
//        return false;
//    for (int i = 0; i < str1.size(); i++)
//    {
//        reverse(str1, 0, str1.size() - 1);
//        reverse(str1, 0, k - 1);
//        reverse(str1, k, str1.size() - 1);
//        if (!strcmp(str1.c_str(), str2.c_str()))
//            return true;
//    }
//    return false;
//}
//int main()
//{
//    string str1, str2;
//    cin >> str1 >> str2;
//    bool ret = is_left_rotate(str1, str2);
//    if (ret)
//    {
//        cout << str1 << "是由" << str2 << "左旋得来" << endl;
//        return 0;
//    }
//    else
//    {
//        ret = is_right_rotate(str1, str2);
//        if(ret)
//            cout << str1 << "是由" << str2 << "右旋得来" << endl;
//        else
//            cout << str1 << "不是由" << str2 << "旋转得来" << endl;
//    }
//    return 0;
//}

//void m_swap(char* e1, char* e2, int width)
//{
//	while (width--)
//	{
//		char tmp = *e1;
//		*e1 = *e2;
//		*e2 = tmp;
//		e1++;
//		e2++;
//	}
//}
//

//
//void bullet_sort(void* base, size_t num, size_t width, int(*cmp)(void* e1, void* e2))
//{
//	for (int i = 0; i < num - 1; i++)
//	{
//		for (int j = 0; j < num - i - 1; j++)
//		{
//			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
//				m_swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
//		}
//	}
//}

typedef struct Student
{
	char name[10];
	int age;
}Student;
int cmp_int(void* e1, void* e2)
{
	return (*(int*)e1 - *(int*)e2);
}
int cmp_struct(void* e1, void* e2)
{
	return (*(Student*)e1).age - (*(Student*)e2).age;
}
int main()
{
	//int arr[10] = { 9,2,7,1,0,8,4,6,5,3 };
	//int len = sizeof(arr) / sizeof(arr[0]);
	//qsort(arr, len, sizeof(int), cmp_int);
	Student students[3] = { {"李四",17}, {"王五",16}, {"张三", 18} };
	for (int i = 0; i < 3; i++)
		printf("%s:%d\n", students[i].name, students[i].age);

	qsort(students, 3, sizeof(Student), cmp_struct);
	printf("按年龄排序后：\n");
	for (int i = 0; i < 3; i++)
		printf("%s:%d\n", students[i].name, students[i].age);

	return 0;
}