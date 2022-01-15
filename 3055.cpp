#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
typedef struct xy{
    int x,y;
    char t;
}xy;

xy dest,start;
int R,C;
char ar[52][52]={0,};
int visited[52][52]={0,};
int water[52][52]={0,};
int dx[4]={0,1,0,-1};
int dy[4]={-1,0,1,0};
queue<xy> q;

void BFS(int y,int x){
    q.push({x,y,'.'});
    int flag=0;
    while(!q.empty()){
        int x=q.front().x;
        int y=q.front().y;
        int t=q.front().t;
        q.pop();
        for(int i=0;i<4;i++){
            int nx=dx[i]+x;
            int ny=dy[i]+y;
            if(t=='*'){
                // printf("water : (%d,%d) from (%d,%d)\n",ny,nx,y,x);
                if(nx<0||nx>=C||ny<0||ny>=R)continue;
                if(water[ny][nx]!=-1||ar[ny][nx]=='D'||ar[ny][nx]=='X')continue;
                // printf("yes\n");
                q.push({nx,ny,'*'});
                water[ny][nx]=water[y][x]+1;
            }else{
                // printf("doch : (%d,%d)\n",ny,nx);
                if(nx<0||nx>=C||ny<0||ny>=R)continue;
                if(visited[ny][nx]!=-1||ar[ny][nx]=='X')continue;
                // printf("yes\n");
                if(water[ny][nx]<=visited[y][x]+1&&water[ny][nx]!=-1)continue;
                visited[ny][nx]=visited[y][x]+1;
                q.push({nx,ny,'.'});
                if(ar[ny][nx]=='D'){
                    cout << visited[dest.y][dest.x] << endl;
                    flag=1;
                }
            }
        }
    }
    if(!flag){
        cout << "KAKTUS" << endl;
    }
    // for(int i=0;i<R;i++){
    //     for(int j=0;j<C;j++){
    //         printf("%2d",visited[i][j]);
    //     }puts("");
    // }
}
int main(void){

    scanf("%d %d",&R,&C);
    memset(visited,-1,sizeof(visited));
    memset(water,-1,sizeof(visited));
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            scanf("%1s",&ar[i][j]);
            if(ar[i][j]=='D'){
                dest.y=i;
                dest.x=j;
            }else if(ar[i][j]=='*'){
                q.push({j,i,'*'});
                water[i][j]++;
            }else if(ar[i][j]=='S'){
                ar[i][j]='.';
                visited[i][j]++;
                start.x=j;
                start.y=i;
            }
        }
    }
    // for(int i=0;i<R;i++){
    //     for(int j=0;j<C;j++){
    //         printf("%c,",ar[i][j]);
    //     }
    //     puts("");
    // }
    BFS(start.y,start.x);
}
