/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_one func.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:31:07 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/05/27 11:31:07 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
    char    	*buf;
    char    	*line;
    static char *stash;
    int     	count;
    ssize_t     nbytes;
    char    	*tmp;

    if (BUFFER_SIZE <= 0 || fd < 0)
        return (NULL);
    buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (buf == NULL)
        return (NULL);

//if !stash we initialize stash with ft_strdup
//pas besoin de fonction pour initialiser stash. Il suffit de
//malloc stash avec BUFFER SIZE + 1 puis stash[0] = '\0'

    if (!stash || !*stash) //if stash == NULL or stash is an empty string
    {
		stash = malloc(sizeof(char) * (BUFFER_SIZE + 1)); //or just 1 for the '\0' ?
		if (!stash)
			return (NULL);
		stash[0] = '\0';
    }
//We fill the stash until we find a '\n' or EOF indicated by !nbytes
    while (!ft_strchr(stash, '\n') && !nbytes)
    {
        nbytes = read(fd, buf, BUFFER_SIZE);
		//CHECK if nbytes == -1
		buf[nbytes] = '\0';
        tmp = ft_strdup(stash);
        if (!tmp)
            return (NULL);
        free (stash);
        stash = ft_strjoin(tmp, buf);
        if (!stash)
            return (NULL);
        free(tmp);
    }
//If EOF then the return line is also the stash line
    if (!nbytes)
    {
        line = ft_strdup(stash);
        if (!line)
            return (NULL);
		free(stash);
    }
//If '\n' then we use ft_substr to get the line in the stash, including the '\n',
//then we clean the stash
    if (ft_strchr(stash, '\n'))
    {
        int i;

        i = 0;
        while (stash[i] != '\n')
            i++;
        line = ft_substr(stash, 0, i + 1); //len i + 1 to include the '\n'
        if (!line)
            return (NULL);
//we clean the stash, leaving only the characters after '\n'
        tmp = (ft_strchr(stash, '\n') + 1);
        free(stash);
        stash = ft_strdup(tmp);
        if (!stash)
            return (NULL);
    }
    //line = ft_extract_line
    //ft_clean_stash
    line[ft_strlen(line)] = '\0';
    return (line);
}
size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char *ft_initialize_stash(int fd, char *buf)
{

}
static int ft_fill_stash(int fd, char *buf)
{
    ssize_t nbytes;

}
