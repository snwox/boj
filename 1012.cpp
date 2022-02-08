#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int ar[52][52],visited[52][52];
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int main(void){
    ios::sync_with_stdio(0);cin.tie(0);
    int T,M,N,K;
    pair<int,int>cur;
    cin >> T;
    while(T--){
        int count=0;
        queue<pair<int,int>> Q;
        cin >> M >> N >> K;
        for(int i=0;i<N;i++){
            fill(ar[i],ar[i]+M,0);
            fill(visited[i],visited[i]+M,0);
        }
        for(int i=0;i<K;i++){
            int a,b;
            cin >> a >> b;
            ar[b][a]=1;
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(!visited[i][j]&&ar[i][j]){
                    count++;
                    Q.push({i,j});
                    while(!Q.empty()){
                        cur=Q.front();
                        Q.pop();
                        for(int k=0;k<4;k++){
                            int nx=cur.X+dx[k];
                            int ny=cur.Y+dy[k];
                            if(nx<0 || nx>=N || ny <0 || ny>=M || visited[nx][ny] || !ar[nx][ny])continue;
                            visited[nx][ny]=1;
                            Q.push({nx,ny});
                        }
                    }
                }
            }
        }
        cout << count << '\n';
    }
}