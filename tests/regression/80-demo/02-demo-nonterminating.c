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

void factorialPrint(unsigned int n) {
    printf("Factorial of %i: %llu\n", n, factorial(n));
}

void trianglePrint(unsigned int n) {
    printf("Triangle number of %i: %llu\n", n, triangle(n));
}

void smallestEvenHalfPrint(unsigned int n) {
    printf("Smallest even half of %i: %i", n, getSmallestEvenHalf(n));
}

int main() {
    unsigned int number = 32;

    factorialPrint(number);
    trianglePrint(number);
    smallestEvenHalfPrint(number);

    return 0;
}
