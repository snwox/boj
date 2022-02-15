#include<bits/stdc++.h>

using namespace std;
using long long = ll;

ll pow(ll a,ll x,ll m){
    if(x==1) return a%m;
    ll var=pow(a,x/2,m);
    var=var*var%m;
    if(x%2==0) return var;
    return var*a%m;
}
int main(void){
    ios::sync_with_stdio(0);cin.tie(0);
    ll A,B,C;
    cin >> A >> B >> C;
    cout << pow(A,B,C);
}