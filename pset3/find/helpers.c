/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    /* TODO: implement a searching algorithm
    if (n < 0) {
    return false;
    }
    
    for (int i = 0; i < n; i++) {
        if (value == values[i]) {
            return true;
        }
        
    }
    return false;
*/
    // While length of list > 0
    int lower = 0;
    while (n - lower > 0) {
        // Look at the middle of the list
        int mid = (n-lower)/2.0+1+lower;
        if(values[mid] == value) {
        // If found, return true
            return true;
        } else if (values[mid] > value) {
            n = mid - 1;   
        } else if (values[mid] < value) {
            lower = mid + 1;
            }
        }
        
    return false;

    
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    // Count var to check if any changes have happend
    int count = 1;
    // While count = 0
    while (count != 0) {
    
    // Count = 0
    count = 0;
    // For each int in values[]
    for (int i = 0; i <= n-1; i++) {
        
    // Check if n+1 is greater than n
        if (values[i+1] < values[i]) {
            // If so, swap the integers, by putting one of them into a variable.
            int swap = values[i];
            
            
            values[i] = values[i+1];
            values[i+1] = swap;
            count++;
            
            }
        }
    }
    return;

}