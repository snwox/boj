#include<bits/stdc++.h>
using namespace std;
typedef struct _XYZ{
    int x;
    int y;
    int z;
}xyz;
int dx[]={-1,0,1,0,-1,-2,-2,-1,1,2, 2, 1};
int dy[]={0,1,0,-1,-2,-1, 1, 2,2,1,-1,-2};
int board[202][202];
int visited[202][202][32];
int main(void){
    ios::sync_with_stdio(0);cin.tie(0);
    int K,W,H,flag=0;
    xyz v;
    queue<xyz> Q;
    cin >> K;
    cin >> W >> H;
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            cin >> board[i][j];
        }
    }
    Q.push({1,1,K});
    while(!Q.empty()){
        v=Q.front();Q.pop();
        if(v.x==H&&v.y==W){
            flag=1;
            printf("%d\n",visited[H][W][v.z]);
            break;
        }
        for(int i=0;i<(v.z>0?12:4);i++){
            int nx=v.x+dx[i];
            int ny=v.y+dy[i];
            int nz=i<4?v.z:v.z-1;
            if(nx<1||nx>H||ny<1||ny>W||visited[nx][ny][nz]!=0||board[nx][ny]==1)continue;
            visited[nx][ny][nz]=visited[v.x][v.y][v.z]+1;
            Q.push({nx,ny,nz});
        }
    }
    if(!flag){
        printf("-1\n");
    }
}