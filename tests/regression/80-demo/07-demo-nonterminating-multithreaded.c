// NONTERM PARAM: --set "ana.activated[+]" termination --set ana.activated[+] apron --enable ana.int.interval --set ana.apron.domain polyhedra
#include <stdio.h>
#include <pthread.h>

// Function to calculate the factorial of a number recursively
unsigned long long factorial(unsigned int n) { // NONTERMFUNDEC
    if (n == 0) {
        return factorial(1); // 1
    } else {
        return n * factorial(n - 1);
    }
}

// Function to calculate the Fibonacci number using a do-while loop
unsigned long long triangle(unsigned int n) {
    unsigned long long curr = 0;
    unsigned long long triangle = 0;

    do {
        curr++;
        triangle = triangle + curr;
    } while (curr <= triangle); // NONTERMLOOP
    // < n
    return triangle;
}

// Function to return the smallest even half of a number using goto statements
unsigned int getSmallestEvenHalf(unsigned int n) {
    start:
    if (n % 2 != 0) {
        goto end;
    }

    while (1) {
        if ((n / 2) % 2 != 0) {
            goto start; // NONTERMGOTO
            // end
        }
        n = n / 2;
    }
    end:
    return n;
}

// Function to be executed by the first thread
void* factorialPrintThread(void* arg) {
    unsigned int n = *(unsigned int*)arg;
    printf("Factorial of %d: %llu\n", n, factorial(n));
    return NULL;
}

// Function to be executed by the second thread
void* trianglePrintThread(void* arg) {
    unsigned int n = *(unsigned int*)arg;
    printf("Triangle number of %d: %llu\n", n, triangle(n));
    return NULL;
}

// Function to be executed by the third thread
void* smallestEvenHalfPrintThread(void* arg) {
    unsigned int n = *(unsigned int*)arg;
    printf("Smallest even half of %d: %d\n", n, getSmallestEvenHalf(n));
    return NULL;
}

int main() {
    unsigned int number = 32;
    pthread_t thread1, thread2, thread3;

    // Create the first thread for factorial calculation
    pthread_create(&thread1, NULL, factorialPrintThread, &number);

    // Create the second thread for triangle number calculation
    pthread_create(&thread2, NULL, trianglePrintThread, &number);

    // Create the third thread for smallest even half calculation
    pthread_create(&thread3, NULL, smallestEvenHalfPrintThread, &number);

    // Wait for all threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);

    return 0;
}
