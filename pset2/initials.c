#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    
    string name = GetString();
   
    
    printf("%c", toupper(name[0]));
    
    for (int i = 1; i < strlen(name); i++) {
        if (name[i-1] == 32) {
            printf("%c", toupper(name[i]));
            
        } 
    }
    
    printf("\n");
}