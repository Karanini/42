/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GNL rewrite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:13:10 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/06/03 15:18:10 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/* ************************************************************************** *
* NOTE : APPELER LA CAF
Dans get_next_line : 
buff
stash

Dans cooking_stash : 
tmp
* ************************************************************************** */

/* ************************************************************************** *
* 1. on verifie que fd et BUFFER_SIZE sont valides
2. on malloc buff
3. on prepare le stash avec cooking_stash()
4. on recupere line et on nettoie stash avec extract_and_clean()
5. on free buff et on return line
* ************************************************************************** */
char	*get_next_line(int fd)
{
	ssize_t	read_bytes;
	char *buff;
	static char	*stash;
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return (NULL);
	}
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	read_bytes = 1;
	stash = cooking_stash(fd, buff, stash, &read_bytes);
	if (!stash)
		return (free(buff), NULL);
	line = extract_and_clean(&stash);
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
char	*cooking_stash(int fd, char *buff, char *stash, ssize_t *ptr_vers_read_bytes)
{
	char	*tmp;

	while (!ft_strchr(stash, '\n'))
	{
		*ptr_vers_read_bytes = read(fd, buff, BUFFER_SIZE);
		if (*ptr_vers_read_bytes < 0)
			return (free(stash), NULL);
		if (*ptr_vers_read_bytes == 0)
			return (stash);
		buff[*ptr_vers_read_bytes] = '\0';
		tmp = ft_strdup(stash); //besoin de gerer le cas !tmp (echec du malloc)
		free(stash);
		stash = ft_strjoin(tmp, buff); //besoin de gerer le cas !stash (echec du malloc)
		free(tmp);
	}
	return (stash);
}
size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/* ************************************************************************** *
* fonction extract_and_clean()
3. si '\n' dans stash :
3a. on recupere line dans stash AVEC le '\n'
3b. on nettoie stash cad on recupere le ptr vers la chaine de car juste apres '\n'
3c. on return line
4. si EOF cad pas de '\n' dans le stash
4a. on assigne stash a line
4b. on free line et on le fixe a NULL
4c. on return line
* ************************************************************************** */
char	*extract_and_clean(char **stash)
{
	int	i;
	char *line;
	char	*tmp;

	i = ft_find_the_nl(*stash);
	if (i >= 0) // '\n' dans stash 
	{
		line = ft_substr(*stash, 0, i + 1);
		if (!line)
			return (free(*stash), NULL);
		tmp = ft_strdup(*stash); //besoin de gerer le cas !tmp (echec du malloc)
		free(*stash);
		*stash = (ft_strchr(ft_strdup(tmp), '\n') + 1); //besoin de gerer le cas !*stash (echec du malloc)
		free(tmp);
	}
	else // '\n' not found --> EOF
	{
		line = ft_strdup(*stash); //besoin de gerer le cas !line (echec du malloc)
		free(*stash);
		*stash = NULL; 
	}
	return (line);
}

int ft_find_the_nl(char *str)
{
    int i = 0;
    while (str[i])
    {
        if (str[i] == '\n')  // test de comparaison
            return i;        // position du '\n'
        i++;
    }
    return -1;  // pas trouvé
}
