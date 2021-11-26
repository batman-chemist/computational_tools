/*this program will perform the Newton Raphson methd to 
find the the root of an equation defined by the user. 
Along with the eqauation the fisrt derivative of it 
should be defined as well.*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define f(x) 3 * x - sin(x) - 1 //define the function of interest here
#define g(x) 3 - cos(x)       //derivative of the fucntion defined above. Chnage accordingly. 
int main()
{
	float x0,x1,f0,f1,g0,g1,e=0.000001;
	int i=1, N=0;
	printf("\nEnter the initial guess value for the root (x0)=  ");
	scanf("%f",&x0);
	printf("\nMaximum number of iterations, N= ");
	scanf("%d",&N);
	printf("\nThe maximum tolerable value, e= %f",e);
	//begining of the NR method
	printf("\n\n******************************\n\tNewton Raphson\n******************************\n\n");

	do
	{
	f0 = f(x0);
	g0 = g(x0);

	printf("\n\nf0= %f and g0= %f",f0,g0);
	
	if (g0 == 0)
		{
		printf("\n\nMathematical error!!!\n\n");
		exit(0);
		}

	printf("\n\nIteration number: %d",i);
	i=i+1;
	
	x1= x0 - (f0 / g0);
	
	f1= f(x1);
	g1= g(x1);
	
	printf("\t x1 = %f \t f1= %f",x1,f1);

	x0=x1;
	
	}while (fabs(f1)>e && i<=N);

	if (fabs(f1) > e)
	{
		printf("\n%f\n",fabs(f1));
		printf("\n\nNot converged\n\n");
	}
	else 
	{
	printf("\n\nHurray!! The caclualtion has converged\n\n");
	printf("The root of the equation is: %f\n\n",x1);
	}

	return 0;
}
