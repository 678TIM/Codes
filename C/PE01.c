#include <stdio.h>
#include <stdlib.h>

int main() {
    int a,b;
    scanf("%d", &a);
    scanf("%d", &b);
    int gcf = 1;
    int i = 1;
    if (a >= b) {
        for (i = 1; i <= b; i++) {
            if (a % i == 0 && b % i == 0) {
                gcf = i;
            }
        }
    } else {
        for (i = 1; i <= a; i++) {
            if (a % i == 0 && b % i == 0) {
                gcf = i;
            }
        }
    }
    printf("%d\n%d", a/gcf, b/gcf);

    return 0;
}