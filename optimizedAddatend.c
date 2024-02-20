#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;

};
struct node* addattheEnd(struct node * ptr, int data);
int main()
{
    struct node *node1= (struct node *) malloc(sizeof(struct node));
    node1->data=145;
    node1->next=NULL;
   
    struct node *ptr;
    ptr=node1;
//this is to keep the ptr always pointing at the last node in the linked list 
//the ptr now stores the temp node returned by the addattheend function  which is the last node in the linked list 
//Hence this ptr should be differnt from the node1.
    ptr=addattheEnd(ptr,45);
    ptr=addattheEnd(ptr,-66);
    ptr=addattheEnd(ptr, -665);
    ptr=node1;
    if(ptr==NULL)
    {
        printf("\n The linked list is empty\n");
    }
    //ptr=node1;
    while(ptr!=NULL)
    {
        printf("\n %d ",ptr->data);
        ptr=ptr->next;

    }
    
    printf("\n");
//Time complexity is O(1) -> the fastest type of running algorithm.

    return 0;
}
//program code to add at the end of the function 


    //in this design the linked list takes big onf (n) but can be optimized to take the big(o) of 1
    struct node* addattheEnd(struct node * ptr, int data)
    {
        struct node * temp=(struct node *) malloc(sizeof(struct node));
        temp->data=data;
        temp->next=NULL;
        ptr->next=temp;
        return temp;
    }
