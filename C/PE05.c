#include <stdio.h>
#include <stdlib.h>

int main () {
    printf("|   pid|    cpu|stat|                     name| hexdump|\n");
    printf("+------+-------+----+-------------------------+--------+\n");
    for (int i = 0; i < 1000; i++) {
        int pid = 0;
        char name[26] = "";
        char stat[4] = "";
        double cpu = 0.0;
        int hexdump = 0;
        scanf("%d\t%s\t%s\t%lf\t%x\n", &pid, name, stat, &cpu, &hexdump); // %x reads hex numbers
        printf("|%6d|%.5f|%4s|%25s|%8u|\n", pid, cpu, stat, name, hexdump); // %u converts hex to dec
    }

    return 0;
}