#include<bits/stdc++.h>
using namespace std;
void hanoi(int x,int start, int end){
    if(x==0)return;
    hanoi(x-1,start,6-start-end);
    cout << start << ' ' << end << '\n';
    hanoi(x-1,6-start-end,end);
}
int main(void){
    ios::sync_with_stdio(0);cin.tie(0);
    int N;
    cin >> N;
    // 1 - 1
    // 2 - 3
    // 3 - 7
    // move count : 2^N-1 
    cout << (1<<N)-1 << '\n';
    hanoi(N,1,3);
}