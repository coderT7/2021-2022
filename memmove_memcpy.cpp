#define _CRT_SECURE_NO_WARNINGS 1

#include<assert.h>

#include<iostream>
using namespace std;

void* my_memcpy(void* dest, const void* src, size_t count) {
	assert(dest && src);
	void* ret = dest;

	while (count--) {
		*(char*)dest = *(char*)src;
		dest = (char*)dest + 1;
		src = (char*)src + 1;
	}
	return ret;
}
void* my_memmove(void* dest, const void* src, size_t count) {
	assert(dest && src);
	void* ret = dest;
	if (dest < src) {
		while (count--) {
			*(char*)dest = *(char*)src;
			dest = (char*)dest + 1;
			src = (char*)src + 1;
		}
	}
	else {
		dest = (char*)dest + count - 1;
		src = (char*)src + count - 1;
		while (count--) {
			*(char*)dest = *(char*)src;
			dest = (char*)dest - 1;
			src = (char*)src - 1;
		}
	}
	return ret;

}
int main()
{
	int arr[10];
	for (int i = 0; i < 10; i++) {
		arr[i] = i + 1;
	}
	int len = sizeof(arr);
	int tmp[20] = { 0 };
	//my_memmove(arr + 2, arr, 20);
	my_memcpy(tmp, arr, len);
	for (int i = 0; i < 10; i++) {
		cout << tmp[i] << " ";
	}
	return 0;
}