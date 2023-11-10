#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* function declaration/prototype
 * input Fn-1 and Fn-2
 * output Fn and Fn-1
 */

void fibonacci(int *a, int *b);

int main(){
	
	int n, i;
	int f0 = 0, f1 = 1;
	
	printf("please enter a postive integer\n");
	scanf("%d", &n);

	if(n < 1){
		printf("The number you enetered is not a positive integer\n");
		exit(1);	
	}
	
	printf("the fibonacci sequnece is:\n");
	printf("%d, %d, ",f0, f1);

	//calculating the sequnce 
	for(i=2;i<=n;i++){
		fibonacci(&f1, &f0);
		printf("%d, ", f1);
		
		if((i+1)%10 == 0) printf("\n");
	}





  return 0;
}


//fibonacci function
void fibonacci(int *a, int *b){
	int next;
	
	//*a=fn-1	*b=fn-2		next=fn
	next = *a + *b;
		
	//*a=fn *b=fn-1
	*b = *a;
	*a = next;


}
