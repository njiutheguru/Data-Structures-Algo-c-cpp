#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *next;
};

void Insert_Beginnig(struct node **head, int data)
{

    struct node *temp=(struct node*)malloc (sizeof (struct node));
    temp->data=data;
    temp->next=NULL;
    temp ->next=*head;
    *head=temp;
    //here we return no pointer due to passing by value

}

int main()


{
 //code
    return 0;
}