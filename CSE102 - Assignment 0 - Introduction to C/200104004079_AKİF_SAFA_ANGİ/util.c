#include <stdio.h>
#include "util.h"

void fraction_print(int numerator, int denominator) {
    printf("%d//%d", numerator, denominator);
}  /* end fraction_print */

void fraction_add(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3 = n1*d2 + n2*d1;
    *d3 = d1*d2;
    fraction_simplify(n3, d3);
} /* end fraction_add */

void fraction_sub(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3 = n1*d2 - n2*d1;
    *d3 = d1*d2;
    fraction_simplify(n3, d3);
} /* end fraction_sub */

void fraction_mul(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3 = n1*n2;
    *d3 = d1*d2;
    fraction_simplify(n3, d3);
} /* end fraction_mul */

void fraction_div(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3 = n1*d2;
    *d3 = d1*n2;
    fraction_simplify(n3, d3);
} /* end fraction_div */

/* Simplify the given fraction such that they are divided by their GCD */
void fraction_simplify(int * n, int * d) {
    int i,gcd = 1;
    
    /* Check the numbers are negative or not.If they are both negatives we turn them to positive numbers with multiplication with (-1) */
    if(*n < 0 && *d < 0){
    *n = *n * (-1);
    *d = *d * (-1);
    }

    //To start with two,check the numbers. If they are divide "i" will be new gcd
    for(i = 2;i <= *n || i <= *d;i++){
        if(*n%i == 0 && *d%i == 0){
            gcd = i;
        }
    }
    
    *n = *n/gcd;
    *d = *d/gcd;
} /* end fraction_div */
