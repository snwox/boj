#include <bits/stdc++.h>
#define MAX 1000001
using namespace std;
int visited[MAX + 1];
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int F, S, G, U, D, flag = 0;
    cin >> F >> S >> G >> U >> D;
    queue<int> Q;
    fill(visited, visited + F+1, -1);
    Q.push(S);
    visited[S] = 0;
    while (!Q.empty()&&flag==0)
    {
        int v = Q.front();
        Q.pop();
        for (auto m : {U,-D})
        {
            if(v==G){
                cout << visited[v] << '\n';
                flag=1;
                break;
            }
            if (v+m > F || v+m <=0 || visited[v+m] != -1)
                continue;
            visited[v+m] = visited[v] + 1;
            Q.push(v+m);
        }
    }
    if (!flag)
    {
        cout << "use the stairs" << '\n';
    }
}