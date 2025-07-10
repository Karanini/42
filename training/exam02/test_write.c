#include <unistd.h>

int main(void)
{
    int i = 49;

    // This will compile - passing address of int
    write(1, &i, 1);  // Writes 1 byte from the memory location of i
    write(1, "\n", 1);

    // For comparison, to write the character '1' (ASCII 49)
    char c = (char)i;  // Convert int 49 to char '1'
    write(1, &c, 1);
    write(1, "\n", 1);

    // Or more directly
    char digit = '1';  // ASCII value 49
    write(1, &digit, 1);
    write(1, "\n", 1);

    return (0);
}
