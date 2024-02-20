#include <stdio.h>
#include <stdlib.h>

struct node 
{
     int data;
     struct node *next;
};
void createnodes(struct node **head,int data)
{
    struct node *node1 = (struct
    
     node*)malloc(sizeof(struct node));
    node1->data =data;
    node1->next =(*head)->next;//deferencing the pointer
    (*head)->next= node1;
    //return *head;
}

int main()
{
    //code
    //struct node *head;
    struct node *head=(struct node*)malloc(sizeof(struct node));
   head->data=543;
    head->next=NULL;
   // head= head1;
    printf("\n How many nodes:");
    int num,data;
    scanf("%d",&num);
    for(int i=0; i<num; i++)
    {
        printf("\n Enter element %d:",i+1);
        scanf("%d",&data);
    createnodes(&head, data);
    }
   /* struct node *node2=(struct node*)malloc(sizeof(struct node));
    node2->data=53;
    node2->next=NULL;
    head->next=node2;
    
    struct node *node3=(struct node*)malloc(sizeof(struct node));
    node3->data=5439;
    node3->next=NULL;
    node2->next=node3;

    
    struct node *node4=(struct node*)malloc(sizeof(struct node));
    node4->data=983;
    node4->next=NULL;
     node3->next=node4;
    
    struct node *node5=(struct node*)malloc(sizeof(struct node));
    node5->data=93;
    node5->next=NULL;
     node4->next=node5;
    
*/

    struct node* ptr1;
    struct node *ptr2;
    //assuming there is already created linked list

    ptr1=head;
    ptr2=head;
    //ptr1=head;
    while(ptr1!=NULL)
    {
        printf("%d\n",ptr1->data);
        ptr1=ptr1->next;
        //free(head);
       // head=ptr1;
    }
    
    while(ptr2!=NULL)
    {
        ptr2=ptr2->next;
        free(head);
        head=ptr2;
    }
    if(head==NULL)
    {
        printf("Whole linked list is deleted\n");
    }

    head=NULL;
    ptr1=NULL;

    //if()

    return 0;
}