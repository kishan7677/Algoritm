#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // naive method
    int maxSubArray1(vector<int> &v)
    {

        int maximum = INT_MIN;
        for (int i = 0; i < v.size(); i++)
        {
            int sum = 0;
            for (int j = i; j < v.size(); j++)
            {
                sum += v[j];
                maximum = max(maximum, sum);
            }
        }

        return maximum;
    }

    // kaden's algorithm
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