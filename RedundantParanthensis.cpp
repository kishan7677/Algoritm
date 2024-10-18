bool isValidParenthesis(string s)
{
    // Write your code here
    // Write your code here
    std::stack<char> strStack;

    for (char ch : s)
    {
        if (ch == '{' || ch == '(' || ch == '[')
        {
            strStack.push(ch);
        }
        else
        {
            if (!strStack.empty())
            {
                char top = strStack.top();
                if ((ch == '}' && top == '{') || (ch == ')' && top == '(') ||
                    (ch == ']' && top == '['))
                {
                    strStack.pop();
                }
            }
            else
            {
                return false;
            }
        }
    }
    if (strStack.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}