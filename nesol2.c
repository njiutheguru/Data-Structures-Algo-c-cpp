#include <stdio.h>
#include <stdlib.h>

//Inserting a node in a new position
//steps

//create a new node
//traversal
//update the links 
 

struct node 
{
    int data;
    struct node *next;
};
void add_at_position(struct node *head, int pos, int data);
int main()
{

    struct node *head=(struct node *)malloc (sizeof (struct node));
    head->data=54;
    head->next=NULL;
    struct node *node2=(struct node *)malloc (sizeof (struct node));
    node2->data=43;
    node2->next=NULL;
    head->next=node2;
    struct node* node3=(struct node *)malloc (sizeof (struct node));
    node3->data=89;
    node3->next=NULL;
    node2->next=node3;
    struct node *node4=(struct node *)malloc (sizeof (struct node));
    node4->data=890;
    node4->next=NULL;
    node3->next=node4;
    struct node *node5=(struct node *)malloc (sizeof (struct node));
    node5->data=654;
    node5->next=NULL;
    node4->next=node5;
    struct node *ptr;
    int pos=1;
    int data=5545;
    //printf("ENter the Desired Position of The new node:");
   // scanf("%d",&pos);
   add_at_position(head, pos,data);
    ptr=head;

    while(ptr!=NULL)
    {
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }

    return 0;
}
void add_at_position(struct node *head, int pos, int data)
{
    struct node * newnode=(struct node *)malloc (sizeof (struct node));
    newnode->data=data;
    newnode->next=NULL;
    struct node *ptr;
    ptr=head;
    int i;
    printf("Enter the position of the new node: ");
    scanf("%d",&i);
    
    if(i==1)
    {
        
        newnode->data=head->data;
        newnode->next=head->next;
        head->data=data;
        head->next=newnode;
    }
    else{
    i=i-1;
    while( pos<i)
    {
        ptr=ptr->next;
        ++pos;
    }
    newnode->next=ptr->next;
    ptr->next=newnode;
    }
    //return ptr;

}