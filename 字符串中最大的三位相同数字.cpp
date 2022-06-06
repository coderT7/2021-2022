#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<string>
using namespace std;

//int main()
//{
//	char c2[] = { '\x10', '\xa', '\8' };
//	for (auto val : c2) {
//		cout << val << endl;
//	}
//	return 0;
//}

//#include <iostream>
//using namespace std;
//class A
//{
//public:
//    void print()
//    {
//        cout << "A:print()";
//    }
//};
//class B : private A
//{
//public:
//    void print()
//    {
//        cout << "B:print()";
//    }
//};
//class C : public B
//{
//public:
//    void print()
//    {
//        //A::print();
//    }
//};
//int main()
//{
//    C b;
//    b.print();
//}

//#include <iostream>       
//#include <vector>
//using namespace std;
//int main(void)
//{
//	vector<int>array;
//	array.push_back(100);
//	array.push_back(300);
//	array.push_back(300);
//	array.push_back(300);
//	array.push_back(300);
//	array.push_back(500);
//	vector<int>::iterator itor;
//	for (itor = array.begin(); itor != array.end(); itor++)
//	{
//		if (*itor == 300)
//		{
//			itor = array.erase(itor);
//		}
//	}
//	for (itor = array.begin(); itor != array.end(); itor++)
//	{
//		cout << *itor << " ";
//	}
//	return 0;
//}

class Solution {
public:
    string largestGoodInteger(string num) {
        int max = -1;
        for (char val : num) {
            if (val - '0' > max)
                max = val - '0';
        }
        int* arr = (int*)calloc(max + 1, sizeof(int));
        for (char val : num) {
            arr[val - '0']++;
        }
        vector<int> res;
        for (int i = 0; i <= max; i++) {
            if (arr[i] == 3) {
                res.push_back(i);
            }
        }
        if (res.empty()) {
            return "";
        }
        max = -1;
        for (auto val : res) {
            if (val > max)
                max = val;
        }
        max = max * 100 + max * 10 + max;
        string ret = to_string(max);
        return ret;
    }
};
class Solution2 {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        string res;
        for (int i = 0; i < n - 2; ++i) {
            if (num[i] == num[i + 1] && num[i + 1] == num[i + 2]) {
                res = max(res, num.substr(i, 3));
            }
        }
        return res;
    }
};

int main()
{
    Solution s1;
    string num ="6777133339";
    string ret = s1.largestGoodInteger(num);
    cout << ret << endl;
    return 0;
}