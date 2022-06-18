#define _CRT_SECURE_NO_WARNINGS 1

#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    //������topK����
    vector<int> smallestK(vector<int>& arr, int k) {
        vector<int> vec(k);
        if (k == 0) { // �ų� 0 �����
            return vec;
        }
        priority_queue<int> Q;//���ȼ����У��ײ�ʵ��Ϊ����ѵ����ݽṹ��
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
