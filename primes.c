// testing if this shows
// help for the isprime function https://www.programiz.com/c-programming/examples/prime-number
#include <stdio.h>
#include <math.h>
#include <pthread.h>
#include "primes.h"//implementing

typedef struct { //example structure
    int example;
    int e_g;
} Example_Structure;

pthread_mutex_t lock;
int counter = 2;

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
            if (verb != 0){
                printf("%d is a prime\n", tested_number);
            }
            
        }
        
    }
    return;
}


// the prime checker thread does a while loop to check if the shared counter mutex is unlocked
// if it's unlocked, it gets the number, increments it, and lets go of the lock
// then it checks if the number is a prime and prints if verbose. Then it continues the while loop
void* prime_checker_routine(void* arg)
    {   
        int verb = *((int*)arg);

        // get the current number
        pthread_mutex_lock(&lock);
        int tested_number = counter;
        counter++;
        pthread_mutex_unlock(&lock);

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
            if (verb != 0){
                printf("%d is a prime\n", tested_number);
            }
        }
        
        return NULL;
    }

void primes_mt(unsigned int max, unsigned int threads,	\
	       unsigned int verb){
               
    //Put your code here.
    //example_helper_function(2000);
    // mutex should be counter
    // PSEUDOCODE
    // create a shared counter mutex variable to keep track of which number is available
    // from this counter, every thread accesses the mutex, takes the number, and increments it
    // after it gets the number it calculates if it's a prime
    // after finishing, request another number
    // when the counter reaches the max, end the thread
    
    // initialize
    
    
    pthread_t thread[threads];
    for (int i=0; i < threads; i++){   
        int rc = pthread_create(&thread[i], NULL, prime_checker_routine, &verb);
    }
    for (int i=0; i < threads; i++){
        pthread_join(thread[i], NULL);
    }

    return;
}
