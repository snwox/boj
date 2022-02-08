#include<bits/stdc++.h>
using namespace std;
int visited[100002];
int main(void){
    ios::sync_with_stdio(0);cin.tie(0);
    queue<int> Q;
    fill(visited,visited+100002,-1);
    int N,K;
    cin >> N >> K;
    Q.push(N);
    visited[N]=0;
    while(visited[K]==-1){
        int cur=Q.front();
        Q.pop();
        for(int nxt:{cur-1,cur+1, cur*2}){
            if(nxt<0 || nxt >100000 || visited[nxt]!=-1)continue;
            Q.push(nxt);
            visited[nxt]=visited[cur]+1;
        }
    }
    cout << visited[K] << '\n';
}