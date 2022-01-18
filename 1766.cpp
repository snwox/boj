#include<bits/stdc++.h>
using namespace std;
int N,M;
int in_degree[32001];
vector<int> v[32001];
priority_queue<int,vector<int>,greater<int>> pq;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N >> M;
    for(int i=1;i<=M;i++){ // 입력받은뒤, 인접리스트에 넣고, 진입차수를 증가시킨다.
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        in_degree[b]++;
    } 
    // for(int i=1;i<=N;i++){ // test
    //     cout << in_degree[i] << '\n';
    // }
    for(int i=1;i<=N;i++){ // 진입차수가 0인 정점을 push
        if(in_degree[i]==0){
            pq.push(i);
        }
    }
    while(!pq.empty()){
        int x=pq.top();
        pq.pop();
        cout << x << ' ';
        for(auto i:v[x]){
            if(--in_degree[i]==0)
                pq.push(i);
        }
    }
}