#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void swap(int *a,int *b)
{int temp;
temp=*a;
*a=*b;
*b=temp;
}
void main()
{int n,i,j,tq,temp,null=0;
float sw=0,st=0;
printf("Enter the number of process\n");
scanf("%d",&n);
printf("Enter time quantum\n");
scanf("%d",&tq);
int *remb=(int*)malloc(n*sizeof(int));
int *b=(int*)malloc(n*sizeof(int));
int *w=(int*)malloc(n*sizeof(int));
int *t=(int*)malloc(n*sizeof(int));
for( i=0;i<n;++i)
        {//printf("Enter the AT of %d :",i+1);
        //scanf("%d",&a[i]);
        //printf("%d",a[i]);
        printf("Enter the BT of %d :",i+1);
        scanf("%d",&b[i]);
        }
for(i=0;i<n;++i)
	{
	//printf("%d\n",b[i]);
	remb[i]=b[i];
	}

memset (w, 0, sizeof (int) * n);
do
for(i=0;i<n;++i)
	{null=0;
	if(remb[i]==0)
		continue;
	else if(remb[i] >= tq)
		{printf("P%d |",i+1);
		remb[i]=remb[i]-tq;
		for(j=0;j<n;++j)
			{
			if(remb[j]!=0 && j!=i)
				w[j]=w[j]+tq;
			}
		}
	else
		{printf("P%d |",i+1);
		temp=remb[i];
		remb[i]=0;
		for(j=0;j<n;++j)
                        {
                        if(remb[j]!=0 && j!=i)
                                w[j]=w[j]+temp;
                        }

		}
	for(j=0;j<n;++j)
		if(remb[j]!=0)
			{
			null=1;
			break;
			}
	}
while(null);
printf("\n");
for(i=0;i<n;++i)
	{t[i]=w[i]+b[i];
	}
printf("Process \t Burst Time \t Waiting Time \t Turnaround Time\n");
for(i=0;i<n;++i)
        {printf("P%d \t \t %d \t \t %d \t \t %d \n",i+1,b[i],w[i],t[i]);
        sw+=w[i];
        st+=t[i];}
printf("Average waiting time is %f \n Average turnaround time is %f \n",sw/n,st/n);

}
