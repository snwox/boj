#include <bits/stdc++.h>
using namespace std;
typedef struct _XYW
{
    int x;
    int y;
    int w;
} xyw;
char ar[1001][1001];
int visited[2][1001][1001];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    queue<xyw> Q;
    xyw v;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> ar[i][j];
        }
    }
    Q.push({1, 1, 1});
    visited[1][1][1] = 1;
    visited[0][1][1] = 1;
    while (!Q.empty())
    {
        v = Q.front();
        Q.pop();
        if(v.x==N&&v.y==M){
            cout << visited[v.w][N][M] << '\n';
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = v.x + dx[i];
            int ny = v.y + dy[i];
            if (nx < 1 || nx > N || ny < 1 || ny > M || visited[v.w][nx][ny] != 0)
                continue; // index check
            if (ar[nx][ny] == '1' && v.w)
            { // wall breaking chance
                visited[0][nx][ny] = visited[v.w][v.x][v.y] + 1;
                Q.push({nx, ny, 0});
            }
            if(ar[nx][ny]=='0'){
                visited[v.w][nx][ny] = visited[v.w][v.x][v.y] + 1;
                Q.push({nx, ny, v.w});
            }
        }
    }
    if(visited[v.w][N][M]==0){
        cout << -1 << '\n';
    }
}