#include<stdio.h>
int power(int n){
	if(n==1){
		return 1;
	}else{
	return	n*power(n);
	}
}
int main(){
	int n,r,ch;
	printf("enter the number u want power");
	scanf("%d",&n);
	printf("1.square power\n");
	printf("2.cube power\n");
	printf("enter the option\n");
	scanf("%d",&ch);
	switch(ch){
		case 1:
		  r=power(n);
		  printf("%d",r);
			break;
		case 2:
		r=power(n)*n;
		printf("%d",r
		);
			break;
		default:
			return 0;
	}
}
