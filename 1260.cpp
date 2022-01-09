#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

void DFS(int v);
void BFS(int v);

int N,M,V,a,b;
int map[1001][1001];
int visit[1001];
queue<int> q;

int main(int argc,char *argv[]){
	cin >> N >> M >> V;
	for(int i=0;i<M;i++){
		cin >> a >> b;
		
		map[a-1][b-1]=1;
		map[b-1][a-1]=1;
	}
	DFS(V-1);
	cout << endl;
	fill_n(visit,1001,0);
	BFS(V-1);
	cout << endl;
}
void DFS(int v){
	visit[v]=1;
	cout << v+1 << ' ';
	for(int i=0;i<1000;i++){
		if(map[v][i]&&!visit[i]){
			visit[i]=1;
			DFS(i);
		}
	}
}
void BFS(int v){
	visit[v]=1;
	q.push(v);
    cout << v+1 << ' ';
	while(!q.empty()){
		v=q.front();
		q.pop();
		for(int i=0;i<1000;i++){
			if(map[v][i]&&!visit[i]){
				cout << i+1 << ' ';
				q.push(i);
				visit[i]=1;
			}
		}
	}
}
