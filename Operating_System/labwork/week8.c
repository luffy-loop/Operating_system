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

    int array_size = 3;
    int *my_array = calloc(array_size, sizeof(int));

    if (my_array == NULL)
    {
        printf("Calloc failed\n");
        free(a);
        return 1;
    }

    my_array[0] = 10;
    my_array[1] = 20;
    my_array[2] = 30;

    int new_size = 4;
    int *temp = realloc(my_array, new_size * sizeof(int));

    if (temp == NULL)
    {
        printf("Realloc failed\n");
        free(a);
        free(my_array);
        return 1;
    }

    my_array = temp;
    my_array[3] = 40;

    printf("a value: %d\n", *a);

    for (int i = 0; i < new_size; i++)
    {
        printf("my_array[%d] = %d\n", i, my_array[i]);
    }

    free(a);
    free(my_array);

    a = NULL;
    my_array = NULL;

    return 0;
}
