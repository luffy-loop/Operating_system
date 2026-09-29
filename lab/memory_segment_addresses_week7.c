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
    int *heap_var = malloc(4);

    printf("--- TEXT (CODE) ---\nMain:  %p\nFunc:  %p\n", (void *)main, (void *)dummy_func);
    printf("--- DATA (INIT) ---\nGlobal:%p\nStatic:%p\n", (void *)&g_init, (void *)&s_init);
    printf("--- BSS (UNINIT) ---\nGlobal:%p\nStatic:%p\n", (void *)&g_uninit, (void *)&s_uninit);
    printf("--- HEAP ---\nHeap:  %p\n", (void *)heap_var);
    printf("--- STACK ---\nArg:   %p\nLocal: %p\n", (void *)&argc, (void *)&stack_local);

    free(heap_var);

    return 0;
}
