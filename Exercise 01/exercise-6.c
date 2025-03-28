#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int m = 10, n = 5;
    int* mp, * np;
    
    mp = &m;       // mp now contains address of m
    np = &n;       // np now contains address of n
    *mp = *mp + *np;   // value at mp (m) becomes 15 (10 + 5)
    *np = *mp - * np;  // value at np (n) becomes 10 (15 - 5)
    
    printf("Results:\n");
    printf("%d %d\n%d %d\n", m, *mp, n, *np);
    // Output will be:
    // 15 15
    // 10 10
    // Because:
    // - m was changed to 15 through mp
    // - *mp shows the value at m which is 15
    // - n was changed to 10 through np
    // - *np shows the value at n which is 10
    
    return 0;
}
