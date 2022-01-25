#include<bits/stdc++.h>

using namespace std;

vector<int> v[501];
queue<int> q;
int N,times[501],dp[501],in_deg[501],ans[501];
int main(void){
    ios::sync_with_stdio(0);cin.tie(0);
    int a;
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> times[i];
        cin >> a;
        while(a!=-1){
            v[a].push_back(i);
            in_deg[i]++;
            cin >> a;
        }
    }
    for(int i=1;i<=N;i++){
        if(in_deg[i]==0)q.push(i);
        ans[i]=times[i];
    }
    while(!q.empty()){
        int t=q.front();
        q.pop();
        for(auto i:v[t]){
            ans[i]=max(ans[i],times[i]+ans[t]);
            if(--in_deg[i]==0)
                q.push(i);
        }
    }
    for(int i=1;i<=N;i++){
        cout << ans[i] << '\n';
    }
}
