#include <stdio.h>
#include <math.h>

#define N 1 // 79 is the highest my terminal can display properly lol XD

int main(){
    int x = N;
    // top of hourglass
    printf("o");
    for (int i=0; i <= 2*x; i++){
        printf("-");
    }
    printf("o\n");

    // upper half
    for (int i=0; i < x; i++){
        // inner for loop for printing spaces part 1 reeeeee
        for (int j=0; j <= i; j++){
            printf(" ");
        }
        printf("\\"); // print backslash
        // inner space
        for (int k=0; k < 2*(x-i)-1; k++){
            printf(" ");
        }
        printf("/\n"); // print forwardslash
    }

    // center
    for (int i=0; i <= x; i++){
        printf(" ");
    }
    printf("X\n");

    // lower half
    for (int i = x; i > 0; i--){
        // inner loop for printing left spaces reeeeeeeee
        for (int j = 0; j < i; j++){
            printf(" ");
        }
        printf("/"); // left side
        // sand i guess???
        for (int k = 0; k < 2*(abs(i-x)) + 1; k++){
            printf(".");
        }
        printf("\\\n");
    }

    // bottom of hourglass
    printf("o");
    for (int i=0; i <= 2*x; i++){
        printf("-");
    }
    printf("o\n");

    return 0;
}
