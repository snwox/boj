#include<bits/stdc++.h>

using namespace std;
queue<int> q;
int in_degree[32001];
vector<int> v[32001];
int main(){
    int N,M;
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N >> M;
    for(int i=1;i<=M;i++){
        int a,b;
        cin >> a >> b;
        in_degree[b]++;
        v[a].push_back(b);
    }
    for(int i=1;i<=N;i++){
        if(in_degree[i]==0)q.push(i);
    }
    while(!q.empty()){
        int t=q.front();
        q.pop();
        cout << t << ' ';
        for(auto i: v[t]){
            if(--in_degree[i]==0){
                q.push(i);
            }
        }
    }
    
}