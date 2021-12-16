#include<stdio.h>

int main(void){
	int x,y,w,h,max=1001;
	scanf("%d %d %d %d",&x,&y,&w,&h);
	int ar[4]={x,w-x,y,h-y};
	for(int i=0;i<4;i++){
		if(ar[i]<max)max=ar[i];
	}
	printf("%d",max);
}
