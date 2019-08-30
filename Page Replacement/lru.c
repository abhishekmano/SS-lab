#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main(){
    int n,i,num,nreq,pos=0,pagefault=0,k,j;
    printf("Enter the number of page frames: ");
    scanf("%d",&n);
    printf("Enter the total number of pages: ");
    scanf("%d",&num);
    int *page=(int *)malloc(n*sizeof(int));
    int *present=(int *)malloc(num*sizeof(int)); //to make searching faster
    memset(present, -1, num*sizeof(int));
    printf("Enter the number of request: ");
    scanf("%d",&nreq);
    int *req =(int *)malloc(nreq*sizeof(int));
    printf("Enter the reuest: ");
    for(i=0;i<nreq;++i)
        scanf("%d",&req[i]);
    for(i=0;i<nreq;++i){
        if(present[req[i]]>=0){ //if page already present
            printf("%d Already present\n",req[i]);
            for(j=present[req[i]];j<n-1;++j){
               page[j]=page[j+1];
               present[page[j]]--;
            }
            page[n-1]=req[i];
            present[req[i]]=n-1;
            printf("-------------------------current page ");
            for(k=0;k<n;++k){
                printf("%d  ",page[k]);
            }
            printf("\n");
            /*
            printf("------current pos ");
            for(k=0;k<num;++k){
                printf("%d  ",present[k]);
            }
            printf("\n");
            */

        }
        else if(pos < 3){   //if page is absent but free page frame available
            printf("%d added\n",req[i]);
            present[req[i]]=pos;
            page[pos]=req[i];
            pos++;
            pagefault++;
            printf("-------------------------current page ");
            for(k=0;k<n;++k){
                printf("%d  ",page[k]);
            }
            printf("\n");
            /*
            printf("------current pos ");
            for(k=0;k<num;++k){
                printf("%d  ",present[k]);
            }
            printf("\n");
            */
        }
        else{               //page absent and no free page frame
            printf("%d removed and %d added\n",page[0],req[i]);
            present[page[0]]--;
            for(j=0;j<n-1;++j){
                page[j]=page[j+1];
                present[page[j]]--;
            }
            page[n-1]=req[i];
            present[req[i]]=n-1;
            pagefault++;
            printf("-------------------------current page :");
            for(k=0;k<n;++k){
                printf("%d  ",page[k]);
            }
            printf("\n");
            /*
            printf("------current pos ");
            for(k=0;k<num;++k){
                printf("%d  ",present[k]);
            }
            printf("\n");
            */
        }
    }
    printf("Total number of page fault is %d\n",pagefault);
}