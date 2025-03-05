//stack
#include<stdio.h>
int max=10;
int top=-1;
int arr[10];
int isfull(){
	if(top==max-1){
		printf("overflow");
		return 0;
	}
}
int isempty(){
	if(top<0||top==-1){
		printf("underflow");
	}
	return 0;
}
int push(int a){
	if(top==max-1){
		printf("overflow");
		return 0;
	}
	else{
		top++;
		arr[top]=a;
	//	return 1;
	    printf("%d is pushed to stack\n",a);
	}
}
int pop(){
	if(top<0||top==-1){
		printf("underflow");
	}
	else{
		int p=arr[top--];
	}
}
int peek(){
	if(top<0||top==-1){
		printf("underflow");
	}
	return arr[top];
}
int main(){
	push(10);
	push(15);
	push(20);
	push(25);
	push(30);

    printf("popeed elemnt :%d\n",pop());
    printf("top elemnt:%d\n",peek());
    return 0;
}
