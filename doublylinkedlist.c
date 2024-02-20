#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


struct node 
{
    struct node *prev;
    int info;
    struct node *next;
    

};
struct node *createList(struct node *start);
 void displayList(struct node* start);
 struct node *insertIntheBeginning(struct node *start, int data);
 struct node *insertInEmptyList(struct node *start, int data);
 void insertAtEnd(struct node *start, int data);
 void insertAfter(struct node *start, int data , int x);
 struct node *insertBefore(struct node *start, int data , int x);
 struct node *deleteNode(struct node *start, int data);
 struct node *reverseList(struct node *start);

 int main()
 {
    int choice, data, x;
    struct node *start=NULL;
    start=createList(start);
    while(1)
    {
        printf("\n");
        printf("\n 1: Display List");
         printf("\n 2: Insert in an Empty List");
        printf("\n 3: Insert a Node in the Beginning of the list");
       
        printf("\n 4: Insert a node at the end of the list");
        printf("\n 5: Insert a node after a specified node");
        printf("\n 6: Insert a node before a specified node ");
        printf("\n 7: Delete a Node");
        printf("\n 8: Reverse the list \n");
        printf("9: quit");
        printf("\n Enter your choice: ");
        if(scanf("%d",&choice)==0)
        {
            printf(" You have entered a Wrong choice, please try again....");
            break;
        }
        if(choice==9)
        {
            exit(0);

        }
        switch(choice)
        {
            case 1:
                displayList(start);
                 break;
            case 2: 
                printf("\n Enter the element to be inserted:");
                scanf("%d",&data);
                start=insertInEmptyList(start, data);
                break;
            case 3: 
                printf("\n Enter the element to be inserted:");
                scanf("%d",&data);
                start=insertIntheBeginning(start, data);

                break;
            case 4:
                printf("\n Enter the element to be inserted:");
                scanf("%d",&data);
                insertAtEnd(start,data);
                break;
            case 5: 
                printf("\n Enter the element to be inserted:");
                scanf("%d",&data);
                printf("\n Enter the element after which to insert:");
                scanf("%d",&x);
                insertAfter(start, data, x);
                break;
            case 6:   
                printf("\n Enter the element to be inserted:");
                scanf("%d",&data);
                printf("\n Enter the element before which to Insert:");
                scanf("%d",&x);
                insertBefore(start, data, x);
                break;
            case 7: 
                printf("/n Enter the element to be deleted:");
                scanf("%d",&data);
                start=deleteNode(start, data);
                break;
            case 8: 
                start=reverseList(start);
                break;
            default:
                printf("\n Wrong Choice ...Please try again");

        }
    
         
    
    }




    return 0;
 }
 struct node *insertInEmptyList(struct node *start, int data)
 {
    struct node *temp=(struct node*)malloc (sizeof(struct node));
    temp->info=data;
    temp->prev= NULL;
    temp->next=NULL;
    start=temp;
    return start;

 }

 void insertAtEnd(struct node *start, int data)
 {
    struct node* p;
    struct node*temp=(struct node*)malloc(sizeof(struct node));
    temp->info=data;
    
    
    p=start;
    while(p->next !=NULL)
    {
        p=p->next;
    }
    p->next=temp;
    temp-> next=NULL;
    temp->prev=p;
 }
struct node *createList(struct node *start)
{
    int i,n,data;
    printf("\n Enter the number of nodes in the Doubly Linked List:");
    scanf("%d",&n);
    start=NULL;
    if(n==0)
    {
        return start;
       //printf("\n You cannot create a 0 doubly linked list..");
    }
    printf("\n Enter the first element to be inserted: ");
    scanf("%d",&data);
    start=insertInEmptyList(start, data);
    for(i=2;i<=n;i++)
    { 
        printf("\n Enter the %d element:",i);
        fflush(stdin);
        scanf("%d",&data);
        insertAtEnd(start,data);
    }
    return start;
}
 void displayList(struct node* start)
 {
    struct node *p;
    if(start==NULL)
    {
        printf("\n The list is Empty!");
        return;
    }
    
        p=start;
        printf("\n The list is >>> ");
        while(p!=NULL)
        {
            printf("\n %d",p->info);
            p=p->next;
        }
    
 }
 struct node *insertIntheBeginning(struct node *start, int data)
 {
    struct node *temp=(struct node*)malloc(sizeof(struct node));
     temp->info=data;
     temp->prev=NULL;
     temp->next=start;
     start->prev=temp;
     start=temp;
     return start;
 }
 
  
 void insertAfter(struct node *start, int data , int x)
 {
    struct node *temp=(struct node*) malloc (sizeof(struct node));
    struct node *p;
    
    temp->info=data;
    p=start;
    while(p!=NULL)
    {
        if(p->info==x)
        {
            break;
        }
        p=p->next;
    }
    if(p==NULL)
    {
        printf("\n %d not found in the list",x);
        
    }
    else
    {
        temp->prev=p;
        temp->next=p->next;
        if(p->next!=NULL)
        {
            p->next->prev=temp;
        }
        p->next=temp;
    }
 }
 struct node *insertBefore(struct node *start, int data , int x)
 {
    struct node *temp, *p;
    temp=(struct node*)malloc(sizeof(struct node));
    if(start==NULL)
    {
        printf("\n List is Empty");
        return start;
    }
    if(start->info=x)
    {
       // 
        temp->info=data;
        temp->prev=NULL;
        temp-> next=start;
        start->prev=temp;
        start=temp;
        return start;
    }
        
    p=start;
    while(p!=NULL)
 {
    if(p->info==x)
    {
        break;
    }
    p=p->next;
 }
 if(p==NULL)
 {
    printf("\n %d not present in the list ");
 }
 else{
    //temp=(struct node*)malloc(sizeof(struct node));
    temp->info=data;
    temp->prev=p->prev;
    p->prev->next=temp;
    p->prev=temp;
 }
 return start;
  } 
 struct node *deleteNode(struct node *start, int x)
 {
    struct node *temp;
    if(start==NULL)
    {
        printf("\n The  list is empty");
        return start;
    }
    if(start->next==NULL)
    {
        //here we are only dealing with one node
        if(start->info==x){
            temp=start;
            start=NULL;
            free(temp);
            return start;

        }
        else {
            printf("\n The element %d is not found in the list",x);
             return start;
        }
    }
        //Deletion of the first node in the lsit 
        if(start->info==x)
        {
            temp=start;
            start=start->next;
            start->prev=NULL;
            free(temp);
            return start; 

    
        }
        //deletion of nodes between 
        temp=start->next;
        while(temp->next!=NULL)
        {
            if(temp->info==x)
            {
                break;
            }
                temp=temp->next;
            
        }
        if(temp->next!=NULL)
        //node to be deleted is in between
        {
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            free(temp);
        }
        else
        {
            //this is when temp points to the last node
            if(temp->info==x)
            {
                temp->prev->next=NULL;
                free(temp);
            }
            else
        
        {
            printf("\n Element %d not found",x);
        }
    
        }
            return start;


    
 }
 struct node *reverseList(struct node *start)
 {
    struct node *p1, *p2;
    if(start==NULL)
    {
        return start;
    }
    p1=start;
    p2=p1->next;
    p1->next=NULL;
    p1->prev=p2;
    while(p2!=NULL)
    {
        p2->prev=p2->next;
        p2->next=p1;
        p1=p2;
        p2=p2->prev;
    }
    start=p1;
    return start;
 }