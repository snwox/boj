#include<stdio.h>
#include<string.h>


int queue[50000];
int rear=20000;
int front=20000;
void push_front(int data){
	queue[front--]=data;
}
void push_back(int data){
	queue[++rear]=data;
}
int pop_front(){
	if(front>=rear)return -1;
	return queue[++front];
}
int pop_back(){
	if(front>=rear)return -1;
	return queue[rear--];
}
int size(){
	return rear-front;
}
int empty(){
	return rear==front;
}
int head(){
	if(front>=rear)return -1;
	return queue[front+1];
}
int back(){
	if(front>=rear)return -1;
	return queue[rear];
}
int main(){
	int N,data;
	char buf[100];
	scanf("%d",&N);
	while(N--){
		scanf("%s",buf);
		if(!strcmp(buf,"push_back")){
			scanf("%d",&data);
			push_back(data);
		}else if(!strcmp(buf,"push_front")){
			scanf("%d",&data);
			push_front(data);
		}else if(!strcmp(buf,"pop_front")){
			printf("%d\n",pop_front());
		}else if(!strcmp(buf,"pop_back")){
			printf("%d\n",pop_back());
		}else if(!strcmp(buf,"size")){
			printf("%d\n",size());
		}else if(!strcmp(buf,"empty")){
			printf("%d\n",empty());
		}else if(!strcmp(buf,"front")){
			printf("%d\n",head());
		}else if(!strcmp(buf,"back")){
			printf("%d\n",back());
		}
	}
}
