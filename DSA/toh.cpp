//tower of hanoi
#include <stdio.h>
void tower(int n,char beg,char aux,char end){
	if(n<=0){
		printf("\n illegal entry");
	}else if(n==1){
		printf("\nmove disc from %c to %c",beg,end);
	}else{
		
		tower(n-1,beg,end,aux);
		tower(1,beg,aux,end);
		tower(n-1,aux,beg,end);
	}
}
int main(){
	int n;
	char a,b,c;
	printf("enter the number of disc");
	scanf("%d",&n);
	printf("tower of hanoi of %d disc\n",n);
	tower(n,'a','b','c');
	
}
