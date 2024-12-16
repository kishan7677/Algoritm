#include<bits/stdc++.h>
using namespace std;
//https : // leetcode.com/problems/valid-palindrome/

bool isPalindrome(string s)
{

    int len = s.length();
    string ogstr = "";

    for (int i = 0; i < len; i++)
    {

        if (isalpha(s[i]) || (s[i] >= '0' && s[i] <= '9'))
        {
            ogstr.push_back(tolower(s[i]));
        }
    }
    len = ogstr.length();

    for (int i = 0; i < len / 2; i++)
    {

        if (ogstr[i] != ogstr[len - i - 1])
            return false;
    }
    return true;
}
int main(){
    string str1 = "radar";
    cout<<isPalindrome(str1)<<endl;
}
