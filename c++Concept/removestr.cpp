

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string s = "spaces in text";
    remove(s.begin(), s.end(), ' ');
    cout << s << endl;
}