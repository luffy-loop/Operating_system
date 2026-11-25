#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *a = malloc(sizeof(int));

    if (a == NULL)
    {
        printf("Malloc failed\n");
        return 1;
    }

    *a = 77;

    int n = 3;
    int *arr = calloc(n, sizeof(int));

    if (arr == NULL)
    {
        printf("Calloc failed\n");
        free(a);
        return 1;
    }

    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;

    int ns = 4;
    int *temp = realloc(arr, ns * sizeof(int));

    if (temp == NULL)
    {
        printf("Realloc failed\n");
        free(a);
        free(arr);
        return 1;
    }

    arr = temp;
    arr[3] = 40;

    printf("a value: %d\n", *a);

    for (int i = 0; i < ns; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    free(a);
    free(arr);

    a = NULL;
    arr = NULL;

    return 0;
}
