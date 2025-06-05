#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
    int fd;
    char *line;

    fd = open("gnlTester_files/nl", O_RDWR);
    line = get_next_line(fd);
    printf("line GNL=%s", line);
    free(line);
    line = get_next_line(fd);
    printf("line GNL=%s", line);
    free(line);
    return (0);
}
