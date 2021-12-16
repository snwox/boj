#include<stdio.h>
#include<math.h>

struct xy {
	int x;
	int y;
}xy[3];
main(){
int i;
for(i=0;i<3;i++){
	scanf("%d %d",&xy[i].x,&xy[i].y);
}
int x,y;
x=xy[2].x;
y=xy[2].y;
for(i=0;i<2;i++){
	if(x==xy[i].x){
		x=xy[(i+1)%2].x;
		break;
	}
}
for(i=0;i<2;i++){
	if(y==xy[i].y){
		y=xy[(i+1)%2].y;
		break;
	}
}

printf("%d %d",x,y);

}
