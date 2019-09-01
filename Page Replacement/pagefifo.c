#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main(){
    int n,i,num,nreq,pos=0,pagefault=0,j;
    printf("Enter the number of page frames: ");
    scanf("%d",&n);
    printf("Enter the total number of pages: ");
    scanf("%d",&num);
    int *page=(int *)malloc(n*sizeof(int));
    int *present=(int *)malloc(num*sizeof(int)); //to make searching faster
    memset(present, 0, num*sizeof(int));
    printf("Enter the number of request: ");
    scanf("%d",&nreq);
    int *req =(int *)malloc(nreq*sizeof(int));
    printf("Enter the request: ");
    for(i=0;i<nreq;++i)
        scanf("%d",&req[i]);
    for(i=0;i<nreq;++i){
        if(present[req[i]]==1){ //if page already present
            printf("%d Already present\n",req[i]);
	    printf("------------------------Current page :");
	    if(pos < n){
		for(j=0;j< pos;++j)
			printf("%d    ",page[j]);
	    }
	    else{
		 for(j=0;j< n;++j)
                        printf("%d    ",page[j]);
	    }
	    printf("\n");
            continue;
        }
        else if(pos < n){   //if page is absent but free page frame available
            printf("%d added\n",req[i]);
            present[req[i]]=1;
            page[pos]=req[i];
            pos++;
            pagefault++;
	    printf("------------------------Current page :");
	    for(j=0;j< pos;++j)
                        printf("%d    ",page[j]);
	    printf("\n");
        }
        else{               //page absent and no free page frame
            printf("%d removed and %d added\n",page[0],req[i]);
            present[page[0]]=0;
            for(j=0;j<n-1;++j){
                page[j]=page[j+1];
            }
            page[n-1]=req[i];
            present[req[i]]=1;
            pagefault++;
	    printf("------------------------Current page :");
       	    for(j=0;j< n;++j)
                        printf("%d    ",page[j]);
	    printf("\n");
        }
    }
    printf("Total number of page fault is %d\n",pagefault);
}
