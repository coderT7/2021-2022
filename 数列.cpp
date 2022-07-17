#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<list>
#include<vector>
using namespace std;

int a[1000001];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= 1000000; i++) {
        if (i <= 2) a[i] = i;
        else a[i] = (2 * a[i - 1] + a[i - 2]) % 32767; //在中间就应取模，防止溢出
    }
    while (n--) {
        int k;
        scanf("%d", &k);
        printf("%d\n", a[k]);
    }
    return 0;
}
