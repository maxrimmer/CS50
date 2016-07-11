#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <stdlib.h>

// Prototypes
void pToC(string p, int k);

int main(int argc, string argv[]) {
    // Check if K is declared
    if (argc != 2) {
        printf("Please enter a valid K value\n");
        return 1;
    }
    
    // Store k as an int
    int k = atoi(argv[1]);
    
    // Get unencrypted string
    string p = GetString();
    
    pToC(p, k);
    
    return 0;
    
}

void pToC(string p, int k) {
    
    for (int i = 0; i < strlen(p); i++) {
        if (p[i] >= 65 && p[i] <= 90 ) {
            
            // Encrypt
            int e = ((p[i] - 64 + k) % 26) + 64;
            printf("%c", e);
        }
        
        else if (p[i] >= 97 && p[i] <= 122) {
            
            int e = ((p[i] - 96 + k) % 26) + 96;
            printf("%c", e);
        }
        
        else {
            printf("%c", p[i]);
        }
    }
    printf("\n");
}