#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string input;
    cin >> input;
    stack<char> S;
    int flag = 0, ans = 0, tmp = 1;
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == '(')
        {
            tmp *= 2;
            S.push(input[i]);
        }
        if (input[i] == '[')
        {
            tmp *= 3;
            S.push(input[i]);
        }
        if (input[i] == ')')
        {
            if (input[i - 1] == '(') // 2
            {
                S.pop();
                ans += tmp;
            }
            else if (!S.empty() && S.top() == '(')
            {
                S.pop();
            }
            else
            {
                flag = 1;
                break;
            }
            tmp /= 2;
        }
        else if (input[i] == ']')
        {
            if (input[i - 1] == '[') // 3
            {
                S.pop();
                ans += tmp;
            }
            else if (!S.empty() && S.top() == '[')
            {
                S.pop();
            }
            else
            {
                flag = 1;
                break;
            }
            tmp /= 3;
        }
    }
    if (!S.empty())
    {
        flag = 1;
    }
    if (!flag)
        cout << ans;
    else
        cout << 0;
}