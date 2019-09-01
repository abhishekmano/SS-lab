#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b){
        int temp;
        temp=*a;
        *a=*b;
        *b=temp;
}
float fcfs(int n,int init,int req[]){
float total=0;
int i;
for(i=0;i<n;++i){
                if(req[i]<=init){
                        total+=init-req[i];
                        printf("Move from\t%d\tto\t%d\twith seek %d\n",init,req[i],init-req[i]);
                }
                else{
                        total+=req[i]-init;
                        printf("Move from\t%d\tto\t%d\twith seek %d\n",init,req[i],req[i]-init);
                }
                init=req[i];
        }

        printf("***Total seek time is %f ***\n",total);
        printf("***Average seek time is %f ***\n",total/n);
        return total;
}
float sstf(int n,int init,int size,int req[]){
	int min,i,maxex=0,minex=0,count=n,least,max;
	float total=0;
	for(min=0;req[min]<=init &&  min < n;++min);
        //printf("%d",req[min]);
        min--;
	max=min+1;
	while(count > 0 ){
		if(max >= n){
			maxex=1;
			break;
		}
		if(min < 0){
			minex=1;
			break;
		}
		least=init-req[min];
		if(least > (req[max]-init)){
			total+=req[max]-init;
			//printf("inside while max side");
                        printf("Move from\t%d\tto\t%d\twith seek %d\n",init,req[max],req[max]-init);
			init=req[max];
			max++;
			count--;
		}
		else{
			total+=init-req[min];
			//printf("inside while minside");
                        printf("Move from\t%d\tto\t%d\twith seek %d\n",init,req[min],init-req[min]);
                        init=req[min];
                        min--;
                        count--;
		}
	}
	if(maxex==1)
		for(i=min;i>=0;--i){
			total+=init-req[i];
                        printf("Move from\t%d\tto\t%d\twith seek %d\n",init,req[i],init-req[i]);
	                init=req[i];
		}
		if(minex==1)
			for(i=max;i<n;++i){
				total+=req[i]-init;
	                        printf("Move from\t%d\tto\t%d\twith seek %d\n",init,req[i],req[i]-init);
        	                init=req[i];
				}
		printf("***Total seek time is %f ***\n",total);
        	printf("***Average seek time is %f ***\n",total/n);
		return total;
	}
float scan(int n,int init,int size,int req[]){
        int min=0,i;
        float total=0;
        for(min=0;req[min]<init &&  min < n;min++);
        //printf("%d",req[min]);
        for(i=min;i<n;++i){
                total+=req[i]-init;
                printf("Move from\t%d\tto\t%d\twith seek %d\n",init,req[i],req[i]-init);
                init=req[i];
        }
	 if(min == 0)
                return total;
        if(init!=size-1){
                printf("Move from\t%d\tto\t%d\twith seek %d\n",init,size-1,size-1-init);
                total+=size-1-init;
                init=size-1;
        }
	if( min-1 >=0 )
                for(i=(min-1);i>=0;--i){
                        total+=init-req[i];
                        printf("Move from\t%d\tto\t%d\twith seek %d\n",init,req[i],init-req[i]);
                        init=req[i];
                }

        printf("***Total seek time is %f*** \n",total);
        printf("***Average seek time is %f*** \n",total/n);
        return total;
}
float cscan(int n,int init,int size,int req[]){
        int min=0,i;
        float total=0;
        for(min=0;req[min]<init &&  min < n;min++);
        //printf("%d",req[min]);
        for(i=min;i<n;++i){
                total+=req[i]-init;
                printf("Move from\t%d\tto\t%d\twith seek %d\n",init,req[i],req[i]-init);
                init=req[i];
        }
	if(min == 0)
                return total;
        if(init!=size-1){
                printf("Move from\t%d\tto\t%d\twith seek %d\n",init,size-1,size-1-init);
                total+=size-1-init;
                init=size-1;
        }
        printf("Move from\t%d\tto\t0\twith seek %d\n",size-1,size-1);
        init=0;
        total+=size-1;
        for(i=0;i<min;++i){
                total+=req[i]-init;
                printf("Move from\t%d\tto\t%d\twith seek %d\n",init,req[i],req[i]-init);
                init=req[i];
        }

        printf("***Total seek time is %f*** \n",total);
        printf("***Average seek time is %f*** \n",total/n);
        return total;
}
float look(int n,int init,int size,int req[]){
        int min=0,i;
        float total=0;
        for(min=0;req[min]<init &&  min < n;min++);
        //printf("%d",req[min]);
        for(i=min;i<n;++i){
                total+=req[i]-init;
                printf("Move from\t%d\tto\t%d\twith seek %d\n",init,req[i],req[i]-init);
                init=req[i];
        }
	 if(min == 0)
                return total;
	if( min-1 >=0 )
                for(i=(min-1);i>=0;--i){
                        total+=init-req[i];
                        printf("Move from\t%d\tto\t%d\twith seek %d\n",init,req[i],init-req[i]);
                        init=req[i];
                }

        printf("***Total seek time is %f*** \n",total);
        printf("***Average seek time is %f*** \n",total/n);
        return total;
        }
