#define _CRT_SECURE_NO_WARNINGS 1
#include<queue>
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (!prices.size()) {
            return 0;
        }
        int _min = INT_MAX, res = 0;
        for (int i = 1; i < prices.size(); i++) {
            //_min维护最新的股票最低值
            _min = min(_min, prices[i - 1]);
            //当今日的股票价格高于先前的股票最低值则卖出
            if (prices[i] > _min) {
                //res始终维护最大利润
                res = max(res, prices[i] - _min);
            }
        }
        return res;
    }
};
