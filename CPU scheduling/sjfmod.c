#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b)
{int temp;
temp=*a;
*a=*b;
*b=temp;
}
void main()
{int n,i,j,ct=0,null,oldct,smallb,foundb,index;
float sw=0,st=0;
printf("Enter the number of process : ");
scanf("%d",&n);
int *a=(int*)malloc(n*sizeof(int));
int *b=(int*)malloc(n*sizeof(int));
int *w=(int*)malloc(n*sizeof(int));
int *t=(int*)malloc(n*sizeof(int));
int *remb=(int*)malloc(n*sizeof(int));
for( i=0;i<n;++i)
        {printf("Enter the AT of %d :",i+1);
        scanf("%d",&a[i]);
        printf("Enter the BT of %d :",i+1);
        scanf("%d",&b[i]);
	remb[i]=b[i];
	w[i]=0;
        }
for(i=0;i<n-1;++i)
        for(j=i+1;j<n;++j)
                {if(a[i]>a[j])
                        {swap(&b[i],&b[j]);
			swap(&a[i],&a[j]);
                        }
		else if(a[i]==a[j] && b[i] > b[j])
			{
			swap(&b[i],&b[j]);
                        swap(&a[i],&a[j]);
			}
                }
for(i=0;i<n;++i)
	printf("P%d - AT :%d BT :%d \n",i+1,a[i],b[i]);
ct=a[0];
null=n;
do
{//null=0;
foundb=0;
for(i=0;a[i]<=ct;++i)
	{
	if(foundb==0 && remb[i]!=0)
		{
		smallb=b[i];
		index=i;
		foundb=1;
		}
	else if(remb[i]!=0 && smallb>b[i])
		{
		smallb=b[i];
		index=i;
		}
	}

	oldct=ct;
	ct+=b[index];
	remb[index]=0;
		for(j=0;j<n;++j)
			if(a[j]<=ct && index!=j && remb[j]!=0)
				{
				if(a[j]<=oldct)
					w[j]+=b[index];
				else
					w[j]+=ct-a[j];
				}
/*for(j=0;j<n;++j)
	if(remb[j]!=0)
		{
		null=1;
		break;
		}
*/
null--;
}
while(null>0);

printf("Process \t Arrival Time \t Burst Time  \t Waiting Time \t Turnaround Time\n");
for(i=0;i<n;++i)
        {t[i]=w[i]+b[i];
	printf("P%d \t \t %d \t \t %d \t \t %d \t \t %d \n",i+1,a[i],b[i],w[i],t[i]);
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

