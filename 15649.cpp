#include <bits/stdc++.h>

using namespace std;
int N, M;
int ar[10];
int used[10];

void back(int n)
{
    if (n == M)
    {
        for (int i = 0; i < M; i++)
        {
            cout << ar[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = 1; i <= N; i++){
        if(!used[i]){
        ar[n]=i;
        used[i]=1;
        back(n+1);
        used[i]=0;
        }
    }
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    back(0);
}