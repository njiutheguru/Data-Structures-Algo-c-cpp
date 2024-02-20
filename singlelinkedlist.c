#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;

};
void AddattheEnd(struct node * head, int data);
int main()
{
    struct node *node1= (struct node *) malloc(sizeof(struct node));
    node1->data=45;
    node1->next=NULL;
    struct node *node2= (struct node *) malloc(sizeof(struct node));
    node2->data=22;
    node2->next=NULL;
    node1->next=node2;
    printf("\n The linked list printed is >>>\t\t");
     //printf("%d,%d,", node1->data,node2->data);
    //creating the third linked list
    node2= (struct node *) malloc(sizeof(struct node));
    node2->data=-65;
    node2->next=NULL;
    node1->next->next=node2;
    //printf("%d", node2->data);
    printf("\n Enter the number of Nodes to add to the linked list  >>>");
 unsigned int count,numbertoadd;
 scanf("%d",&count);
    for(int i=1; i<=count; i++)
    {
        printf(" Enter Number %d: ", i);
        scanf("%d",&numbertoadd);

        AddattheEnd(node1, numbertoadd);
    }
    
    //AddattheEnd(node1,-98);
    //AddattheEnd(node1,-66);
    struct node *ptr;
    if(ptr==NULL)
    {
        printf("\n The linked list is empty\n");
    }
    ptr=node1;
    while(ptr!=NULL)
    {
        printf("\n %d ",ptr->data);
        ptr=ptr->next;

    }
    
    printf("\n");


    return 0;
}
//program code to add at the end of the function 

void AddattheEnd(struct node * head, int data)
{
    struct node * ptr,*temp;
    ptr=head;
    temp=(struct node *) malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=temp;
    //in this design the linked list takes big onf (n) but can be optimized to take the big(o) of 1
    
}