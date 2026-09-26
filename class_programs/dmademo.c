#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *my_array = calloc(3, sizeof(int));

    if (my_array == NULL)
    {
        printf("Calloc failed\n");
        return 1;
    }

    my_array[0] = 10;
    my_array[1] = 20;
    my_array[2] = 30;

    my_array[100] = 50;

    for (int i = 0; i < 3; i++)
    {
        printf("my_array[%d] = %d\n", i, my_array[i]);
    }

    return 0;
}
