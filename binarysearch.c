#include <stdio.h>
#include <stdlib.h>
// #define maxsize 100

int linearSearch(int a[],int n, int searchvalue);
int main()
{
     int n,searchvalue;
     int a[]={-876,-98,-43,43,77,99,105,144,176,196,209,244,333,909};
      n=sizeof(a)/sizeof(a[1]);
  printf("\n Enter the Search Value: ");
  scanf("%d",&searchvalue);
   int index=linearSearch(a,n,searchvalue);
   if(index==-1)
   {
    printf("\n Element not found");
   }
   else{
    printf("\n %d found in index %d , position %d ", searchvalue,  index,index+1);

   }
    return 0;
}
int linearSearch(int a[],int n, int searchValue)
{
    int first=0,last=n-1,mid;
    
    while(first<=last)
    {
        mid=(first+last)/2;
        if(searchValue<a[mid])
        {
            last=mid-1;
        }
        else if(searchValue>a[mid])
        {
            first=mid+1;
        }
        else{
            return mid;
        }
    }
    return -1;
 
}