#include <stdio.h>
#include <stdlib.h>
// #define maxsize 100

int linearSearch(int a[],int n, int searchvalue);
int main()
{
     int n,searchvalue;
     int a[]={43,77,99,55,444,76,666,9,44,333,-98,-43,-876,909};
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
    //int n=14;
    for (int i=0;i<n;i++)
    {
        if(searchValue==a[i])
        {
            return i;
        }
    }
     
        return -1;
    
}