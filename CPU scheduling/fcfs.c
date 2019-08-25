#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b)
{int temp;
temp=*a;
*a=*b;
*b=temp;
}
void main()
{int n,i,j;
float sw=0,st=0;
printf("Enter the number of process:");
scanf("%d",&n);
int *a=(int*)malloc(n*sizeof(int));
int *b=(int*)malloc(n*sizeof(int));
int *w=(int*)malloc(n*sizeof(int));
int *t=(int*)malloc(n*sizeof(int));
for( i=0;i<n;++i)
        {printf("Enter the AT of %d :",i+1);
        scanf("%d",&a[i]);
        //printf("%d",a[i]);
        printf("Enter the BT of %d :",i+1);
        scanf("%d",&b[i]);
        }
for(i=0;i<n-1;++i)
        for(j=i+1;j<n;++j)
                {if(a[i]>a[j])
                        {swap(&a[i],&a[j]);
                        swap(&b[i],&b[j]);
                        }
                }
for( i=0;i<n;++i)
        {w[i]=0;
        for(j=0;j<i;++j)
                w[i]+=b[j];
        w[i]=w[i]-a[i]+a[0];
        t[i]=w[i]+b[i];
        }
printf("Process \t Burst Time \t Arrival Time \t Waiting Time \t Turnaround Time\n");
for(i=0;i<n;++i)
        {printf("P%d \t \t %d \t \t %d \t \t %d \t \t %d \n",i+1,b[i],a[i],w[i],t[i]);
        sw+=w[i];
        st+=t[i];}
printf("Average waiting time is %f \nAverage turnaround time is %f \n",sw/n,st/n);
printf("GANT chart\n");
int *pid=(int*)malloc(n*sizeof(int));
int *finish=(int*)malloc(n*sizeof(int));
for(i=0;i<n;++i)
	{
	pid[i]=i;
	finish[i]=a[i]+b[i]+w[i];
	}
for(i=0;i<n-1;++i)
        for(j=i+1;j<n;++j)
                {if(finish[i]>finish[j])
                        {swap(&finish[i],&finish[j]);
                        swap(&pid[i],&pid[j]);
                        }
                }
for(i=0;i<n;++i)
{printf("P%d \t",pid[i]+1);
}
printf("\n");
for(i=0;i<n;++i)
{printf("%d \t",finish[i]);
}
printf("\n");


}
