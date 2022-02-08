#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int BFS(int x, int y);
int ar[502][502], visited[502][502];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
queue<pair<int, int>> Q;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M, count = 0, max = 0;
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
            cin >> ar[i][j];
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (!visited[i][j] && ar[i][j])
            {
                int tmp = BFS(i, j);
                max = tmp > max ? tmp : max;
                count++;
                // cout << "(" << i << "," << j << ") : " << tmp << "\n";
            }
        }
    }
    cout << count << '\n'
         << max << '\n';
}
int BFS(int x, int y)
{
    visited[x][y] = 1;
    Q.push({x, y});
    int num = 1;
    while (!Q.empty())
    {
        pair<int, int> cur = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = dx[i] + cur.X;
            int ny = dy[i] + cur.Y;
            if (nx < 1 || nx > 500 || ny < 1 || ny > 500 || visited[nx][ny] || !ar[nx][ny])
                continue;
            Q.push({nx, ny});
            visited[nx][ny] = 1;
            num++;
        }
    }
    return num;
}