#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    string input;
    while (true)
    {
        stack<int> S;
        int flag = 0;
        getline(cin, input);
        if (input == ".")
            break;
        for (auto &c : input)
        {
            if (c == '(' or c == '[')
                S.push(c);
            else if (c == ')')
            {
                if (!S.empty() && S.top() == '(')
                {
                    S.pop();
                }
                else
                {
                    flag = 1;
                }
            }
            else if (c == ']')
            {
                if (!S.empty() && S.top() == '[')
                {
                    S.pop();
                }
                else
                {
                    flag = 1;
                }
            }
        }
        if(!S.empty())flag=1;
        if (!flag)
            cout << "yes"
                 << "\n";
        else
            cout << "no"
                 << "\n";
    }
}