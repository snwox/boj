#include<bits/stdc++.h>

using namespace std;
queue<int> q;
int in_degree[1001];
vector<int> v[1001];
queue<int> s;
int main(){
    int N,M;
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N >> M;
    int num,a,b;
    int tmp=0;
    for(int i=1;i<=M;i++){
        cin >> num;
        cin >> a;
        for(int j=1;j<=num-1;j++){
            cin >> b;
            v[a].push_back(b);
            in_degree[b]++;
            a=b;
        }
    }
    for(int i=1;i<=N;i++){
        if(in_degree[i]==0)q.push(i);
    }
    while(!q.empty()){
        int t=q.front();
        q.pop();
        s.push(t);
        for(auto i: v[t]){
            if(--in_degree[i]==0){
                q.push(i);
            }
        }
    }
    if(s.size()!=N){
        cout << 0 << endl;
    }else{
        for(int i=0;i<N;i++){
            cout << s.front() << '\n';
            s.pop();
        }
    }
}