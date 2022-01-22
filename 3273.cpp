#include<iostream>
int main(void){
    std::ios::sync_with_stdio(0);std::cin.tie(0);
    int n, ar[1000001],cnt[2000001]={0,},x,ans=0;
    std::cin >> n;
    for(int i=0;i<n;i++){
        std::cin >> ar[i];
    }
    std::cin >> x;
    for(int i=0;i<n;i++){
        if(cnt[x-ar[i]] == 1){
            ans+=1;
        }
        cnt[ar[i]]=1;
    }
    std::cout << ans;
}