#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct {
    char name[10];
    struct single *next;
}single;
typedef struct{
    char name[10];
    struct single *next;
    struct dir *down;
}dir;
void single_c(single *head,char filename[]){
    single *temp;
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    single *new = (single *)malloc(sizeof(single));
    strcpy(new->name,filename);
    new->next=NULL;
    temp->next=new;
}
void single_d(single *head,char filename[]){
    single *temp,*ptr;
    temp=head->next;
    ptr=head;
    while(temp!=NULL && strcmp(temp->name,filename)!=0){
        ptr=temp;
        temp=temp->next;
    }
    if(temp!=NULL && strcmp(temp->name ,filename)==0){
            ptr->next=temp->next;
            printf("File Deleted\n");
    }
    else if(temp==NULL)
    {
      printf("No such File\n");  
    }
    
}
void single_dis(single *head){
    single *ptr = head->next;
    printf("-------------------------------------------------------------\n");
    while(ptr!=NULL){   
        printf("|\t%s\t",ptr->name);
        ptr=ptr->next;
    }
    printf("|\n");
    printf("--------------------------------------------------------------\n");
}
void single_s(single *head,char filename[]){
    single *temp,*ptr;
    temp=head->next;
    ptr=head;
    while(temp!=NULL && strcmp(temp->name,filename)!=0){
        ptr=temp;
        temp=temp->next;
    }
    if(temp!=NULL && strcmp(temp->name , filename)==0){
            printf("File Present\n");
    }
    else if(temp==NULL)
    {
      printf("No such File\n");  
    }
    
}
int single_level(){
    int choice,a;
    char b[10],filename[10];
    single *new =(single *)malloc(sizeof(single));
    strcpy(new->name,b);
    new->next = NULL;
    single *head;
    head = new;
    while(1){
        printf("1. Create File\n2. Delete File\n3. Search File\n4. Display Files\n5. Exit\nEnter your choice: ");
        scanf("%d",&choice);
        switch (choice){
            case 1:printf("Enter the file name: ");
                   scanf("%s",filename);
                   single_c(head,filename);
                   break;
            case 2:printf("Enter the file name: ");
                   scanf("%s",filename);
                   single_d(head,filename);
                   break;
            case 3:printf("Enter the file name: ");
                   scanf("%s",filename);
                   single_s(head,filename);
                   break;
            case 4:single_dis(head);
                   break;
            case 5:return 0;
        }
    }
    return 0;
}
dir * two_dir(dir *twohead,char filename[]){
    dir *new=(dir*)malloc(sizeof(dir));
    new->down=NULL;
    new->next=NULL;
    dir *ptr=twohead;
    strcpy(new->name,filename);
    if(twohead==NULL){
        //printf("First directory\n");
        twohead=new;
    }
    else{
        //printf("second time\n");
        while(ptr->next!=NULL)
            ptr=ptr->next;
        ptr->next=new;
    }
    return twohead;
}
dir * two_c(dir *head,char direc[],char filename[]){
    dir *temp,*ptr;
    temp=head;
    single *ptr1,ptr2;
    single *new=(single *)malloc(sizeof(single));
    strcpy(new->name,filename);
    new->next=NULL;
    while(temp!=NULL && strcmp(temp->name,direc)!=0){
        ptr=temp;
        temp=temp->next;
    }
    if(temp!=NULL && strcmp(temp->name , direc)==0){
            printf("Directory Present\n");
            ptr1=temp->down;
            if(ptr1==NULL)
                temp->down=new;
            else{
                while(ptr1->next!=NULL){
                    ptr1=ptr1->next;
                }
                ptr1->next=new;
            }

    }
    else if(temp==NULL)
    {
      printf("No such Directory\n");  
    }
    return head;
}
dir * two_d(dir *head,char direc[],char filename[]){
    dir *ptr=head;
    single *ptr1,*ptr2=NULL;
    while(ptr!=NULL && strcmp(ptr->name,direc)!=0)
        ptr=ptr->next;
    if(ptr==NULL)
        printf("No Such Directory\n");
    else{
        ptr1=ptr->down;
        while(ptr1!=NULL && strcmp(ptr1->name,filename)!=0){
            ptr2=ptr1;
            ptr1=ptr1->next;
        }
        if(ptr1==NULL)
            printf("No such File\n");
        else if(ptr2==NULL){
            ptr->down=NULL;
        }
        else{
            printf("File Deleted\n");
            ptr2->next=ptr1->next;
        }
    }
    return head;
}
void two_s(dir *head,char direc[],char filename[]){
    dir *ptr=head;
    single *ptr1,*ptr2=NULL;
    while(ptr!=NULL && strcmp(ptr->name,direc)!=0)
        ptr=ptr->next;
    if(ptr==NULL)
        printf("No Such Directory\n");
    else{
        ptr1=ptr->down;
        while(ptr1!=NULL && strcmp(ptr1->name,filename)!=0){
            ptr2=ptr1;
            ptr1=ptr1->next;
        }
        if(ptr1==NULL)
            printf("No such File\n");
        else{
            printf("File Present\n");
        }
    }
}
void two_dis(dir *head){
    single *ptr;
    dir *main=head;
    if(main==NULL)
        printf("Empty\n");
    while(main!=NULL){
        printf("%s\t",main->name);
        ptr=main->down;
        while(ptr!=NULL){
            printf("%s  ",ptr->name);
            ptr=ptr->next;
        }
        printf("\n");
        main=main->next;
    }

}
int two_level(){
    int choice,a;
    char direc[10],filename[10];
    dir *twohead = NULL;
    while(1){
        printf("1. Create Directory\n2. Create File\n3. Delete File\n4. Search File\n5. Display Files\n6. Exit\nEnter your choice: ");
        scanf("%d",&choice);
        switch (choice){
            case 1:printf("Enter the Directory name: ");
                   scanf("%s",filename);
                   twohead = two_dir(twohead,filename);
                   break;
            case 2:printf("Enter the Directory name: ");
                   scanf("%s",direc);
                   printf("Enter the filename: ");
                   scanf("%s",filename);
                   twohead = two_c(twohead,direc,filename);
                   break;
            case 3:printf("Enter the Directory name: ");
                   scanf("%s",direc);
                   printf("Enter the file name: ");
                   scanf("%s",filename);
                   twohead = two_d(twohead,direc,filename);
                   break;
            case 4:printf("Enter the Directory name: ");
                   scanf("%s",direc);
                   printf("Enter the file name: ");
                   scanf("%s",filename);
                   two_s(twohead,direc,filename);
                   break;
            case 5:two_dis(twohead);
                   break;
            case 6:return 0;
        }
    }
    return 0;
}
void inorder(dir *root,int count){
    int i;
	if(root!=NULL){
		while(root!=NULL){
            for(i=0;i<count;++i)
                printf("\t");
            printf("%s",root->name);
            if (root->down!=NULL){
                printf("\n");
                inorder(root->down,count+1);
            }
            root=root->next;
            printf("\n");
        }
	}
}
dir * create_dir(dir *head,char filedir[]){
    int i,num,choice ;
    char name[10];
    dir *ptr=head;
    dir *new=(dir *)malloc(sizeof(dir));
        strcpy(new->name,filedir);
        new->next=NULL;
        new->down=NULL;
    if(head==NULL){
        head=new;
        ptr=head;
    }
    else{
        while(ptr->next!=NULL)
            ptr=ptr->next;
        ptr->next=new;
        ptr=new;
    }
    printf("Enter 1 for Dir,2 for file: ");
    scanf("%d",&choice);
    if(choice==1){
        printf("Enter the number of SubDir/file under %s: ",filedir);
        scanf("%d",&num);
        for(i=0;i<num;++i){
            printf("Enter the name of file/Directory (under %s) : ",filedir);
            scanf("%s",name);
            ptr->down=create_dir(ptr->down,name);
        }
    }
    else if(choice==2){
        /*No idea what to do*/
    }
    return head;
}
int hierarchial(){
    int choice,num;
    dir *root =NULL;
    char filedir[10];
    while(1){
        printf("Enter the file/Dir under root: ");
        scanf("%s",filedir);
        root = create_dir(root,filedir);
        printf("1. to continue 2.to Exit\n");
        scanf("%d",&choice);
        if(choice==2)
            inorder(root,0);
            break;
    }
    return 0;
}
int main(){
    int choice,chumma;
    printf("1 Single level Directory\n2 Two-level Directory\n3 Hierarchial Directory\n4 Exit\nEnter your coice: ");
    scanf("%d",&choice);
    switch (choice){
        case 1:chumma = single_level();
               break;
        case 2:chumma = two_level();
               break;
        case 3:chumma = hierarchial();
               break;
        case 4:return 0;
    }
    return 0;
}