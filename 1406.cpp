#include<bits/stdc++.h>
using namespace std;
int main(void){
    list<char> l;
    list<char>::iterator it;
    string s;
    char arg;
    int N;
    cin >> s;
    for(auto i:s){
        l.push_back(i);
    }
    it=l.end();
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> s;
        if(s=="L"){
            if(it!=l.begin())it--;
        }else if(s=="D"){
            if(it!=l.end())it++;
        }else if(s=="B"){
            if(it!=l.begin()){
                it--;
                it=l.erase(it);
            }
        }else if(s=="P"){
            cin >> arg;
            l.insert(it,arg);
        }
    }
    for(auto c:l)cout << c;
}
