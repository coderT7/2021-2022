#define _CRT_SECURE_NO_WARNINGS 1

#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    //类似于topK问题
    vector<int> smallestK(vector<int>& arr, int k) {
        vector<int> vec(k);
        if (k == 0) { // 排除 0 的情况
            return vec;
        }
        priority_queue<int> Q;//优先级队列（底层实际为大根堆的数据结构）
        for (int i = 0; i < k; ++i) {
            Q.push(arr[i]);
        }
        for (int i = k; i < (int)arr.size(); ++i) {
            if (Q.top() > arr[i]) {
                Q.pop();
                Q.push(arr[i]);
            }
        }
        for (int i = 0; i < k; ++i) {
            vec[i] = Q.top();
            Q.pop();
        }
        return vec;
    }
};
