#include <stdio.h>
#include <stdlib.h>

int g_init = 1;
int g_uninit;
static int s_init = 2;
static int s_uninit;

void dummy_func()
{
}

int main(int argc, char *argv[])
{
    int stack_local = 0;
    int *heap_var = malloc(sizeof(int));

    printf("--- TEXT (CODE) ---\n");
    printf("Main:  %p\n", (void *)main);
    printf("Func:  %p\n", (void *)dummy_func);

    printf("--- DATA (INIT) ---\n");
    printf("Global:%p\n", (void *)&g_init);
    printf("Static:%p\n", (void *)&s_init);

    printf("--- BSS (UNINIT) ---\n");
    printf("Global:%p\n", (void *)&g_uninit);
    printf("Static:%p\n", (void *)&s_uninit);

    printf("--- HEAP ---\n");
    printf("Heap:  %p\n", (void *)heap_var);

    printf("--- STACK ---\n");
    printf("Arg:   %p\n", (void *)&argc);
    printf("Local: %p\n", (void *)&stack_local);

    free(heap_var);

    return 0;
}
