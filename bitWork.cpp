#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<cassert>
#include<vector>
#include<map>
#include<unordered_map>
#include<set>
using namespace std;
//#define KNASPACK 50//背包容量
////定义map从大到小排序
//class myCompare {
//public:
//	bool operator()(int x, int y) const {
//		return x > y;
//	}
//};
////价值为key值进行升序插入有序表中
//static void init_knapsack_1(map<int, int, myCompare>& goods) {
//	goods.insert(make_pair<int, int>(40, 20));
//	goods.insert(make_pair<int, int>(60, 15));
//	goods.insert(make_pair<int, int>(12, 12));
//	goods.insert(make_pair<int, int>(30, 10));
//}
////重量为key值进行降序插入有序表中
//static void init_knapsack_2(map<int, int>& goods) {
//	goods.insert(make_pair<int, int>(20, 40));
//	goods.insert(make_pair<int, int>(15, 60));
//	goods.insert(make_pair<int, int>(12, 12));
//	goods.insert(make_pair<int, int>(10, 30));
//}
////价值最高优先
//void knapsack_1() {
//	map<int, int, myCompare>goods;
//	init_knapsack_1(goods);//按价值最高优先插入有序表
//	unordered_map<int, int> bag;
//	int knaspack = 0, index = 0;
//	map<int, int>::iterator it = goods.begin();
//	while (it != goods.end()) {//按价值最高依次放入背包中
//		if (knaspack + it->second < KNASPACK) {
//			bag.insert(make_pair<int, int>((int)it->first, (int)it->second));
//			knaspack += it->second;
//		}
//		it++;
//	}
//	for (auto i : bag) {
//		cout << "物品价值：" << i.first << " " << "物品重量：" << i.second << endl;
//	}
//}
////重量最低优先
//void knapsack_2() {
//	map<int, int>goods;
//	init_knapsack_2(goods);//按重量最低优先插入有序表
//	unordered_map<int, int> bag;
//	int knaspack = 0, index = 0;
//	map<int, int>::iterator it = goods.begin();
//	while (it != goods.end()) {//按重量最低依次放入背包中
//		if (knaspack + it->first < KNASPACK) {
//			bag.insert(make_pair<int, int>((int)it->second, (int)it->first));
//			knaspack += it->first;
//		}
//		it++;
//	}
//	for (auto i : bag) {
//		cout << "物品价值：" << i.first << " " << "物品重量：" << i.second << endl;
//	}
//}
////价格:重量最高值优先
//void knapsack_3() {
//	map<int, int>goods;
//	init_knapsack_2(goods);
//	map<int,int,myCompare> density;
//	for (auto i : goods) {//将物品按比值进行降序排序
//		density.insert(make_pair<int, int>((int)(i.second / i.first), (int)i.first));
//	}
//	map<int, int>::iterator it = goods.begin();
//	unordered_map<int, int>bag;
//	int knapsack = 0;
//	for (auto i : density) {//将物品依次按照排序后的顺序放入背包中
//		it = goods.find(i.second);
//		if (knapsack + it->first > KNASPACK)
//			break;
//		else {
//			bag.insert(make_pair<int, int>((int)it->first, (int)it->second));
//			knapsack += it->first;
//		}
//	}
//	for (auto i : bag) {
//		cout << "物品价值：" << i.second << " " << "物品重量：" << i.first << endl;
//	}
//}
//int main()
//{
//	cout << "价值最大优先：" << endl;
//	knapsack_1();
//	cout << endl;
//	cout << "重量最轻优先：" << endl;
//	knapsack_2();
//	cout << endl;
//	cout << "价值密度最高优先：" << endl;
//	knapsack_3();
//	return 0;
//}

int my_strlen(const char* str) {
	assert(str);
	int len = 0;
	while (*(str++))
		len++;
	return len;
}
char* my_strcpy(char* str1, const char* str2) {
	assert(str1);
	assert(str2);
	char* ret = str1;
	while (*(str1++) = *(str2++)) {
		;
	}
	return ret;
}
int my_strcmp(const char* str1, const char* str2) {
	assert(str1);
	assert(str2);
	while (*(str1++) && *(str2++)) {
		if (*str1 == *str2) {
			continue;
		}
		return *str1 - *str2;
	}
	return 0;
}
char* my_strcat(char* str1, char* str2) {
	assert(str1);
	assert(str2);
	char* ret = str1;
	while (*str1) {
		str1++;
	}
	while (*(str1++) = *(str2++)) {
		;
	}
	return ret;
}
char* my_strstr(char* str1, char* str2) {
	assert(str1);
	assert(str2);
	char* first = str1;
	char* second = str2;
	char* cur = str1;

	while (*cur) {
		first = cur;
		second = str2;

		while(*first && *second && (*first == *second)) {
			first++;
			second++;
		}

		if (*second == '\0')
			return cur;

		cur++;
	}
	return NULL;
}
int main()
{
	char arr[20] = "abcdef"; 
	char* str = (char*)"bcd";
	cout << my_strcat(arr, str);
	return 0;
}