
#include "get_next_line.h"

char    *get_next_line(int fd)
{
    ssize_t nbytes;
    static char *stash;
    char    *buf;

    if (BUFFER_SIZE <= 0 || fd < 0)
        return (NULL);
    buf = malloc(sizeof(char) * BUFFER_SIZE);
    if (buf == NULL)
        return (NULL);
    nbytes = read(fd, buf, BUFFER_SIZE);
    //handle case nbytes == 0 here ?
    if (!stash)
        stash = ft_strdup(buf);
    while (!ft_strchr(stash, '\n') && !nbytes)
    {
        
    }
}