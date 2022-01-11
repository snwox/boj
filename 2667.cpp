#include<iostream>
#include<stdio.h>
#include <algorithm>
using namespace std;
int map[26][26]={0,};
int visit[26][26]={0,};
int yy[]={0,-1,0,1};
int xx[]={-1,0,1,0};
int N;

int DFS(int y,int x,int c){
    if (y < 0 || x < 0 || y >= N || x >= N || map[y][x] == 0) return 0;
    visit[y][x]=1;
    for(int asdf=0;asdf<4;asdf++){
        int nx=x+xx[asdf];
        int ny=y+yy[asdf];
        cout << '(' << ny << ',' << nx << ')' <<c << endl;
        if(map[ny][nx]&&!visit[ny][nx]){
            cout <<"yes" << endl;
            visit[ny][nx]=1;
            c=DFS(ny,nx,c+1);
        }
    }    
    return c;
}
int main(){
    int house=0;
    int houses[25*25]={0,};
    scanf("%d",&N);
    for(int j=0;j<N;j++){
        for(int i=0;i<N;i++){
            scanf("%1d",&map[j][i]);
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(map[i][j]&&!visit[i][j]){
                // cout << '(' << i << ',' << j << ')' << endl;
                houses[house++]=DFS(i,j,1);
                // exit(0);
            }
        }
    }
    sort(houses,houses+house);
    cout << house << endl;
    for(int i=0;i<house;i++){
        cout << houses[i] << endl;
    }
}