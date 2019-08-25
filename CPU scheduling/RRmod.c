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
{int n,i,j,tq,temp,null=0,ct;
float sw=0,st=0;
printf("Enter the number of process\n");
scanf("%d",&n);
printf("Enter time quantum\n");
scanf("%d",&tq);
int *remb=(int*)malloc(n*sizeof(int));
int *b=(int*)malloc(n*sizeof(int));
int *w=(int*)malloc(n*sizeof(int));
int *t=(int*)malloc(n*sizeof(int));
int *a=(int*)malloc(n*sizeof(int));
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

ct=a[0];
for(i=0;i<n;++i)
        {
        remb[i]=b[i];
        }
int ghant[50],m=0,elem=0,ghantpos=0;
int time[50],point=0;
while(a[elem]<=ct)
{printf("###new process %d in GANT chart pos %d \n",elem+1,m+1);
ghant[m]=elem;
m++;
elem++;
}
i=0;
memset (w, 0, sizeof (int) * n);
do
//for(i=0;i<n;++i)
        {//printf("*");
	null=0;
        if(remb[i]==0)
                continue;
        else if(remb[i] >= tq && a[i]<=ct)
                {//printf("%d process bt >= tq",i+1);
                remb[i]=remb[i]-tq;
		temp=ct;
		ct=ct+tq;
		time[point++]=ct;
		//printf("remaining time is %d past time is %d currenttime %d\n",remb[i],temp,ct);
                for(j=0;j<n;++j)
                        {//printf("check for p%d with AT=%d RT=%d\n",j+1,a[j],remb[j]);
			if(a[j]<=temp)
                        	if(remb[j]!=0 && j!=i)
					{//printf("P%d is waiting for %d\n",j+1,tq);
                                	w[j]=w[j]+tq;
					}
				else
					{//printf("own process\n");
					}
			else if(a[j] < ct && a[j] > temp)
				 {//printf("entered inbetween arrived\n");
					if(remb[j]!=0 && j!=i)
                                       {
					 w[j]=w[j]+ct-a[j];
					//printf("P%d is waiting for %d\n",j+1,ct-a[j]);
					}
					else
					{//do nothing
					}
				}
			else
				{//do nothing
				}
                        }
		while(elem<n && a[elem]<=ct)
			{//printf("entered while loop to add new process\n");
			ghant[m]=elem;
			printf("###new process %d in GANT chart pos %d \n",elem+1,m+1);
			elem++;
			m++;
			}
		if(remb[i]!=0)
			{ghant[m]=i;
			printf("###old process %d again in GANT chart pos %d \n",i+1,m+1);
			m++;}
                }
        else
                {//printf("RT is less than tq \n ");
                temp=remb[i];
                remb[i]=0;
		ct=ct+temp;
		time[point++]=ct;
		//printf("remaining time is %d current time is %d pasttime %d\n",remb[i],ct,ct-temp);
                for(j=0;j<n;++j)
                        {if(a[j]<=(ct-temp))
                        	if(remb[j]!=0 && j!=i)
					{
                                	w[j]=w[j]+temp;
					}
			 else if(a[j]>(ct-temp) && a[j] < ct)
                                 if(remb[j]!=0 && j!=i)
                                        w[j]=w[j]+ct-a[j];
                        }
		   while(elem<n && a[elem]<=ct)
                        {printf("###new process %d in GANT chart pos %d \n",elem+1,m+1);
			ghant[m]=elem;
                        elem++;
                        m++;
                        }
		}
	ghantpos++;
	i=ghant[ghantpos];
	//printf("next iteration is for P%d\n",i+1);
        for(j=0;j<n;++j)
                if(remb[j]!=0)
                        {
                        null=1;
                        break;
                        }
        }
while(null);
for(i=0;i<n;++i)
        {t[i]=w[i]+b[i];
        }
printf("Process \t Burst Time \t Waiting Time \t Turnaround Time\n");
for(i=0;i<n;++i)
        {printf("P%d \t \t %d \t \t %d \t \t %d \n",i+1,b[i],w[i],t[i]);
        sw+=w[i];
        st+=t[i];}
printf("Average waiting time is %f \nAverage turnaround time is %f \n",sw/n,st/n);
printf("GANTT CHART\n\n");
for(i=0;i<point;++i)
	printf("P%d\t",ghant[i]+1);
printf("\n");
for(i=0;i<point;++i)
	printf("%d \t",time[i]);
printf("\n");
}

