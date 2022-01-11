#include<iostream>

using namespace std;
int map[27][27];
int visit[27][27];
int main(){
    int N;
    cin >> N;
    string s;
    for(int j=0;j<N;j++){
        cin >> s;
        for(int i=0;i<s.size();i++){
            map[j+1][i+1]=s[i]-'0';
        }
        s="";
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(map[i][j]
        }
    }
}