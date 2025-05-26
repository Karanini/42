
#include "get_next_line.h"

char    *get_next_line(int fd)
{
    char    *buf;
    char    *line;
    static char *stash;
    int     count;

    if (BUFFER_SIZE <= 0 || fd < 0)
        return (NULL);
    buf = malloc(sizeof(char) * BUFFER_SIZE);
    if (buf == NULL)
        return (NULL);
    if (!stash)
        ft_initialize_stash(fd, buf);
    if (ft_fill_stash(fd, buf) == -1)
        return (NULL);
    //line = ft_extract_line
    //ft_clean_stash
    return (line);
}

static char *ft_initialize_stash(int fd, char *buf)
{
    ssize_t     *nbytes;

    nbytes = read(fd, buf, BUFFER_SIZE);
    //handle case nbytes == 0 here ?
    stash = ft_strdup(buf);
    if (!stash)
        return (-1);
    return (stash);
}
static int ft_fill_stash(int fd, char *buf)
{
    ssize_t nbytes;
    char    *tmp;

    //initialization of nbytes and stash to move to a separate function ?
    
    while (!ft_strchr(stash, '\n') && !nbytes)
    {
        tmp = ft_strdup(stash);
        if (!tmp)
            return (-1);
        free (stash);
        stash = ft_strjoin(tmp, buf);
        if (!stash)
            return (-1);
        nbytes = read(fd, buf, BUFFER_SIZE);
    }
}
