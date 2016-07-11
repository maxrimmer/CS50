#include <stdio.h>
#include <cs50.h>
#include <math.h>



int main(void)
{
    float owe = 0;
    
    do {
    printf("Enter the owed amount: ");
    owe = GetFloat();
    } while (owe <= 0);
    
    
    owe = owe * 100.0;
    owe = roundf(owe);
    owe = (int)owe;
    
    int coins = 0;
    
    while (owe > 0) {
        if (owe >= 25) {
            owe = owe - 25;
            coins++;
        }
        else if (owe >= 10) {
            owe = owe - 10;
            coins++;
        }
        else if (owe >= 5) {
            owe = owe - 5;
            coins++;
        }
        else if (owe >= 1) {
            owe = owe - 1;
            coins++;
        }
    }
    printf("%i\n", coins);
}

