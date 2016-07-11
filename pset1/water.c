#include <cs50.h>
#include <stdio.h>

int CalculateBottles(int minutes);

int main(void) 
{
    printf("minutes: ");
    int m = GetInt();
    int b = CalculateBottles(m);
    printf("bottles: %d\n", b);
}

int CalculateBottles(int minutes)
{
    int b = 12 * minutes;
    return b;
}
