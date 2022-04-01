#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#include<cstdlib>
#include<assert.h>
using namespace std;


class Solution {
public:
	int my_atoi(string str) {

	}

	void find_signal_num(int* arr, int len) {
		int singal_1 = 0, singal_2 = 0;

		int pos = 0, ret = 0;
		for (int i = 0; i < len; i++) {
			ret ^= arr[i];
		}
		for (int i = 0; i < 32; i++) {
			if ((((ret >> i) & 1) == 1)) {
				pos = i;
				break;
			}
		}
		for (int i = 0; i < len; i++) {
			if (((arr[i] >> pos) & 1) == 0) {
				singal_1 ^= arr[i];
			}
		}
		singal_2 = ret ^ singal_1;
		cout << singal_1 << " " << singal_2 << endl;
	}
	char* my_strncpy(char* dest, char* src, size_t size) {
		assert(dest && src);

		char* ret = dest;
		while (size--) {
			*dest++ = *src++;
		}
		return ret;
	}
	char* my_strncat(char* dest, char* src, size_t size) {
		assert(dest && src);
		char* ret = dest;
		while (*dest) {
			dest++;
		}
		while (size--){
			*dest++ = *src++;
		}
		
		return ret;
	}
};

int main()
{
	Solution solution;
	char str1[20] = "hello ";
	char str2[] = "world";
	char* tmp = solution.my_strncpy(str1, str2, 5);
	cout << tmp;
	return 0;
}