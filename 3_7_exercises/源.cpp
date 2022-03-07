#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

//#define row 5
//#define col 5

//int x = 0, y = 0;
//int Y_matrix[row][col] = {
//	{1,4,7,11,15},
//	{2,5,8,12,19},
//	{3,6,9,16,22},
//	{10,13,14,17,24},
//	{18,21,23,26,30}
//};
//
//bool find_target(int target)
//{
//	int _row = row, _col = col;
//	for (int i = 0; i < _row; i++)
//	{
//		for (int j = _col - 1; j >= 0; j--)
//		{
//			if (Y_matrix[i][j] == target)
//			{
//				x = i, y = j;
//				return true;
//			}
//
//			else if (Y_matrix[i][j] > target)
//				_col--;
//			else
//				break;
//		}
//	}
//	return false;
//}
//int main()
//{
//	int target = 0;
//	cin >> target;
//	bool ret = find_target(target);
//	if (ret)
//		cout << "�ҵ���,�±�Ϊ��" << x << " " << y << endl;
//	else
//		cout << "δ�ҵ�" << endl;
//	return 0;
//}

//void reverse(string& str, int start, int end)
//{
//    while (start < end) {
//        swap(str[start], str[end]);
//        start += 1;
//        end -= 1;
//    }
//}
//int main()
//{
//    string str;
//    cin >> str;
//    int k = 0;
//    cin >> k;
//    k %= str.size();
//    reverse(str, 0, str.size() - 1);
//    reverse(str, 0, str.size() - k - 1);
//    reverse(str, str.size() - k, str.size() - 1);
//    cout << str;
//    return 0;
//}

//long long _count = 0;
//void _move(char A, char C)
//{
//	cout << A << "->" << C << endl;
//	_count++;
//}
//void Hanoi(int n, char A, char B, char C)
//{
//	if (n == 1)
//	{
//		_move(A, C);
//		return;
//	}
//	Hanoi(n - 1, A, C, B);
//	_move(A, C);
//	Hanoi(n - 1, B, A, C);
//}
//
//int main()
//{
//	int n = 0;
//	cin >> n;
//	char a = 'A', b = 'B', c = 'C';
//	Hanoi(n, a, b, c);
//	cout << "�ƶ��Ĵ���Ϊ��" << _count << endl;
//	return 0;
//}



#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <ctime>
using namespace std;

float mile = 1000, oil = 500;
float step_km[20], step_oil[20], km = 0;
//step_km������ʱ������
//step_oil�洢����ʱ�Ĵ�����
int main() 
{
	int index = 1, round_num = 1, storage_point = 0;
	step_km[1] = mile - oil;
	step_oil[1] = oil;
	km = oil;//�������ľ���
	while (km) 
	{
		//���Ƶ���㼴Ϊ��ֹ������������Ϊ0
		//��Ȼ�ǿ���ֱ�Ӵ���0��...������������<0�����оͲ���Ҫ��
		storage_point++;//���͵����
		round_num += 2;//��Ϊÿ�ζ�����500L�ͣ����Զ���һ������,��+2
		step_oil[index + 1] = step_oil[index] + oil;
		step_km[index + 1] = step_km[index] - oil / round_num;
		km = step_km[index];
		if (km < 0) 
		{
			//���������Ĵ��͵�����С��0���������ʱ����ֱ�ӽ���ѭ������
			index--;
			break;		
		}
		index++;
	}
	step_km[index + 1] = 0.00;//���һ�����Ϊ0.00�������Ҫ����
	step_oil[index + 1] = step_oil[index] + step_km[index] * round_num;
	int order = 0;
	for (int i = storage_point; i >= 1; i--)
	{
		cout << setiosflags(ios::fixed) << setprecision(4);
		cout << "���͵㣺" << order << " ������㣺" << step_km[i] << " ��������" << step_oil[i] << endl;
		order++;//t��ʾ���͵�����,��0��ʼ
	}
	return 0;

}
