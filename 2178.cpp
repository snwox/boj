#include<iostream>
#include<queue>
#include<string>

using namespace std;
queue<pair<int,int>>q;
int N,M,map[102][102]={0,},chk[101][101];
void BFS(int x,int y, int c){
	q.push(pair<int,int>(y,x));
	chk[y][x]=c;
	while(!q.empty()){
		int cx = q.front().first;
        int cy = q.front().second;
		q.pop();
		// cout << '(' << cx << ',' << cy << ") : " << chk[cx][cy] << endl;
		if(cx==N&&cy==M){
			cout << chk[N][M] << endl;
			break;
		}
		if(map[cx-1][cy]){
			if(!chk[cx-1][cy]){
			// if (cx-1 < 1 || cx-1 > N || cy < 1 || cy > M) continue;
			q.push(pair<int,int>(cx-1,cy));
			chk[cx-1][cy]=chk[cx][cy]+1;
			}
		}
		if(map[cx+1][cy]){
			if(!chk[cx+1][cy]){
			// if (cx+1 < 1 || cx+1 > N || cy < 1 || cy > M) continue;
			q.push(pair<int,int>(cx+1,cy));
			chk[cx+1][cy]=chk[cx][cy]+1;
			}
		}
		if(map[cx][cy+1]){
			if(!chk[cx][cy+1]){
			// if (cx < 1 || cx > N || cy+1 < 1 || cy+1 > M) continue;
			q.push(pair<int,int>(cx,cy+1));
			chk[cx][cy+1]=chk[cx][cy]+1;
			}
		}
		if(map[cx][cy-1]){
			if(!chk[cx][cy-1]){
			// if (cx < 1 || cx > N || cy-1 < 1 || cy-1 > M) continue;
			q.push(pair<int,int>(cx,cy-1));
			chk[cx][cy-1]=chk[cx][cy]+1;
			}
		}
	}
}
int main(void){
	cin >> N >> M;
	string s;
	for(int i=0;i<N;i++){
		cin >> s;
		for(int j=0;j<s.size();j++){
			map[i+1][j+1]=s[j]-'0';
		}
		s="";
	}
	BFS(1,1,1);
}
