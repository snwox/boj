#include<iostream>
#include<string>
using namespace std;
int queue[10010];
int front;
int rear;

int main(){
	int N;
	string input;
	int num;
	cin >> N ;
	while(N--){
		cin >> 	input;
		if(input=="push"){
			cin >> num;
			queue[rear++]=num;
		}else if(input=="pop"){
			if(front>=rear)cout << -1 << endl;
			else{
				cout << queue[front++] << endl;
			}
		}else if(input=="size"){
			cout << rear-front << endl;
		}else if(input=="empty"){
			if(rear==front)cout << 1 << endl;
			else cout << 0 << endl;
		}else if(input=="front"){
			if(front>=rear)cout << -1 << endl;
			else cout << queue[front] << endl;
		}else if(input=="back"){
			if(front>=rear)cout << -1 << endl;
			else cout << queue[rear-1] << endl;
		}
	}
}
