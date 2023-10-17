#include <stdio.h>

int main(){

    for(int i=1; i<8; i=i+3){
        for(int j=1; j<10; j++){
            printf("%d*%d=%d ", i, j, i*j);
            printf("%d*%d=%d ", i+1, j, (i+1)*j);
            printf("%d*%d=%d\n", i+2, j, (i+2)*j);
        }
        printf("\n");
    }

    return 0;
}