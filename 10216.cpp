#include<bits/stdc++.h>

using namespace std;

typedef struct xyr{
    int x,y,r;
}xyr;

xyr cord[5001];
int visited[5001];
int sqare(int x){
    return x*x;
}
int main(void){
    int T,N,ans=0;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        ans=0;
        fill(visited,visited+N,0);
        stack<int> s;
        for(int i=0;i<N;i++){
            scanf("%d%d%d",&cord[i].x,&cord[i].y,&cord[i].r);
        }
        for(int i=0;i<N;i++){
            if(visited[i])continue;
            visited[i]=1;
            s.push(i);
            ans++;
            // printf("(%d,%d,%d) -> ",cord[i].x,cord[i].y,cord[i].r);
            while(!s.empty()){
                int v=s.top();
                s.pop();
                for(int j=0;j<N;j++){
                    if(!visited[j] && sqare(cord[v].x-cord[j].x)+sqare(cord[v].y-cord[j].y) <= sqare(cord[v].r+cord[j].r)){
                        // printf("(%d) (%d,%d,%d) -> ",sqare(cord[i].x-cord[j].x)+sqare(cord[i].y-cord[j].y),cord[j].x,cord[j].y,cord[j].r);
                        visited[j]=1;
                        s.push(j);
                    }
                }
            }
            // printf("\n");

        }
        printf("%d\n",ans);
    }
}