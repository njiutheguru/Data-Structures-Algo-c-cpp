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
 //optimazation when sorted
 int i=0;
 for(i=0;i<n;i++)
 {
    if(a[i]>=searchValue)
    {
        break;
    }
 }
    if(a[i]==searchValue)
    return i;
    else
    return -1;
 
}