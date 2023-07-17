// NONTERM PARAM: --set "ana.activated[+]" termination --set ana.activated[+] apron --enable ana.int.interval --set ana.apron.domain polyhedra
#include <stdio.h>
#include <pthread.h>

// Function to calculate the factorial of a number recursively
unsigned long long factorial(unsigned int n) { // NONTERMFUNDEC
    if (n == 0) {
        return factorial(1);
    } else {
        return n * factorial(n - 1);
    }
}

// Function to calculate the Fibonacci number using a do-while loop
unsigned long long fibonacci(unsigned int n) {
    unsigned long long curr = 1;
    unsigned long long fib = 0;

    do {
        fib = fib + curr;
        curr++;
    } while (curr > 0); // Registered race; therefore no check for LOOP

    return fib;
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
        }
        n = n / 2;
    }
    end:
    return n;
}

void factorialPrint(void *arg) {
    unsigned int n = *(unsigned int *) arg;
    printf("Factorial of %iu: %llu", n, factorial(n));
}

void fibonacciPrint(void *arg) {
    unsigned int n = *(unsigned int *) arg;
    printf("Fibonacci of %iu: %llu", n, fibonacci(n));
}

void smalestEvenHalfPrint(void *arg) {
    unsigned int n = *(unsigned int *) arg;
    printf("%iu", getSmallestEvenHalf(n));
}

int main() {
    unsigned int number = 32;
    pthread_t thread1, thread2, thread3;

    pthread_create(&thread1, NULL, (void *(*)(void *)) factorialPrint, &number);
    pthread_create(&thread2, NULL, (void *(*)(void *)) fibonacciPrint, &number);
    pthread_create(&thread3, NULL, (void *(*)(void *)) smalestEvenHalfPrint, &number);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);

    return 0;
}
