#include <stdio.h>

int main(){
    int number = 0;
    scanf("%i", &number);
    

    for (int i=1; number>=i; i++){
        if (number % i == 0){
            printf("%i", i);
            if (number > i){
            printf(" ");
            }
            else if (number == i){
            printf("\n");
            }

        }
    }

}