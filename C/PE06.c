#include <stdio.h>
#include <stdlib.h>

void update(int *a, int *b) {
    /* Write your code for update() here */
    *a = *a + *b;
    *b = abs(*a - *b*2);
}

int main() {
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);
    /* Supply code to call update() here */
    update(&a, &b);
    printf("%d\n%d", a, b);

    return 0;
}