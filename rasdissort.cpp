#include <stdio.h>
#include <queue>
using namespace std;

const int n = 5;

void radixSort(int arr[]){
	int max=-1;
	int max_len=1;
	queue<int> q[10];
	for(int i=0;i<n;i++)if(arr[i]>max)max=arr[i];
	while(max>0){
		max/=10;
		max_len*=10;
	}
	for(int i=1;i<=max_len;i*=10){
		for(int j=0;j<n;j++){
			q[arr[j]/i%(i*10)].push(arr[j]);
		}
		int c=0;
		printf("loop %d\n",i);
		puts("=====================================");
		for(int j=0;j<10;j++){
			printf("queue : %d\n",j);
			while(!q[j].empty()){
				printf("%d, ",q[j].front());
				arr[c++]=q[j].front();
				q[j].pop();
			}
			puts("\n-------------------------------------");
		}
		puts("=====================================");
	}
}

int main(){
    int arr[n] = {32, 74, 12, 84, 70};
    radixSort(arr);
    for(int i=0; i<n; i++) printf("%d ", arr[i]);
}

