/**
 *  @ Author: Renê Corrêa
 *  @ Create Time: 29-08-24 19:52:20
 *  @ Description: BitWise basic operations examples
 */

#include <stdio.h>

int main(){
    int a = 0B00000010;
    int b = 0B10101010;
    int c = 0B00000000;

    c = a | b;
    printf("OR entre a e b: %d\n", c);

    c = a & b;
    printf("AND entre a e b: %d\n", c);

    c = a ^ b;
    printf("XOR entre a e b: %d\n", c);

    return 0;
}