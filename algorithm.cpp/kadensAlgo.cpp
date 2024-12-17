#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxSubArray(vector<int> &v)
    {
        int maximum = 0, res = INT_MIN;
        for (int i = 0; i < v.size(); i++)
        {
            maximum = max(maximum + v[i], v[i]);
            res = max(res, maximum);
        }
        return res;
    }
};