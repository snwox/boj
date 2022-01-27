#include<bits/stdc++.h>
using namespace std;
stack<int> s;
int main(void){
    ios::sync_with_stdio(0);cin.tie(0);
    int N,n,c=1;
    string ans;
    cin >> N;
    while(N--){
        cin >> n;
        while(c<=n){
            s.push(c++);
            ans+="+\n";
        }
        if(s.top()==n){
            s.pop();
            ans+="-\n";
        }else{
            cout << "NO" << '\n';
            return 0;
        }
    }
    cout << ans;
}