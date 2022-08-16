#define _CRT_SECURE_NO_WARNINGS 1
#include<vector>
#include<iostream>
using namespace std;


class Solution {
public:
    string intToRoman(int num) {
        string ans;
        int thousand = num / 1000;
        if (thousand != 0) {
            num %= 1000;
            while (thousand--) {
                ans += "M";
            }
        }
        int hundred = num / 100;
        if (hundred != 0) {
            num %= 100;
            switch (hundred) {
            case 1:
                ans += "C";
                break;
            case 2:
                ans += "CC";
                break;
            case 3:
                ans += "CCC";
                break;
            case 4:
                ans += "CD";
                break;
            case 5:
                ans += "D";
                break;
            case 6:
                ans += "DC";
                break;
            case 7:
                ans += "DCC";
                break;
            case 8:
                ans += "DCCC";
                break;
            case 9:
                ans += "CM";
                break;
            }
        }
        int ten = num / 10;
        if (ten != 0) {
            num /= 10;
            switch (ten) {
            case 1:
                ans += "X";
                break;
            case 2:
                ans += "XX";
                break;
            case 3:
                ans += "XXX";
                break;
            case 4:
                ans += "XL";
                break;
            case 5:
                ans += "L";
                break;
            case 6:
                ans += "LX";
                break;
            case 7:
                ans += "LXX";
                break;
            case 8:
                ans += "LXXX";
                break;
            case 9:
                ans += "XC";
                break;
            }
        }
        int digit = num % 10;
        if (digit != 0) {
            switch (digit) {
            case 1:
                ans += "I";
                break;
            case 2:
                ans += "II";
                break;
            case 3:
                ans += "III";
                break;
            case 4:
                ans += "IV";
                break;
            case 5:
                ans += "V";
                break;
            case 6:
                ans += "VI";
                break;
            case 7:
                ans += "VII";
                break;
            case 8:
                ans += "VIII";
                break;
            case 9:
                ans += "IX";
                break;
            }
        }
        return ans;
    }
};

int main() {
    Solution().intToRoman(58);
    return 0;
}
