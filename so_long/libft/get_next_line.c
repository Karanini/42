/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:13:10 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/09/04 10:12:53 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*cooking_stash(int fd, char *buff, char *stash,
				ssize_t *read_bytes);
static char	*extract_and_clean(char **stash);
static int	ft_find_the_nl(char *str);

/**
 * Reads a line from the given file descriptor.
 *
 * This function reads characters from the file descriptor `fd` until a newline
 * character is encountered or the end of file is reached. The returned string
 * includes the newline character if one was read. Memory for the returned string
 * is dynamically allocated and should be freed by the caller.
 *
 * @param fd The file descriptor to read from.
 * @return A pointer to the newly allocated string containing the line read,
 *         or NULL if there is nothing more to read or an error occurs.
 */
/* ************************************************************************** *
* 1. on verifie que fd et BUFFER_SIZE sont valides
2. on malloc buff
3. on prepare le stash avec cooking_stash()
4. on recupere line et on nettoie stash avec extract_and_clean()
5. on free buff et on return line
* ************************************************************************** */
char	*get_next_line(int fd)
{
	ssize_t		read_bytes;
	char		*buff;
	static char	*stash = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	read_bytes = 1;
	stash = cooking_stash(fd, buff, stash, &read_bytes);
	if (!stash)
		return (free(buff), NULL);
	line = extract_and_clean(&stash);
	if (!line)
		return (free(buff), NULL);
	if (stash && read_bytes == 0)
	{
		free(stash);
		stash = NULL;
	}
	return (free(buff), line);
}

/* ************************************************************************** *
* fonction cooking_stash()
1a. on lit le fichier avec read() et on stocke les caracteres dans buffer
1b. si erreur de read() on free stash et on return NULL
1c. on ajoute '\0' a la fin de buff
1d. on stocke l'ancienne valeur de stash dans tmp puis on free stash
1e. on redefinit stash en concatenant tmp et buff
1f. on free tmp
2. on repete tant que :
- stash ne contient pas de '\n'
- ET qu'on ne soit pas a la fin du fichier (EOF check : return de read == 0)
* ************************************************************************** */
static char	*cooking_stash(int fd, char *buff, char *stash, ssize_t *read_bytes)
{
	char	*tmp;

	while (!ft_strchr(stash, '\n'))
	{
		*read_bytes = read(fd, buff, BUFFER_SIZE);
		if (*read_bytes < 0)
			return (free(stash), stash = NULL, NULL);
		if (*read_bytes == 0)
		{
			if (stash && stash[0] == '\0')
				return (free(stash), stash = NULL, NULL);
			return (stash);
		}
		buff[*read_bytes] = '\0';
		tmp = ft_strdup(stash);
		if (stash && !tmp)
			return (free(stash), stash = NULL, NULL);
		free(stash);
		stash = ft_strjoin(tmp, buff, 0);
		if (!stash)
			return (free(tmp), NULL);
		free(tmp);
	}
	return (stash);
}

/* ************************************************************************** *
* fonction extract_and_clean()
3. si '\n' dans stash :
3a. on recupere line dans stash AVEC le '\n'
3b. on nettoie stash cad on recupere le ptr vers la chaine de caracteres
juste apres '\n'
3c. on return line
4. si EOF cad pas de '\n' dans le stash
4a. on assigne stash a line
4b. on free stash et on le fixe a NULL
4c. on return line
* ************************************************************************** */
static char	*extract_and_clean(char **stash)
{
	int		i;
	char	*line;
	char	*tmp;

	if (!stash || !*stash)
		return (NULL);
	i = ft_find_the_nl(*stash);
	if (i >= 0)
	{
		line = ft_substr(*stash, 0, i + 1);
		tmp = ft_strdup(*stash + i + 1);
		if (!line || !tmp)
			return (free(*stash), *stash = NULL, NULL);
		free(*stash);
		*stash = tmp;
	}
	else
	{
		line = ft_strdup(*stash);
		if (!line)
			return (free(*stash), *stash = NULL, NULL);
		free(*stash);
		*stash = NULL;
	}
	return (line);
}

static int	ft_find_the_nl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
