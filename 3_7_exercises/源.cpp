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
//		cout << "找到了,下标为：" << x << " " << y << endl;
//	else
//		cout << "未找到" << endl;
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
//	cout << "移动的次数为：" << _count << endl;
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
//step_km是逆推时存距离的
//step_oil存储逆推时的储油量
int main() 
{
	int index = 1, round_num = 1, storage_point = 0;
	step_km[1] = mile - oil;
	step_oil[1] = oil;
	km = oil;//距离起点的距离
	while (km) 
	{
		//逆推到起点即为终止，即和起点距离为0
		//自然是可以直接大于0的...这样下面那行<0的特判就不必要了
		storage_point++;//储油点个数
		round_num += 2;//因为每次多运了500L油，所以多走一个来回,即+2
		step_oil[index + 1] = step_oil[index] + oil;
		step_km[index + 1] = step_km[index] - oil / round_num;
		km = step_km[index];
		if (km < 0) 
		{
			//离起点最近的储油点会出现小于0的情况，这时我们直接结束循环即可
			index--;
			break;		
		}
		index++;
	}
	step_km[index + 1] = 0.00;//最后一组距离为0.00的情况需要特判
	step_oil[index + 1] = step_oil[index] + step_km[index] * round_num;
	int order = 0;
	for (int i = storage_point; i >= 1; i--)
	{
		cout << setiosflags(ios::fixed) << setprecision(4);
		cout << "储油点：" << order << " 距离起点：" << step_km[i] << " 储油量：" << step_oil[i] << endl;
		order++;//t表示储油点的序号,从0开始
	}
	return 0;

}
