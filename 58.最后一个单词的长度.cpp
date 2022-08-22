/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
#include<string>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
        int end = s.size()-1;
        while(s[end] == ' '){
            s.erase(end);
            end--;
        }
        int pos = s.rfind(' ');
        string tmp = s.substr(pos+1);
        return tmp.size();
    }
};
// @lc code=end

