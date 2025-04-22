// testing if this shows
#include <stdio.h>
#include <math.h>
#include <pthread.h>
#include "primes.h"//implementing

typedef struct { //example structure
    int example;
    int e_g;
} Example_Structure;

static void example_helper_function(int n){
    // Functions defined with the modifier 'static' are only visible
    // to other functions in this file. They cannot be called from
    // outside (for example, from main.c). Use them to organize your
    // code. Remember that in C, you cannot use a function until you
    // declare it, so declare all your utility functions above the
    // point where you use them.
    //
    // Maintain the primes_xt functions as lean as possible
    // because we are measuring their speed. Unless you are debugging,
    // do not print anything on them, that consumes precious time.
    //
    // You may delete this example helper function and structure, and
    // write your own useful ones.

    Example_Structure es1;
    es1.example = 13;
    es1.e_g = 7;
    printf("n = %d\n", es1.example + es1.e_g + n);
    return;
}

// max is the max number to test primes up to, verb indicates whether to print the primes
// print the prime if verb != 0
void primes_st(unsigned int max, unsigned int verb){
    //Put your code here.
    //example_helper_function(1000);
    // outer loop: go over all numbers
    
    for(int tested_number = 2; tested_number < (max); tested_number++){
        int isPrime = 1;
        
        // inner loop: test every number up to half to see if there are
        // any valid factors. If not, it's a prime
        for(int factor = 2; factor*factor <= tested_number; factor++){
            
            // if modulo gives zero, it is not a prime
            // is a prime
            if (tested_number % factor == 0){
                isPrime = 0;  // not prime
                break;
            } 
                
        }
        if (isPrime == 1){
            printf("%d is a prime\n", tested_number);
        }
        
    }
    return;
}

void primes_mt(unsigned int max, unsigned int threads,	\
	       unsigned int verb){
               
    //Put your code here.
    //example_helper_function(2000);
    // mutex should be counter
    return;
}
