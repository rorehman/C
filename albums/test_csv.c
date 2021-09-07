#include <stdio.h>
#include "csv.h"

int main(){
    FILE * fp = fopen("sample.csv","r");
    int status = 1;
    int num;
    while(status){
        status = getCSVInt(&num, fp);
        printf("%d ", num);
    }
    printf("\n");
    return 0;
}