float clook(int n,int init,int size,int req[]){
        int min=0,i;
        float total=0;
        for(min=0;req[min]<init &&  min < n;min++);
        //printf("%d",req[min]);
        for(i=min;i<n;++i){
                total+=req[i]-init;
                printf("Move from\t%d\tto\t%d\twith seek %d\n",init,req[i],req[i]-init);
                init=req[i];
        }
	if(min == 0)
                return total;
        for(i=0;i<min;++i){
                if(i!=0){
                        total+=req[i]-init;
                        printf("Move from\t%d\tto\t%d\twith seek %d\n",init,req[i],req[i]-init);
                }
                else{
                        total+=init-req[i];
                        printf("Move from\t%d\tto\t%d\twith seek %d\n",init,req[i],init-req[i]);
                }
                init=req[i];
        }

        printf("***Total seek time is %f*** \n",total);
        printf("***Average seek time is %f*** \n",total/n);
        return total;
}

int main(){
        int size,init,n,pos,i,j,dir;
        float total=0;

        printf("Enter the Disk size: ");
        scanf("%d",&size);
        printf("Enter the initial head position: ");
        scanf("%d",&init);
        pos=init;
        printf("Enter the number of requests: ");
        scanf("%d",&n);

        int *req=(int *)malloc(n*sizeof(int));
        printf("Enter the request\n");
        for(i=0;i<n;++i){
                scanf("%d",&req[i]);
                if(req[i]>=size || req[i]<0){
                        printf("are you dumb\n");
                        return 0;
                        break;
                }
        }
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~FCFS~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        float tfcfs = fcfs(n,init,req);     ////////////
                for(i=0;i<n-1;++i)
                        for(int j=i;j<n;++j)
                                if(req[i]>req[j])
                                        swap(&req[i],&req[j]);
        
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~SSTF~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        float tsstf = sstf(n,init,size,req);             //////////////

        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~SCAN~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	float tscan = scan(n,init,size,req);     //////////////


        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~C-SCAN~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	float tcscan= cscan(n,init,size,req);  		 //////////////


        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~LOOK~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        float tlook = look(n,init,size,req);    //////////////


        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~C-LOOK~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        float tclook = clook(n,init,size,req);   //////////////
        int arr[6];
        arr[0]=(int)tfcfs;
        arr[1]=(int)tscan;
        arr[2]=(int)tcscan;
        arr[3]=(int)tlook;
        arr[4]=(int)tclook;
        arr[5]=(int)tsstf;
        for(i=0;i<5;++i)
	        for(j=i+1;j<6;++j)
		        if(arr[i]>arr[j])
			        swap(&arr[i],&arr[j]);
        if(arr[0]==tfcfs)
	        printf("FCFS is the optimal With total seek time %f Average seek time %f\n",tfcfs,tfcfs/n);
        else if(arr[0]==tscan)
	        printf("SCAN is the optimal With seek time %f Average seek time %f\n",tscan,tscan/n);
        else if(arr[0]==tcscan)
                printf("C-SCAN is the optimal With seek time %f Average seek time %f\n",tcscan,tcscan/n);
        else if(arr[0]==tlook)
                printf("LOOK is the optimal With seek time %f Average seek time %f\n",tlook,tlook/n);
        else if(arr[0]==tclook)
                printf("C-LOOK is the optimal With seek time %f Average seek time %f\n",tclook,tclook/n);
        else if(arr[0]==tsstf)
                printf("SSTF is the optimal With seek time %f Average seek time %f\n",tsstf,tsstf/n);

        return 0;
        }
