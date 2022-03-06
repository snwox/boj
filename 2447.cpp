#include<bits/stdc++.h>

using namespace std;
char sqare[2188][2188];
void make(int n,int x,int y){
    if(n==1){
        sqare[x][y]='*';
        return;
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(i==1&&j==1)
                continue;
            make(n/3,n/3*i+x,n/3*j+y);
        }
    }
}
int main(void){
    ios::sync_with_stdio(0);cin.tie(0);
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        fill(&sqare[i][0],&sqare[i][N],' ');
    }
    make(N,0,0);
    for(int i=0;i<N;i++){
        cout << sqare[i] << '\n';
    }
}

// 3
// ***
// * *
// ***

// 9
// *********
// * ** ** *
// *********
// ***   ***
// * *   * *
// ***   ***
// *********
// * ** ** *
// *********