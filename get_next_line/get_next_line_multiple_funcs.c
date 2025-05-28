/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_multiple_funcs.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:31:07 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/05/27 18:25:43 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
    char    	*buf;
    char    	*line;
    static char *stash;
	static int	end_of_file = 0;
	ssize_t		nbytes;

	// end_of_file = 0;
    if (BUFFER_SIZE <= 0 || fd < 0 || end_of_file == 1)
        return (NULL);
    buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (buf == NULL)
        return (NULL);
    if (!stash) //if stash == NULL -> need to initialize it
    {
		stash = malloc(sizeof(char) * (BUFFER_SIZE + 1)); //or just 1 for the '\0' ?
		if (!stash)
			return (NULL);
		stash[0] = '\0';
    }
	stash = ft_fill_stash(stash, fd, buf, &nbytes);
	if (!nbytes)
		end_of_file = 1;
	// printf("stash after ft_fill_stash==%s\n", stash);
	// fflush(stdout);
	// if (stash == NULL) //useless : already checked in ft_fill_stash
	// 	return (NULL);
	line = ft_extract_line(&stash, nbytes);
	// printf("stash after ft_extract_line==%s\n", stash);
	// fflush(stdout);
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
char *ft_fill_stash(char *stash, int fd, char *buf, ssize_t *nbytes)
{
    char    	*tmp;

    //We fill the stash until we find a '\n' or EOF indicated by !nbytes
    while (!ft_strchr(stash, '\n'))
    {
        *nbytes = read(fd, buf, BUFFER_SIZE);
		// printf("buf==%s\n", buf);
		if (!*nbytes) //EOF -> we return stash
			return (stash);
		if (*nbytes == -1)
			return (NULL);
		buf[*nbytes] = '\0';
        tmp = ft_strdup(stash);
        if (!tmp)
            return (NULL);
        free (stash);
        stash = ft_strjoin(tmp, buf);
        if (!stash)
            return (NULL);
        free(tmp);
    }
	return (stash);
}
/* ************************************************************************** *
* If !nbytes then EOF then the return line is also the stash line
* If '\n' then we use ft_substr to get the line in the *stash, including
* the '\n', then we clean the *stash
* ************************************************************************** */
char *ft_extract_line(char **stash, ssize_t nbytes)
{
	char	*line;
	char	*tmp;
	int		i;

    if (!nbytes)
	{
		//(*stash)[ft_strlen(*stash)] = '\0'; //check if it works w/o since strjoin
		// in ft_fill_stash already adds a '\0' 
		return (*stash);
	}
	i = 0;
	while ((*stash)[i] != '\n')
		i++;
	line = ft_substr(*stash, 0, i + 1); //len i + 1 to include the '\n'
	if (!line)
		return (NULL);
//we clean the stash, leaving only the characters after '\n'
	tmp = ft_strdup(ft_strchr(*stash, '\n') + 1); //tmp = ft_strdup(ft_strchr(*stash, '\n') + 1) puis *stash = tmp
	// printf("tmp ft_extract_line==%s\n", tmp);
	free(*stash);
	*stash = tmp;
	// printf("stash after cleaning in ft_extract_line==%s\n", *stash);
	if (!*stash)
		return (NULL);
	//line[ft_strlen(line)] = '\0'; //utile ? ft_substr already adds a '\0'
	return (line);
}
