#include <stdio.h>

int main(){
    int i= 0;
    for (i =0; i< 1000000001; ++i) i+=1;
    printf("%d",i);
    return 0;
}