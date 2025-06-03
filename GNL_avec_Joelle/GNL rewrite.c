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
buff
stash
* ************************************************************************** */

/* ************************************************************************** *
* 1a. on lit le fichier avec read() et on stocke les caracteres dans buffer
1b. si erreur de read() return NULL
2. on alimente stash avec buffer tant que :
- il ne contient pas de '\n'
- ET qu'on ne soit pas a la fin du fichier (EOF check : return de read == 0)
3. si '\n' dans stash :
3a. on recupere line dans stash AVEC le '\n'
3b. on nettoie stash cad on recupere le ptr vers la chaine de car juste apres '\n'
3c. on free buff et on return line
4. si EOF cad read_bytes == 0
4a. on free buff et on return stash

* ************************************************************************** */
char	*get_next_line(int fd)
{
	int	read_bytes;
	char *buff;
	static char	*stash = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return (NULL);
	}
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);

	read_bytes = 1;
	stash = cooking_line(fd, buff, stash, &read_bytes);


}

/* ************************************************************************** *
* fonction cooking_line()
1a. on lit le fichier avec read() et on stocke les caracteres dans buffer
1b. si erreur de read() return NULL
2. on alimente stash avec buffer tant que :
- il ne contient pas de '\n'
- ET qu'on ne soit pas a la fin du fichier (EOF check : return de read == 0)
RETURN read_bytes ou stash ???
* ************************************************************************** */
char	*cooking_line(int fdd, char *buff, char *stash, int *ptr_vers_read_bytes)
{
	*ptr_vers_read_bytes = read(fd, buff, BUFFER_SIZE);

	return (stash);
}

/* ************************************************************************** *
* fonction extract_and_clean()
3. si '\n' dans stash :
3a. on recupere line dans stash AVEC le '\n'
3b. on nettoie stash cad on recupere le ptr vers la chaine de car juste apres '\n'
3c. on free buff et on return line
4. si EOF cad read_bytes == 0
4a. on free buff et on return stash
* ************************************************************************** */
