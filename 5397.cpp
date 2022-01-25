#include<bits/stdc++.h>
using namespace std;
int main(void){
    list<char> L;
    list<char>::iterator cur;
    int T;
    string s;
    cin >> T;
    while(T--){
        cur=L.begin();
        cin >> s;
        for(auto c:s){
            if(c=='<'){
                if(cur!=L.begin())cur--;
            }else if(c=='>'){
                if(cur!=L.end())cur++;

            }else if(c=='-'){
                if(cur!=L.begin()){
                    cur=L.erase(--cur);
                }
            }else{
                L.insert(cur,c);
            }
        }
        for(auto c:L)
            cout << c ;
        cout << '\n';
        L.clear();
    }
}