#include<bits/stdc++.h>

using namespace std;
int N,r,c,answer=0;
void Z(int N,int x,int y,int value){
    // cout << "Z(" <<N<<','<<x<<','<<y<<','<<value<<")\n";
    if(x==r&&y==c){
        answer=value;
        return;
    }
   if(x<=r&&r<x+N&&y<=c&&c<y+N){
       Z(N/2,x,y,value); // 1사분면
       Z(N/2,x,y+N/2,value+(N/2)*(N/2)); // 2사분면
       Z(N/2,x+N/2,y,value+(N/2)*(N/2)*2); // 3사분면
       Z(N/2,x+N/2,y+N/2,value+(N/2)*(N/2)*3); // 4사분면
   }
}
int main(void){
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N >> r >> c;
    Z(1<<N,0,0,0);
    cout << answer << '\n';
}