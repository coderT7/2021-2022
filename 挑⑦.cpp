#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    int count = 0;
    if (n < 7) {
        cout << 0;
        return 0;
    }
    for (int i = 7; i <= n; i++) {
        int tmp = i;
        if (tmp % 7 == 0) {
            count++;
        }
        else {
            while (tmp) {
                if (tmp % 10 == 7) {
                    count++;
                    break;
                }
                tmp /= 10;
            }
        }
    }
    cout << count;
    return 0;
}