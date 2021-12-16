#include<iostream>
#include<stack>
#include<string>
#include<sstream>

using namespace std;
stack<int> st;

int main(void){
	int N,item;
	string op;
	cin >> N ;
	while(N--){
		cin >> op ;
		if(op=="push"){
			int x;
			cin >> x;
			st.push(x);
		}else if(op=="pop"){
			if(st.empty())
				cout << -1 << endl;
			else{
				cout << st.top() << endl;
				st.pop();
			}
		}else if(op=="empty"){
			cout << st.empty() << endl;
		}else if(op=="top"){
			if(st.empty())
				cout << -1 << endl;
			else
				cout << st.top() << endl;
		}else{
			cout << st.size() << endl;
		}
	}
}
