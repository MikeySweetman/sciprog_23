//Practical 4

//including packages
#include <stdio.h>
#include <math.h>

//declaring global variables and functions
int i;
int N = 2000;
float pi = M_PI;
float degtorad(float arg); //not sure what variables should be global and what shouldn't
float results[12];
float arg;
float trapezoidal(int N);



//main function
int main(void){    
    //calculating tan every 5 degrees    
    arg = 0;
    for(i=0; i<13; i++){
	arg = 5.0*i;
	//printf("arg = %f\n", arg);
        results[i] = tan(degtorad(arg));			//need to tidy this 
	printf("tan(x_%d) = %f\n",i ,results[i]);
	//printf("i = %d\n\n", i);
    }

     float area = trapezoidal(N);
     printf("the area under the curve is %f\n", area);

    return 0;
}




//function to convert from degrees to radians
float degtorad(float arg){
    return ((pi * arg)/180.0);
}






//function to compute integral using trapezoidal rule
float trapezoidal(int N){
    float a, b;
    float f0, fN;
    float prefac;
    float area;     
    float arg;
    float sum;

    //calculating prefac
    a = 0;
    b = degtorad(60);
    prefac = ((b - a)/((float)N*2));

    //calculating f0 and fN
    f0 = tan(a);
    fN = tan(b);

    //calculating inner sum
    sum = f0 + fN;
    for(i=1; i<N; i++){
	arg = (60.0/(float)N)*i;
        sum += 2*tan(degtorad(arg));
    }

    //area calc    
    area = prefac*sum;
    
return area;
}
