#include<bits/stdc++.h>
typedef struct _XY{
    int X;
    int Y;
}XY;
using namespace std;
int main(void){
    ios::sync_with_stdio(0);cin.tie(0);
    stack<XY>S;
    S.push({100000001,0});
    int N,t;
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> t;
        while(S.top().X<t)
            S.pop();
        cout << S.top().Y << ' ';
        S.push({t,i});
    }
}