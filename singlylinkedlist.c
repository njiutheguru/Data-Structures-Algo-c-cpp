#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
//arrys  come with the risk of overflow or memory wastage
//implementation of a single linked list 

struct node {
    int data;
    struct node *link;

};
struct node *createlist(struct node *start);
void displaylist(struct node *start);
void countnodes(struct node *start);
void search(struct node *start, int x);
struct node *insertInBeginning(struct node*start, int data);
struct node *insertBefore (struct node *start, int data, int x);
struct node *insertAtPosition(struct node *start, int data, int k);
struct node * deleteNode(struct node *start, int data);
struct node * reverseList(struct node *start);
void insertAtEnd(struct node *start, int data);
void insert_After(struct node *start, int data, int x);




int main()
{
    struct node *start =NULL;
    int choice, data,x,k;
    start=createlist(start);
    while(1)
    {
        printf("\n");
        printf("\n 1. Display List");
        printf("\n 2. Count the Number of Nodes");
        printf("\n 3. Search for an element");
        printf("\n 4. Add to empty list/ Add at begining");
        printf("\n 5. Add a node at the end of the list");
        printf(" \n 6. Add a node after a specified node ");
        printf("\n 7. Add a node before a specified node");
        printf(" \n 8. Add a node at a given Position");
        printf(" \n 9. Delete a node");
        printf("\n 10. Reverse the list");
        printf("\n 11. Quit \n");
        
        printf("\n Enter your choice: ");
        if(scanf("%d",&choice)!=1)
        {
            printf("\n Only integers allowed.");
            break;
            getch();
        }

        if(choice==11)
        {
            break;
        }
        
        switch(choice)
        {
            case 1:
                displaylist(start);
                getch();
                break;
            case 2:
                countnodes(start);
                getch();
                break;
            case 3:
                printf("\n Enter the element to be searched:");
                scanf("%d",&data);
                search(start,data);
                getch();
                break;
            case 4:
                printf(" \n Enter the element to be inserted :");
                scanf("%d",&data);
                start=insertInBeginning(start, data);
                getch();
                break;
            case 5:
                printf("\n Enter the  Element to be Inserted");
                scanf("%d",&data);
                insertAtEnd(start,data);
                getch();
                break;
            case 6:
                printf("\n Enter the Element to be Inserted:");
                scanf("%d",&data);
                printf("\nEnter the Element after which to insert:");
                scanf("%d",&x);
                insert_After(start, data, x);
                getch();
                break;
            case 7:
                printf("\nEnter the Element to be Inserted:");
                scanf("%d",&data);
                printf("\nEnter the Element BEFORE which to insert:");
                scanf("%d",&x);
                insertBefore(start, data, x);
                getch();
                break;
            case 8:
                printf("\nEnter the Element to be Inserted:");
                scanf("%d",&data);
                printf("\n Enter the position at which to Insert:");
                scanf("%d",&k);
                start=insertAtPosition(start, data, k);
                getch();
                break;
            case 9:
                printf("\nEnter the Element to be Deleted:");
                scanf("%d",&data);
                start=deleteNode(start, data);
                start=deleteNode(start, data);
                getch();
                break;
            case 10:
                start=reverseList(start);
                break;
                default:
                printf(" You Entered the wrong choice, Please try Again");
                getch();
                break;
                


        }


    }


    return 0;
}
struct node *createlist(struct node *start)
{
    int i,n,data;
    printf("\n enter the number of Nodes..");
    scanf("%d",&n);
    if(n==0)
    {
        return start;
    }
    printf("\nEnter the First Number to be inserted: " );
    scanf("%d",&data);
    start=insertInBeginning(start, data);

    for(i=1;i<n;i++)
    {
        printf("\n Enter the %d Element to be Inserted:", i+1);
        scanf("%d",&data);
        insertAtEnd(start,data);
    }
    return start;
}
void displaylist(struct node *start)
{
    struct node *p;
    if(start==NULL)
    {
        printf("\n The list is empty...");
        return;

    }
    printf("\n the list is:...");
    p=start;
    while(p!=NULL)
    {
        printf("\n %d ", p->data);
        p=p->link;
    }
    printf("\n");
}
void countnodes(struct node *start)
{
    int n=0;
    struct node* p;
    p=start;
    while(p!=NULL)
        {
            n++;
        p= p->link;
        }
   printf("\n The number of Nodes are: %d ",n);
}

