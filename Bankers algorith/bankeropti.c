#include <stdio.h>
#include <stdlib.h>
void main(){
        //taking required inputs from user
        int i,j,nr,np;
        printf("Enter the number of resources:");
        scanf("%d",&nr);
        printf("Enter the total number of each resource:");
        int *res=(int *)malloc(nr*sizeof(int));
        int *left=(int *)malloc(nr*sizeof(int));
        for(i=0;i<nr;++i){
                scanf("%d",&res[i]);
                left[i]=0;
                }
        printf("Enter the number of Processes:");
        scanf("%d",&np);
        int *alloc[np],*need[np],*max[np];
        for(i=0;i<np;++i){
                alloc[i]=(int*)malloc(nr*sizeof(int));
                max[i]=(int*)malloc(nr*sizeof(int));
                need[i]=(int*)malloc(nr*sizeof(int));
                }
        printf("Enter the Allocation matrix\n");
        for(i=0;i<np;++i){
                printf("P%d\t",i);
                for(j=0;j<nr;++j){
                        scanf("%d",&alloc[i][j]);
                        left[j]+=alloc[i][j];
                        }
                }
        for(i=0;i<nr;++i){
                left[i]=res[i]-left[i];  //flipping the array
                }
        printf("Enter the Max matrix\n");
        for(i=0;i<np;++i){
                printf("P%d\t",i);
                for(j=0;j<nr;++j){
                        scanf("%d",&max[i][j]);
                        need[i][j]=max[i][j]-alloc[i][j]; //resources that is needed to complete the process
                        }
                }
        //All required arrays are initialized
        int *comp=(int*)malloc(np*sizeof(int));
        int flag=0,k,foundp,l,gotatleast=0;
        i=0;
        while(i<np){
		gotatleast=0;
                for(j=0;j<np;++j){
                        foundp=1;
                        for(k=0;k<nr;++k)
                                if(need[j][k]>left[k]){
                                        foundp=0;
                                        break;
                                        }
                        if(foundp==1){
				gotatleast=1;
                                comp[i++]=j;
                                for(l=0;l<nr;++l){
                                        left[l]+=alloc[j][l];
                                        need[j][l]=10000;   //large value just to make sure it wont be selected again
                                        }
                                }
                        }
                if(gotatleast==0 && i!=np){
                        flag=1;
                        break;
                        }
                }
        if(flag==1){
                printf("No safe sequence deadlock present\n");
                }
        else{
                printf("------Safe Sequence is------\n <\t");
                for(i=0;i<np;++i)
                        printf("P%d\t",comp[i]);
                printf(">\n");
                }
        printf("\n");
}

