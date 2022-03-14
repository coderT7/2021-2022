#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<vector>
using namespace std;

//class Solution
//{
//public:
//	void printAllFolds(int N) {
//		printProcess(1, N, true);
//	}
//
//private:
//	//i为当前层数，N为总层数（对折次数）
//	//ture为凹，false为凸
//	void printProcess(int i, int N, bool down) {
//		if (i > N)
//			return;
//		printProcess(i + 1, N, true);
//		cout << (down ? "凹" : "凸");
//		printProcess(i + 1, N, false);
//	}
//};
//int main()
//{
//	Solution solution;
//	int N = 0;
//	cin >> N;
//	solution.printAllFolds(N);
//	return 0;
//}

class Solution1 {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        int size = nums.size();
        int cur = 0, next = 1;
        while (next < size) {
            if (nums[next] == nums[cur]) {
                int _next = next, _cur = cur;
                while (_next < size) {
                    nums[_cur++] = nums[_next++];
                }
                size--;

            }
            else {
                cur++;
                next++;
            }
        }
        return cur;
    }
};
//原地删除，快慢指针yyds

class Solution2 {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        int size = nums.size();
        int cur = 1, next = 1;
        while (next < size) {
            if (nums[next] != nums[next - 1]) {
                nums[cur] = nums[next];
                cur++;
            }
            next++;
        }
        return cur;
    }
};
int main()
{
    Solution1 solution;
    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    cout << solution.removeDuplicates(v);
    
    return 0;
}