void search(struct node *start, int x)
{
    struct node *p=start;
    static int position=1;
    p=start;
    if(p==NULL)
    {
        printf("\n The list is empty..., The element %d is not in the list\n",x);
    }
    while(p!=NULL)
        {
            if(p->data==x)
            {
                position++;
                p=p->link;
                printf("\n The element %d is found in position %d", x, position);
                break;
            
            }
         }
         //position++;
        
        
            if(p==NULL)
            {
                printf("\n The element %d is not found in the list", x);
                //break;
            }
            //else
           // {
               // printf("\n The element %d is found in position %d", x, position);
               // break;
           // }
        
        
}
struct node *insertInBeginning(struct node*start, int data)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->link=start;
    start=temp;
    return start;

}
struct node *insertBefore (struct node *start, int data, int x)
{

    struct node *temp, *p;
    if(start==NULL)
    {
        printf("\n The list is empty..., The element %d is not in the list. ",x);
        return start;
    }

    if(x==start->data)
    {
        temp=(struct node*)malloc(sizeof(struct node));
        temp->data =data;
        temp->link=start;
        start=temp;
         return start;

    }
    p=start;
    while(p->link!=NULL)
    {
        if(p->link->data==x)
        {
            break;
        }
        p=p->link;
    }
    if(p->link==NULL)
    {
        printf("\n The element %d not present",x);
    }
    else{
        temp=(struct node*)malloc(sizeof(struct node));
        temp->data=data;
        temp->link=p->link;
        p->link=temp;
    }
    return start;
   
}
struct node *insertAtPosition(struct node *start, int data, int k)
{
    struct node *temp, *p;
    int i;
    if(k==1)
    {
        temp=(struct node*)malloc(sizeof(struct node));
        temp->data=data;
        temp->link=start;
        start=temp;
        return start;
    }
    p=start;
    for(i=1;i<k-1&& p!=NULL;i++)
    {
        p=p->link;
    }
    if(p==NULL){
        printf("\n You can only insert upto %dth position. ",i);
    }
    else{
        temp=(struct node*)malloc(sizeof(struct node));
        temp->data=data;
        temp->link=p->link;
        p->link=temp;
    }
return start;
}
struct node * deleteNode(struct node *start, int x)
{
        struct node *temp, *p;
        if(start==NULL)
        {
            printf("\n the list is empty.\n");
            return start;
        }
        //deletion of first node
        if(start->data==x)
        {
            temp=start;
            start=start->link;
            free(temp);
            return start;
        }
        //deletion in between or at the ends 
        p=start;
        while(p->link!=NULL)
        {
            if(p->link->data==x)
            {
                break;
            }
            p=p->link;
        }
        if(p->link==NULL)
        {
            printf("\n element %d not found",x);

        }
        else
        {
            temp=p->link;
           p->link=temp->link;
           free(temp);


        }
        return start;
   
}
struct node * reverseList(struct node *start)
{
    struct node *prev, *ptr, *next;
    prev=NULL;
    ptr=start;
    while(ptr!=NULL)
    {
        next=ptr->link;
        ptr->link=prev;
        prev=ptr;
        ptr=next;

    }
    start=prev;
    return start;


}
void insertAtEnd(struct node *start, int data)
{ struct node *p, *temp;
temp=(struct node*)malloc(sizeof(struct node));
temp->data=data;
p=start;
while(p->link != NULL)
{
    p=p->link;
}
p->link=temp;
temp->link=NULL;


}
void insert_After(struct node *start, int data, int x)
{
    struct node *temp, *p;
    p=start;
    while(p!=NULL)
    {
        if(p->data==x)
        {
            break;
        }
        p=p->link;
    }
    if(p==NULL)
    {
        printf("\n %d not found in the list",x);
    }
    else{
        temp=(struct node *)malloc(sizeof(struct node));
        temp->data=data;
        temp->link=p->link;
        p->link=temp;

    }

}
