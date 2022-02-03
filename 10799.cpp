#include <bits/stdc++.h>
using namespace std;

stack<char> S;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string input;
    int sum = 0;
    cin >> input;
    for (int i=0;i<input.size();i++)
    {
        if (input[i] == '(')
            S.push('(');
        else
        { // c == ')'
            if (input[i-1] == '(')
            { // laser
                S.pop();
                sum += S.size();
            }
            else
            { // end of the iron rod
                S.pop();
                sum++;
            }
        }
    }
    cout << sum;
}