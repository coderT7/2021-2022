#include<bits/stdc++.h>

using namespace std;
class MinStack
{
private:
    stack<int> st;
    stack<int> minSt;

public:
    MinStack()
    {
    }

    void push(int val)
    {
        st.push(val);
        if (minSt.empty() || val <= minSt.top())
            minSt.push(val);
    }

    void pop()
    {
        if (st.top() == minSt.top())
        {
            minSt.pop();
        }
        st.pop();
    }

    int top()
    {
        return st.top();
    }

    int getMin()
    {
        return minSt.top();
    }
};
class Solution
{
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV)
    {
        stack<int> sim;
        int index1 = 0;
        int index2 = 0;
        while (index1 != pushV.size())
        {
            sim.push(pushV[index1]);
            index1++;
            while (!sim.empty() && sim.top() == popV[index2])
            {
                sim.pop();
                index2++;
            }
        }
        return index2 == popV.size();
    }
};