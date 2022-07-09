#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    int count = 0;
    for (int i = 0; i <= n; i++) {
        int _i = i;
        int squareNum = (int)pow(i, 2);
        while (true) {
            if (_i % 10 != squareNum % 10) {
                break;
            }
            _i /= 10;
            squareNum /= 10;
            if (_i == 0)
                break;
        }
        if (_i == 0) {
            count++;
        }
    }
    cout << count;
    return 0;
}