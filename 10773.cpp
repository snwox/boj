#include<bits/stdc++.h>
using namespace std;
stack<int> s;
int main(void){
    ios::sync_with_stdio(0);cin.tie(0);
    int sum=0,K,n;
    cin >> K;
    while(K--){
        cin >> n;
        if(n==0){
            if(s.empty()){
                s.push(n);
            }else{
                s.pop();
            }
        }else{
            s.push(n);
        }
    }
    while(!s.empty()){
        sum+=s.top();
        s.pop();
    }
    cout << sum;
}