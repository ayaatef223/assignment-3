
#include <stdio.h>
#include <math.h>
#include <time.h>

long double fac(int num){
long double ans=1;

for (int i =1 ; i<=num ; i ++ )
ans =ans * i ;
return ans  ; 
}
 double p ( double n , double m){
return pow(n,m); 
}


int main (int argc, char* argv[])
{
    
    double a,b ; 
      
        printf("Enter the angle:");
        scanf("%lf",&a);
         printf("Enter k:");
        scanf("%lf",&b);
        
   // begin = MPI_Wtime();
    clock_t start= clock();
double in = (a * ( 3.141592654/180));
long double res =1; 
for (double i =1 ; i <= b ; i+= 1){

  res += (p(-1.0,i)* p(in,2*i))/fac(2 * i );
  }
clock_t end= clock();
double end_begin = (double )(end - start)/CLOCKS_PER_SEC;
    //end = MPI_Wtime();
    printf("Time=%fs;    sum=%Lf\n",  end_begin, res);
    
    return 0;
}













