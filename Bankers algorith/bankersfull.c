#include<stdio.h>
#include<stdlib.h>
void print(int nr, int np,int matrix[][nr]){
    int i,j;
    for(i=0;i<np;++i){
        for(j=0;j<nr;++j){
            printf("%d ,",matrix[i][j]);
        }
    }
}
int safety(int nr,int np,int avail[],int alloc[][nr],int need[][nr]){
    int i,j,k,l,got_success,high_need,dead=0;
    int *safe=(int *)malloc(nr*sizeof(int));
    while(i<np){
        got_success=0;
        for(j=0;j<np;++j){
            high_need=0;
            for(k=0;k<nr;++k){
                if(need[j][k]>avail[k]){
                    high_need=1;
                    break;
                }    
            }
            if(high_need==0){
                got_success=1;
                safe[i++]=j;
                printf("%d ",j+1);
                for(l=0;l<nr;++l){
                    avail[l]+=alloc[j][l];
                    need[j][l]=100000;
                }
            }
        }
        if(got_success==0 && i!=np){
            dead=1;
            break;
        }
    }
    if(dead==1){
        printf("No safe sequence\n");
        return 0;
    }
    else{
        printf("Safe sequence is : <");
        for(i=0;i<np;++i){
            printf("%d,",safe[i]+1);
        }
        printf(">\n");
        return 1;
    }
}
int main(){
        int nr,np;
        int i,j,k,l;
        printf("Enter the number of resources :");
        scanf("%d",&nr);
        printf("Enter the number of processes :");
        scanf("%d",&np);
        int *resource = (int *)malloc(nr*sizeof(int));
        int *avail = (int *)malloc(nr*sizeof(int));
        int *alloc[np],*max[np],*need[np];
        printf("Enter the total number of each resource present: ");
        for(i=0;i<nr;++i){
            scanf("%d",&resource[i]);
            avail[i]=0;
        }
        for(i=0;i<np;++i){
            alloc[i]= (int*)malloc(nr*sizeof(int));
            max[i]= (int*)malloc(nr*sizeof(int));
            need[i]= (int*)malloc(nr*sizeof(int));
        }
        printf("Enter the Max matrix\n"); //input max matrix
        for(i=0;i<np;++i){
            printf("P%d\t",i+1);
            for(j=0;j<nr;++j){
                scanf("%d",&max[i][j]);
            }
        }
        printf("Enter the Allocation matrix\n"); //input allocation matrix
        for(i=0;i<np;++i){
            printf("P%d\t",i+1);
            for(j=0;j<nr;++j){
                scanf("%d",&alloc[i][j]);
                avail[j]+=alloc[i][j];
                need[i][j]=max[i][j]-alloc[i][j];
                if(need[i][j]<0){
                    printf("Error in allocation Matrix\n");
                    return 0;
                }
            }
        }
        for(i=0;i<nr;++i){      //making available resources
            avail[i]=resource[i]-avail[i];
            if(avail[i]<0){
                printf("Allocated more than available resourced\n");
                return 0;
            }
        }
        printf("Available resources are: ");
        for(i=0;i<nr;++i){
            printf("%d  ",avail[i]);
        }

        int got_success,high_need,dead=0;
    int *safe=(int *)malloc(nr*sizeof(int));
    i=0;
    while(i<np){
        got_success=0;
        for(j=0;j<np;++j){
            high_need=0;
            for(k=0;k<nr;++k){
                if(need[j][k]>avail[k]){
                    high_need=1;
                    break;
                }    
            }
            if(high_need==0){
                got_success=1;
                safe[i++]=j;
                printf("Got one \n");
                printf("%d ",j+1);
                for(l=0;l<nr;++l){
                    avail[l]+=alloc[j][l];
                    need[j][l]=100000;
                }
            }
        }
        if(got_success==0 && i!=np){
            dead=1;
            break;
        }
    }
    if(dead==1){
        printf("No safe sequence\n");
        return 0;
    }
    else{
        printf("Safe sequence is : <");
        for(i=0;i<np;++i){
            printf("%d,",safe[i]+1);
        }
        printf(">\n");
        return 1;
    }
        return 0;
}