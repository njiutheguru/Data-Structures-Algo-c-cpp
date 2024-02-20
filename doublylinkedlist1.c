#include <stdio.h>
#include <stdlib.h>

struct node 
{
    struct node*prev;
    int data;
    struct node*next;
};
void insert_in_empty_list(struct node **headptr, int data);
struct node *insertatend(struct node *headptr, int dataele);
struct node* insert(struct node *headptr, int data, int pos, int i);
int main()
{

    struct node* headptr=NULL;

    int data,nodes,dataele,i=0;
    int pos;
    printf("Enter data: ");
    scanf("%d",&data);
    insert_in_empty_list(&headptr, data);
    printf("\n");
    printf("Enter the number of Nodes to add in the list: ");
    scanf("%d",&nodes);
    while( i<nodes)
    {
    printf("Enter data element %d: ",i+1);
    scanf("%d",&dataele);
    headptr=insertatend(headptr,dataele);
    i++;
    } 
    printf("\n");

    
    if(headptr==NULL)
    {
        printf("\n %d",headptr->data);
    }
    struct node *ptr;
    struct node *ptr1;
    struct node *ptr2;
    ptr1=headptr;
     while( ptr1!=NULL )
    {
    printf("\n %d",ptr1->data);
    ptr1=ptr1->next;
    
    }
   
    //insert before and inserting after a certain node 
    printf("\n Enter the position BEFORE which to enter:");
    scanf("%d",&pos);
    printf(" \n Enter the data to insert:");
    scanf("%d",&data);
    //the insert before and insert after have been merged into one function with some change in the pos
        //insert before
         i=2;
    insert(headptr, data,pos,i);
    printf("\n Before insertion:");
    ptr2=headptr;
     while( ptr2!=NULL )
    {
    printf("\n %d",ptr2->data);
    ptr2=ptr2->next;
    
    }
    
    //inserting after a certain node
  
    printf("\n Enter the position AFTER which to enter:");
    scanf("%d",&pos);
    printf(" \n Enter the data to insert:");
    scanf("%d",&data);
    i=1;
   headptr=insert(headptr,data,pos,i);
   
    printf("\n After Insertion:\n");
    ptr=headptr;
    while( ptr!=NULL )
    {
    printf("\n %d",ptr->data);
    ptr=ptr->next;
    
    }
    return  0;
}
void insert_in_empty_list(struct node **headptr, int data)
{

    struct node *node1=(struct node*)malloc(sizeof(struct node));

     node1->data=data;
    node1->prev=NULL;
    node1->next=NULL;
    *headptr=node1;
    
}
struct node *insertatend(struct node *headptr, int dataele)
{
    struct node *node1=(struct node*)malloc(sizeof(struct node));
    
    struct node *ptr;
    ptr=headptr;
   
    if(ptr->next==NULL)
    {
         node1->data=dataele;
     node1->next=NULL;
        ptr->next=node1;
        node1->prev=ptr;
       
    }
    else
        {  
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
             node1->data=dataele;
            node1->next=NULL;
            ptr->next=node1;
            node1->prev=ptr;
        }
    return headptr;
}

struct node* insert(struct node *headptr, int data, int pos, int i)
{

    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    struct node *ptr;
    ptr=headptr;
    while(ptr->next!=NULL)
    {
        if(i==pos)
        {
            break;
        }
        ptr=ptr->next;
        pos--;
    }
    temp->next=ptr->next;
    temp->prev=ptr;
    ptr->next->prev=temp;
    ptr->next=temp;
    return headptr;

}