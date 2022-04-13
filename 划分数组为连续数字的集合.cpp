#define _CRT_SECURE_NO_WARNINGS 1
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;
class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if (nums.empty()) {
            return false;
        }
        if (nums.size() % k != 0) {
            return false;
        }
        //��������������Ա���ÿ�ζ��ҵ���С���Ǹ���
        sort(nums.begin(), nums.end());
        //�������е����ڹ�ϣ���м�¼����
        unordered_map<int, int> record;
        for (auto& num : nums) {
            record[num]++;
        }
        //������������
        for (auto& x : nums) {
            //�����ǰԪ���ڹ�ϣ���в������ˣ���˵����������һ�����Ѿ��ù����Ҽ�Ϊ0�ˣ����������������
            if (!record.count(x)) {
                continue;
            }
            //���ӵ�ǰ�����С������ʼ���ܷ����һ��k����������
            for (int i = 0; i < k; i++) {
                int tmp = x + i;
                //���tmp�ڹ�ϣ���в����ڣ�˵�������������в�����
                if (!record.count(tmp)) {
                    return false;
                }
                //������ڣ����Ӧ��¼��һ
                record[tmp]--;
                //�����һ���¼Ϊ0������������Ƴ���ϣ��
                if (record[tmp] == 0) {
                    record.erase(tmp);
                }
            }
        }
        return true;
    }
};