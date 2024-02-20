#include <stdio.h>
#include <stdlib.h>
// #define maxsize 100

int linearSearch(int a[],int first,int last, int searchvalue);
int main()
{
     int n,searchvalue;
     int a[]={-876,-98,-43,43,77,99,105,144,176,196,209,244,333,909};
      n=sizeof(a)/sizeof(a[1]);
  printf("\n Enter the Search Value: ");
  scanf("%d",&searchvalue);
   int index=linearSearch(a,0,n-1,searchvalue);
   if(index==-1)
   {
    printf("\n Element not found");
   }
   else{
    printf("\n %d found in index %d , position %d ", searchvalue,  index,index+1);

   }
    return 0;
}
int linearSearch(int a[],int first,int last, int searchValue)
{
    int mid=(first+last)/2;
    
   if(first>last)
   return -1;
   if(searchValue<a[mid])
   {
    return linearSearch(a,first,mid-1,searchValue);
   }
   else if(searchValue>a[mid])
   {
    return linearSearch(a,mid+1,last,searchValue);
   }
   else{
    return mid;
   }

}