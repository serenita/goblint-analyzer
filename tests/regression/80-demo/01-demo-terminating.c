// TERM PARAM: --set "ana.activated[+]" termination --set ana.activated[+] apron --enable ana.int.interval --set ana.apron.domain polyhedra --set sem.int.signed_overflow assume_none
#include <stdio.h>

// Function to calculate the factorial of a number recursively
unsigned long long factorial(unsigned int n) {
    if (n == 0) {
        return 1;
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
    } while (curr <= n);

    return fib;
}

// Function to return the smallest even half of a number using goto statements
unsigned int getSmallestEvenHalf(unsigned int n) {
    if (n % 2 != 0) {
        goto end;
    }

    while (1) {
        if ((n / 2) % 2 != 0) {
            goto end;
        }
        n = n / 2;
    }
    end:
    return n;
}

int main() {
    unsigned int number = 32;
    unsigned long long fact = factorial(number);
    unsigned long long fib = fibonacci(number);
    unsigned int half = getSmallestEvenHalf(number);

    printf("Factorial of %d: %llu\n", number, fact);
    printf("Fibonacci of %d: %llu\n", number, fib);
    printf("Smallest even halves of %d: %d", number, half);

    return 0;
}
