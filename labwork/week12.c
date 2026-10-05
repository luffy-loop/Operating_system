#include <stdio.h>
#include <pthread.h>

#define ITERATIONS 1000000

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

int counter = 0;

void *increment(void *arg)
{
    for (int i = 0; i < ITERATIONS; i++)
    {
        pthread_mutex_lock(&lock);

        counter++;

        pthread_mutex_unlock(&lock);
    }

    return NULL;
}

int main()
{
    pthread_t t1, t2;

    pthread_create(&t1, NULL, increment, NULL);
    pthread_create(&t2, NULL, increment, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Expected Counter: %d\n", ITERATIONS * 2);
    printf("Counter: %d\n", counter);

    return 0;
}
