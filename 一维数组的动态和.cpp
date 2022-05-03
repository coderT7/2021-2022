#define _CRT_SECURE_NO_WARNINGS 1
#ifdef UNICODE
#undef UNICODE
#endif // UNICODE
#include<iostream>
#include<string>
#include<easyx.h>
#include<conio.h>
#include<graphics.h>
#include<windows.h>
#include<mmsystem.h>    //≤•∑≈“Ù¿÷
#pragma comment(lib,"Winmm.lib")   //≤•∑≈“Ù¿÷
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> runningSum(vector<int>& nums) {
		int n = nums.size();
		for (int i = 1; i < n; i++) {
			nums[i] += nums[i - 1];
		}
		return nums;
	}
};

int main()
{
	initgraph(480, 480, EW_NOMINIMIZE);
	mciSendString("open ./ºŒ±ˆ.mp3 alias mymusic", 0, 0, 0);
	mciSendString("play  mymusic", 0, 0, 0);

	_getch();
	closegraph();
	system("pause");
	return 0;

}