#include<bits/stdc++.h>

using namespace std;
deque<int> DQ;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N,M,ans=0;
    cin >> N >> M;
    for(int i=1;i<=N;i++){
        DQ.push_back(i);
    }
    for(int i=1;i<=M;i++){
        int n;
        cin >> n;
        int idx=find(DQ.begin(),DQ.end(),n)-DQ.begin();
        // cout << "idx : " << idx << '\n';
        while(DQ.front()!=n){
            // cout << DQ.front() << '\n';
            ans++;
            if(DQ.size()/2<idx){
                DQ.push_front(DQ.back());
                DQ.pop_back();
            }else{
                DQ.push_back(DQ.front());
                DQ.pop_front();
            }
        }
        // cout << "ans : " << DQ.front() << '\n';
        DQ.pop_front();
    }
    cout << ans;

}