#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int m = 25, n = 77;
    int* itemp;
    
    printf("Analysis of statements:\n\n");
    
    // m = &n;
    printf("1. m = &n;\n");
    printf("   ERROR: Cannot assign address to int variable.\n");
    printf("   Type mismatch: &n is a pointer (address), m is an int.\n\n");
    
    // itemp = m;
    printf("2. itemp = m;\n");
    printf("   ERROR: Cannot assign int to pointer directly.\n");
    printf("   Type mismatch: m is an int, itemp expects an address.\n\n");
    
    // *itemp = *&m;
    printf("3. *itemp = *&m;\n");
    printf("   ERROR: itemp is uninitialized.\n");
    printf("   Dereferencing uninitialized pointer is undefined behavior.\n\n");
    
    // *itemp = &n;
    printf("4. *itemp = &n;\n");
    printf("   ERROR: Two issues:\n");
    printf("   1. itemp is uninitialized\n");
    printf("   2. Type mismatch: &n is an address, can't be stored in value pointed by itemp\n");
    
    return 0;
}
