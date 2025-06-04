#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
    int fd;
    char *line;

    fd = open("gnlTester_files/41_no_nl", O_RDWR);
    line = get_next_line(fd);
    printf("line GNL=%s", line);
    free(line);
    printf("\n");
    line = get_next_line(fd);
    printf("line GNL=%s", line);
    free(line);
    return (0);
}