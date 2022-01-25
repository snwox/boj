#include<bits/stdc++.h>

using namespace std;
int nxt[5001];
int pre[5001];
int main(void){
    int N,K,count=1;
    cin >> N >> K;
    for(int i=1;i<=N;i++){
        nxt[i]=i==N?1:i+1;
        pre[i]=i==1?N:i-1;
    }
    int c=0;
    cout << '<';
    for(int cur=1;;cur=nxt[cur]){
        if(count++%K==0){
            c++;
            if(c==N){
                cout << cur << '>';
                    break;
            }
            cout << cur << ", ";
            nxt[pre[cur]]=nxt[cur];
            pre[nxt[cur]]=pre[cur];
        }
    }

}