#include<bits/stdc++.h>
using namespace std;
queue<int> q;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    for(int i=1;i<=N;i++){
        q.push(i);
    }
    N-=1;
    while(N--){
        q.pop();
        // cout << q.front() << endl;
        q.push(q.front());
        q.pop();
    }
    cout << q.front();
}