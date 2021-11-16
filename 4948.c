/*
	using eratostenes's net, set prime numbers to 0;
	and count prime numbers between n and 2n
*/

#include<stdio.h>
#define MAX 246913
int main(void){
	int n,ar[MAX]={1,1,0},c;
	for(int i=2;i<MAX;i++){
		for(int j=2;i*j<=MAX;j++){
			ar[i*j]=1;
		}
	}
	while(scanf("%d",&n),n!=0){
		c=0;
		for(int i=n+1;i<=2*n;i++){
			if(!ar[i]){c++;}
		}
		printf("%d\n",c);
	}
}
