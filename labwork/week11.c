#include <stdio.h>
#include <pthread.h>

#define ITERATIONS 1000000

int counter = 0;

void *increment(void *arg)
{
    for (int i = 0; i < ITERATIONS; i++)
    {
        counter++;
    }

    return NULL;
}

int main()
{
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, increment, NULL);
    pthread_create(&thread2, NULL, increment, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Expected Counter: %d\n", ITERATIONS * 2);
    printf("Actual Counter  : %d\n", counter);

    return 0;
}
