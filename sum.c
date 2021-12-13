
#include <stdio.h>
#include<math.h>
#include <mpi.h>

long double fac(int num){
long double ans=1;

for (int i =1 ; i<=num ; i ++ )
ans =ans * i ;
return ans  ; 
}
 double p ( double n , double m){
return pow(n,m); 
}
double calc (double x , int k ,int rank , int comm_size){

double in = (x * (3.14/180));
double res =0; 
for (double i =rank ; i <= k ; i+= comm_size){

  res = (p(-1.0,i)* p(in,2))/fac(2 * i );}

}


int main (int argc, char* argv[])
{
    int rank, size, error, i;
    double begin=0.0, end=0.0, result=0.0, sum=0.0, x2;
  
    error=MPI_Init (&argc, &argv);
    
    //Get process ID
    MPI_Comm_rank (MPI_COMM_WORLD, &rank);
    
    //Get processes Number
    MPI_Comm_size (MPI_COMM_WORLD, &size);
    //Get_data2 (&a_ptr ,&b_ptr,rank);
      
  //    Get_data2( &a_ptr,  &b_ptr, size,rank );
    
    MPI_Status status;
    
    double a,b ; 
       if (rank == 0) {
        printf("Enter the angle:");
        scanf("%lf",&a);
         printf("Enter k:");
        scanf("%lf",&b);
        
  
    for (int dest=1; dest <size; dest ++){
    MPI_Send(&a, 1, MPI_DOUBLE, dest,0, MPI_COMM_WORLD);
    MPI_Send(&b, 1, MPI_DOUBLE, dest,0, MPI_COMM_WORLD);
    //MPI_COMM_IGNORE
    }}
    else{
        MPI_Recv(&a, 1, MPI_DOUBLE,0, 0, MPI_COMM_WORLD,&status);
        MPI_Recv(&b, 1, MPI_DOUBLE,0, 0, MPI_COMM_WORLD,&status);
    }

    
    
    
      
      
      
      
    //Synchronize all processes and get the begin time
    MPI_Barrier(MPI_COMM_WORLD);
    begin = MPI_Wtime();
    //    calculatin (270 , int 20 ,int rank , int comm_size);
    //Each process caculates a part of the sum
    
//double a=90 ; 
double in = (a * ( 3.141592654/180));
long double res =0; 
for (double i =rank ; i <= b ; i+= size){

  result += (p(-1.0,i)* p(in,2*i))/fac(2 * i );}


    //Sum up all results
    MPI_Reduce(&result, &sum, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
    
    
    MPI_Barrier(MPI_COMM_WORLD);
    end = MPI_Wtime();
    
  
    if (rank==0)
    {
     
        printf("np=%2d;    Time=%fs;    sum=%lf\n", size, end-begin, sum);
    }
    
    error=MPI_Finalize();
    
    return 0;
}
