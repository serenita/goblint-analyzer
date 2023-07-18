// TERM PARAM: --set "ana.activated[+]" termination --set ana.activated[+] apron --enable ana.int.interval --set ana.apron.domain polyhedra
#include <stdio.h>
#include <pthread.h>

// Function to be executed by the first thread
void* threadFunction1(void* arg) {
    int threadNumber = *(int*)arg;
    printf("Thread %d is running.\n", threadNumber);
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    int threadArg1 = 1;
    int threadArg2 = 2;

    // Create the threads
    pthread_create(&thread1, NULL, threadFunction1, &threadArg1);
    pthread_create(&thread2, NULL, threadFunction1, &threadArg2);

    // Wait for both threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Main thread is done.\n");
    return 0;
}
