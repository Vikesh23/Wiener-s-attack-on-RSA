#include<stdio.h>
#include<math.h>
#include<stdlib.h>
long long int a[100];//step-1
long long int counter=0;

long long int h[100]={0},k[100]={0};//step-2
long long int K[100]={0},d[100]={0};

double phi[100]={0};//step-3
long long int final_phi=0;

double x1,x2;//step-4
long long int root1,root2;
float LHS;
double RHS;

void continued_fractions(long long int, long long int);//step-1
int convergent_function(long long int , long long int );//step-2
int check_phi_int(long long int );//step-3
int calculate_root(long long int,long long int,long long int);//step-4 


int main()
{
    long long int e=0,N=0;
    input:
    printf("\nenter the value of e and N :\n");
    scanf("%lld %lld",&e,&N);
    if(e <= 0 || N <= 0)
    {
        printf("*****ENTER VALID e and N : ******** \n");
        goto input;
    }
        
        
    
//step-1  continued fractions calculation


    continued_fractions(e,N);
    long long int j=0;
    printf("\n*****continued fractions of [ %lld / %lld ] are***** : \n",e,N);
    while(j != counter)
        {
		printf("%lld\t",a[j]);
		j++;
	}
	printf("\n\n");
    
    
//step-2 convergent_function calculation 
    long long int jj=0;
    printf("*****all convergents (K / d) are ***** : \n");
    int n=convergent_function(e,N);
	while(jj != n){
		K[jj]=h[jj];	 //for step-3
		d[jj]=k[jj];	 //for step-3
		printf("\t%lld \t/\t %lld\n",K[jj],d[jj] );
		jj++;
	}
		printf("\n\n");


                

//step-3 phi calculation
    
        again:printf("\t");
        printf("*****phi calculation***** :\n");
	final_phi=check_phi_int(e);
        if(final_phi==-1 || final_phi == 2)
        {
            printf("\n*****integer phi is not available  for real integer root calculation ***** : \n\n");
            printf("\t*****we are not able to find the factors of N*****\n\t***** ATTACK IS NOT POSSIBLE***** :\n\n");
            exit(1);
        }
        else
            printf("\t our integer phi==== %lld \n\n",final_phi);
           // printf("ok \t");
            long long int a,b,c;
            a=1;
            b=-((N-final_phi)+1);	
            c=N;
            int value = calculate_root(a,b,c);
            if(value == -1){//printf("\t%d",b);
                goto again;}
            else    //step-5- N=p*q calculation
            {
                if(N == root1 * root2)
                {
                    printf("*****finally we are able to find the correct factors of N***** :\n\n");
                    printf("factor1 = %lld\t factor2 = %lld\n",root1,root2);
                    RHS = (pow(N,0.25))/3;
                    if(LHS < RHS)
                        printf("\t*****ATTACK IS SUCCESSFUL*****\n");
                    else
                        printf("\t*****ATTACK IS NOT POSSIBLE***** :\n");
                }
            }
            printf("\n\n");
            
}    
                
            


//step-1  continued fractions calculation function defination

void continued_fractions(long long int e, long long int N)
{	
	static int r=111,i=0;
	long long int q;
	while(r!= 0)
            {	
		counter++;//printf("%d\t",counter++);
		q=e/N;
		r=e%N;
		a[i]=q;
		//printf("%d\n",temp[i]);
		i++;
		e=N;
		N=r;
		continued_fractions(e,N);
            }
}

//step-2 convergent calculation function defination

int convergent_function(long long int e, long long int N)
{	
        //printf("hy");
	h[0]=a[0];
	h[1]=a[1]*a[0] + 1;
	k[0]=1;
	k[1]=a[1];
        int n=2;
	while(h[n-1] != e && k[n-1] != N && a[n] != '\0')
	{
		h[n]= a[n]*h[n-1] + h[n-2];
		k[n]= a[n]*k[n-1] + k[n-2];
		n++;
		//counter1++;
	}
	return n;

}

//step-3 phi calculation function defination

int check_phi_int(long long int e)
{
        static int x=0;
	int temper=-1;
	while(x<99)
	{  
		phi[x]=((e*d[x+1] - 1)/(float)K[x+1]);
		if(floor(phi[x])==phi[x]){
			temper=(int)phi[x];
                        LHS = d[x+1];
                        x++;
                        break;
		}
            else
                x++;
	}
	if((d[x] == '\0' && K[x] == '\0'))
            return 2;
        else
            return temper;
}

//step-4 root calculation defination

int calculate_root(long long int a,long long int b,long long int c)
{
	long long int D;
	D=b*b-4*a*c;
        //printf("%lld",D);
        if(D>=0){
            x1=(-b+sqrt(D))/(2*a);
            x2=(-b-sqrt(D))/(2*a);
            if((x1-(int)x1)==0 && (x2-(int)x2)==0)
                    {
                            root1=(int)x1;
                            root2=(int)x2;
                            return 1;
                    }
                }
        else{//printf("hyyyyyyyyyyyy");
            return -1;}
} 

