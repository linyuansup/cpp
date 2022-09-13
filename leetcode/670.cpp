#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumSwap(int num)
    {
        string s = to_string(num);
        string result = s;
        int beginPos = 0;
        for (; beginPos < s.length(); beginPos++)
        {
            int maxPos = getMaxPos(s.substr(beginPos, s.length()));
            maxPos += beginPos;
            if (s[beginPos] < s[maxPos])
            {
                result = s.substr(0, beginPos) + s[maxPos] + s.substr(beginPos + 1, maxPos - beginPos - 1) + s[beginPos] + s.substr(maxPos + 1, s.length());
                break;
            }
        }
        return stoi(result);
    }
    int getMaxPos(string s)
    {
        int maxPos = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] >= s[maxPos])
            {
                maxPos = i;
            }
        }
        return maxPos;
    }
};

int main()
{
    Solution sol;
    cout << sol.maximumSwap(98368);
}