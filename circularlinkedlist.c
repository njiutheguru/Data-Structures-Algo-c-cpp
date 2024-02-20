#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct node 
{
    int info;
    struct node *link;
};
struct node *createList(struct node *last);
void display(struct node *last);
struct node *insertInEmptyList(struct node *last, int data);
struct node *insertInBeginning(struct node *last, int data);
struct node *InsertatEnd(struct node *last, int data);
struct node  *insertAfter(struct node* last, int data,int item);
struct node *deleteNode(struct node *last, int data);


int main()
{ 
    int choice,data,item;
    struct node* last=NULL;
    last=createList(last);
    while(1)
    {
        printf("\n1: Display List\n");
        printf("\n 2: Insert in the Empty List");
        printf("\n 3: Insert at the beginning");
        printf("\n 4: Insert at the end");
        printf("\n 5: Insert after a Node");
        printf("\n 6: Delete a Node");
        printf("\n 7: Quit\n");
        printf("\n Enter your choice: ");
       if(scanf("%d",&choice)==0)
       {
        printf("\n Only integers are allowed::TRY AGAIN...");
        exit(0);
       }
        if(choice==7)
        {
            break;
        }
        switch(choice)
        {
            case 1:
                display(last);
                break;
            case 2:
                printf("\n Enter the element to be inserted:");
                scanf("%d",&data);
                last=insertInEmptyList(last,data);
                break;
            case 3:
                printf("\n Enter the element to be inserted:");
                scanf("%d",&data);
                last=insertInBeginning(last,data);
                break;
            case 4:
                printf("\n Enter the element to be inserted:");
                scanf("%d",&data);
                last=InsertatEnd(last,data);
                break;
            case 5:
                printf("\n Enter the element to be inserted:");
                scanf("%d",&data);
                printf("\n Enter the element after which to insert:");
                scanf("%d",&item);
                last=insertAfter(last,data,item);
                break;
            case 6:
                printf("\n Enter the element to be deleted:");
                scanf("%d",&data);
                last=deleteNode(last,data);
                break;
            
            default:
                printf("\n Wrong choice >>> Please try Again...");
                //end of switch statement


        }



    }


    return 0;
}

void display(struct node *last)
{
    struct node *p;
    if(last==NULL)
    {
        printf("\nThe list is Empty\n");
        return;
    }
    p=last->link;
   do
   {
    /* code */
    printf("\n %d ",p->info);
    p=p->link;
   } while (p!=last->link);

   printf("\n");
    
}

struct node* insertInBeginning(struct node * last, int data)
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->info=data;
    temp->link=last->link;
    last->link=temp;
    return last;

}
struct node *insertInEmptyList(struct node *last, int data)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->info=data;
    last=temp;
    last->link=last;
    return last;
}
struct node *InsertatEnd(struct node *last, int data)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->info=data;
    temp->link=last->link;
    last->link=temp;
    last =temp;
    return last;

}

struct node *createList(struct node *last)
{
    int i,n,data;
    printf("\n Enter the number of Nodes:");
    scanf("%d",&n);
    last=NULL;
    if(n==0)
    {
        return last;
    }
    printf("\n Insert the first element to be inserted:");
    scanf("%d",&data);
    last=insertInEmptyList(last,data);
    for(i=2;i<=n;i++)
    {
        printf("\n Enter element %d: ",i);
        scanf("%d",&data);
        last=InsertatEnd(last,data);

    }
    return last;
}

struct node *insertAfter(struct node *last, int data, int item)
{
    struct node *temp,*p;
    p=last->link;
    do
    {
        /* code */
        if(p->info==data)
        {
            break;
        }
        p=p->link;

    } while(p!=last->link);

    if(p==last->link && p->info !=item)
    {
        printf("\n %d not found in the list",item);
        
    }
    else{
        temp=(struct node*)malloc(sizeof(struct node));
        temp->info=data;
        temp->link=p->link;
        p->link=temp;
        if(p==last)
        {
            last=temp;
        }
    }
    return last;
    
}

struct node *deleteNode(struct node *last, int data)
{
    struct node *temp,*p;
    if(last==NULL)
    {
        printf("\n List is empty...");
        return last;
    }
    //Deletion when there is only one node....
    if(last->link==last && last ->info==data)
    {
        temp=last;
        last=NULL;
        free(temp);
        return last;
    }

    //Deletion of the first node

    if(last->link->info==data)
    {
        temp=last->link;
        last->link=temp->link;
        free(temp);
        return last;

    }
    p=last->link;
    while(p->link!=last)
    {
        if(p->link->info==data)
        {
            break;
        }
        p=p->link;
    }
    if(p->link!=last)
    {
        temp=p->link;
        p->link=temp->link;
        free(temp);
    }
    else{
          if(last->info==data)
          {
            temp=last;
            p->link=last->link;
            last=p;
            free(temp);

          }
          else{
            printf("\n Element %d not found...",data);

          }
        

    }
    return last;




}