#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;


class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, unordered_set<int>> m; // 用户id,操作时间集合
        for (auto& log : logs)
        {
            m[log[0]].insert(log[1]);
        }
        vector<int> ans(k);
        for (auto& mi : m)
        {
            ans[mi.second.size() - 1]++;
        }
        return ans;
    }
};
int main()
{
    vector<int>v1({ 0,5 }), v2({ 1,2 }), v3({ 0,2 }), v4({ 0,5 }), v5({ 1,3 });
    vector<vector<int>>v({ v1,v2,v3,v4,v5 });
    Solution s;
    vector<int>answer = s.findingUsersActiveMinutes(v, 5);
    for (auto it = answer.begin(); it != answer.end(); it++) {
        cout << *it << endl;
    }
    

	return 0;
}