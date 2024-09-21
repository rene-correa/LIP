/**
 *  @ Author: Renê Corrêa
 *  @ Create Time: 21-09-24 09:51:19
 *  @ Description:
 */

#include <stdio.h>  

int main() {
    // Loop for que percorre os números de 1 a 10
    for (int i = 1; i <= 10; i++) {
        // Verifica se o número atual (i) é par
        if (i % 2 == 0) {
            printf("%d  par\n", i);  // Imprime se o número for par
        } else {
            printf("%d  impar\n", i);  // Imprime se o número for ímpar
        }
    }
    
    return 0;  
}
