#include <stdio.h>
#include <stdlib.h>
int max (int a, int b){
    return a > b ?  a : b;
}

int main(){
    int a = 10 , b = 12;
    printf("%d", max(a,b));
}