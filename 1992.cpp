#include<bits/stdc++.h>

using namespace std;
int ar[65][65];
void quad(int n,int x,int y){
    if(x==1){ // base condition : 1, compressed value == ar[x][y]
        cout << ar[x][y];
        return;
    }
    int _0=0,_1=0;
    for(int i=x;i<x+n;i++){ // check 1 or 0
        for(int j=y;j<y+n;j++){
            if(ar[i][j]==0)_0=1;
            else _1=1;
        }
    }
    // only 1, only 0, mixed
    if(!_0){
        cout << 1;
    }else if(!_1){
        cout << 0;
    }else{
        cout << "(";
        quad(n/2,x,y);
        quad(n/2,x,y+n/2);
        quad(n/2,x+n/2,y);
        quad(n/2,x+n/2,y+n/2);
        cout << ")";
    }
}
int main(void){
    ios::sync_with_stdio(0);cin.tie(0);
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        string s;
        cin >> s;
        for(int j=0;j<N;j++){
            ar[i][j]=s[j]-'0';
        }
    }
    quad(N, 0, 0);
}
