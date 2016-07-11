#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <stdlib.h>

// Prototypes
void pToC(string p, int k[], int kE);
int * kToInt(string k, int * kE);

int main(int argc, string argv[]) {
    // Check if K is declared
    
    if (argc != 2) {
        printf("Please enter a valid K value\n");
        return 1;
    }
    
    for (int i = 0; i < strlen(argv[1]); i++) {
        if (argv[1][i] < 65 || argv[1][i] > 122) {
            printf("Please enter a valid K value\n");
            return 1;
        }
        else if (argv[1][i] > 90 && argv[1][i] < 97) {
            printf("Please enter a valid K value\n");
            return 1;
        }
    }
    
    // Store k as a string
    string k = argv[1];
    int kE[strlen(k)];
    int kLen = strlen(k);
    int * kAsInt = kToInt(k, kE);
    
    // Get unencrypted string
    string p = GetString();
    
    pToC(p, kAsInt, kLen);
    
    printf("\n");
    return 0;
    
}

void pToC(string p, int k[], int kE) {
    int kN = 0;
    
    
    for (int i = 0; i < strlen(p); i++) {
        
        
        if (p[i] >= 65 && p[i] <= 90 ) {
            
            // Encrypt
            int e = ((p[i] - 64 + k[kN % kE]) % 26) + 64;
            printf("%c", e);
            
            
            kN++;
            
        }
        
        else if (p[i] >= 97 && p[i] <= 122) {
            
            int e = ((p[i] - 96 + k[kN % kE]) % 26) + 96;
            printf("%c", e);
            
            
            kN++;
        }
        
        else {
            printf("%c", p[i]);
        }
    }
    
}


int * kToInt(string k, int * kE) {
    
    // Convert k to chiffer value
    for (int i = 0; i < strlen(k); i++) {
        // Lowercase
        if (k[i] >= 97 || k[i] <= 122) {
            kE[i] = k[i] - 97;
        }
        // Uppercase
        else if (k[i] >= 65 || k[i] <= 90) {
            kE[i] = k[i]- 97;
        }
    }
    
    return kE;
}