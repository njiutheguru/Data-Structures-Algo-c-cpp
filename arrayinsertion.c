#include <stdio.h>
#include <stdlib.h>

//insertion and deletion in an array 

void Array_Insertion(int arr1[], int arr2[], int siz,int pos,int data)
{
    
    for(int i = 0; i < pos-1; i++)
    {
        arr2[i] = arr1[i];
    }
    arr2[pos-1]=data;
    for(int i = pos-1; i <= siz; i++)
    {
        arr2[i+1]=arr1[i];
    }
}
void array(int siz,int arr2[])
{
    printf("\n Enter the position of the element to be deleted: ");
    int pos;
    scanf("%d",&pos);
   // if(pos==)
    if(pos>siz+1)
    {
        printf("\n Deletion is not possibe");
        exit(0);

    }
    else 
    
    {
        for(int i = pos-1; i < siz;i++)
        arr2[i]=arr2[i+1];
    }
    // delete (arr2[siz+1]);
    for(int i=0;i<siz;i++)
    {
        printf("%d ",arr2[i]);
    }

}

int main()
{
    int arr1[]={1,2,3,4,5,6,7,8,9,10};
    int siz=sizeof(arr1)/sizeof(arr1[0]);
    int arr2[siz+1];
    int data;
    int pos;
    printf("\n Enter the data to be inserted into the array: ");
    scanf("%d",&data);
    printf("\n From position 1 to %d, Enter the position of the data to be inserted into the array: ",siz+1);
    scanf("%d",&pos);
    if(pos>siz+1)
    {
        printf("\nThe position is out of range....Please try Again.");
        exit(0);
    }

    for(int i=0;i<siz;i++)
    {
        printf("%d ",arr1[i]);
    }
    printf("\n");
    printf("After insertion:\n");
    Array_Insertion( arr1, arr2, siz,pos, data);

    for(int i=0;i<siz+1;i++)
    {
        printf("%d ",arr2[i]);
    }
    printf("\n After deletion:\n");
    array(siz,arr2);
   



    return 0;
}