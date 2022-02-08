#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int fire[1002][1002], ar[1002][1002], visited[1002][1002];
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T, w, h, flag = 0;
    cin >> T;
    while (T--)
    {
        flag = 0;
        cin >> w >> h;
        for (int i = 0; i < h; i++)
        {
            fill(fire[i], fire[i] + w, -1);
            fill(visited[i], visited[i] + w, -1);
        }
        queue<pair<int, int>> Q;
        pair<int, int> start;
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                char c;
                cin >> c;
                if (c == '#')
                {
                    ar[i][j] = 0;
                }
                else if (c == '*')
                {
                    Q.push({i, j});
                    fire[i][j] = 0;
                    ar[i][j] = 1;
                }
                else if (c == '.')
                {
                    ar[i][j] = 1;
                }
                else
                {
                    start = {i, j};
                    ar[i][j] = 1;
                    visited[i][j] = 0;
                }
            }
        }
        while (!Q.empty())
        {
            pair<int, int> cur = Q.front();
            Q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nx = dx[i] + cur.X;
                int ny = dy[i] + cur.Y;
                if (nx < 0 || ny < 0 || nx >= h || ny >= w || ar[nx][ny] != 1 || fire[nx][ny] != -1)
                    continue;
                fire[nx][ny] = fire[cur.X][cur.Y] + 1;
                Q.push({nx, ny});
            }
        }
        Q.push(start);
        while (!Q.empty() && flag == 0)
        {
            pair<int, int> cur = Q.front();
            Q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nx = dx[i] + cur.X;
                int ny = dy[i] + cur.Y;
                if (nx < 0 || ny < 0 || nx >= h || ny >= w)
                {
                    flag = 1;
                    cout << visited[cur.X][cur.Y] + 1 << '\n';
                    break;
                }
                if (ar[nx][ny] != 1 || visited[nx][ny] != -1 || (visited[cur.X][cur.Y] + 1 >= fire[nx][ny] && fire[nx][ny] != -1))
                    continue;
                visited[nx][ny] = visited[cur.X][cur.Y] + 1;
                Q.push({nx, ny});
            }
        }
        if (!flag)
            cout << "IMPOSSIBLE" << '\n';
    }
}