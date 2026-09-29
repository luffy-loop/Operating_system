#include <unistd.h>

int main() {
    char *msg = "Hello, Kernel!\n";

    write(1, msg, 15);

    return 0;
}


