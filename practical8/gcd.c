#include <stdio.h>

int gcd_iter(int a, int b){
	int temp;
	while(b!=0){
		temp = b;
		b = a%b;
		a = temp;
	}
	return a;
}

int gcd_recursive(int a, int b){
	if(b == 0){
		return a;
	}	
	
	else{
		return gcd_recursive(b, a%b);
	}	
}


int main(void){
	//int a = 5;
	//int b = 26;
	
	//ask user to input two numbers and then calculate the gcd
	int a, b;
	printf("please input two integers\n");
	scanf("%d\n",&a);
	scanf("%d",&b);	

	int ans1 = gcd_iter(a, b);
	int ans2 = gcd_recursive(a, b);
	printf("Using iteration we get %d\nUsing recursion we get %d\n", ans1, ans2);
	
  return 0;	
}
