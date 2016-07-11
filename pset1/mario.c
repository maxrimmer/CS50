#include <stdio.h>
#include <cs50.h>

int main(void) 
{
    int h = 0;
    do {
        printf("Height: ");
        h = GetInt();
    } while (h > 23 || h<0);
    int y = h;
    while (h > 0) {
    
    for (int l = h-2; l>=0; l--) {
            printf(" ");
        }
        
        for (int p = 0; p<(y-h+2); p++) {
            printf("#");
        }
    printf("\n");
    h--;
    }
    
}
