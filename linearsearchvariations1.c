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
    //optimization using sentinel
    int i=0;
 a[n]=searchValue;
 while(a[i]!=searchValue)
 {
    i++;
 }
 if(i<n)
 {
    return i;
 }
 else
 return -1;
}