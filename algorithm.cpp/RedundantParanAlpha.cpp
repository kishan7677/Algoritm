#include <bits/stdc++.h>
bool findRedundantBrackets(string &s)
{
    // Write your code here.
    stack<char> stac;

    for (char ch : s)
    {
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            stac.push(ch);
        }
        else
        {
            if (ch == ')')
            {
                bool hasOp = false;

                while (!stac.empty() && stac.top() != '(')
                {
                    char top = stac.top();
                    if (top == '+' || top == '-' || top == '*' || top == '/')
                    {
                        hasOp = true;
                    }
                    stac.pop();
                }
                if (stac.empty())
                {
                    return true;
                }
                if (!hasOp)
                    return true;
                stac.pop();
            }
        }
    }
    if (stac.empty())
        return false;
}
