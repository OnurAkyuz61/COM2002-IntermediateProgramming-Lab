// After preprocessing, the program will look like this:
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int main(void)
{
    int a[10], i, j, k, m;

    i = j;  // Since N is defined as 10, #ifdef N is true

    i = 10 + (j+1);  // INC(j) expands to j+1

    i = j - k;       // SUB(j,k) expands to j-k

    i = ((j)*(j));   // SQR(SQR(j)) expands to ((j)*(j))

    i = (((j)*(j))*(j));  // CUBE(j) expands to (SQR(j)*(j)) which is (((j)*(j))*(j))

    i = j#k;         // M1(j,k) expands to j#k

    puts(#i #j);     // M2(i,j) expands to #i #j

    i = ((j)*(j));   // After #undef SQR and #define SQR again

    return 0;
}
