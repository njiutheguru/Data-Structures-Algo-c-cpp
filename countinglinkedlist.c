#include <stdio.h>
#include <stdlib.h>



struct node
{
    int data;
    struct node* link;
    

};
void AddattheEnd(struct node * head, int data);
struct node* reverse(struct node* head);



int main()


{
    struct node* head;
    head= (struct node *) malloc(sizeof(struct node));
   head->data= 0;
    head->link=NULL;

    printf("\n I am a HERO\n");
     printf("\n Enter the number of Nodes to add to the linked list  >>>");
 unsigned int count,numbertoadd;
 scanf("%d",&count);
    for(int i=1; i<=count; i++)
    {
        printf(" Enter Number %d: ", i);
        scanf("%d",&numbertoadd);

        AddattheEnd(head, numbertoadd);
    }
   // 
    struct node *ptr;
    ptr=head;
    while(ptr!=NULL)
    {
        printf("\n %d",ptr->data);
        ptr=ptr ->link;
    }
    printf("\n After Reversal.."    );
    struct node* ptr3;
    ptr3=reverse(head);

    while(ptr!=NULL)
    {
        printf("\n %d",ptr->data);
        ptr=ptr ->link;
    }

    return 0;
}
struct node* reverse(struct node* head)
{
    struct node * prev=NULL, * next=NULL;
    while(head!=NULL)
    {
        next=head->link;
        head-> link=prev;
        prev=head;
        head=next;

    }
    head=prev;
    return head;


}
void AddattheEnd(struct node * head, int data)
{
    struct node * ptr,*temp;
    ptr=head;
    temp=(struct node *) malloc(sizeof(struct node));
    temp->data=data;
    temp->link=NULL;
    while(ptr->link!=NULL)
    {
        ptr=ptr->link;
    }
    ptr->link=temp;
    //in this design the linked list takes big onf (n) but can be optimized to take the big(o) of 1
}