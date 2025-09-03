/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:00:03 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/08/06 13:32:18 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	copy_strings(char *dest, const char *s1, const char *s2,
		char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	if (c)
		dest[i++] = c;
	j = 0;
	while (s2[j])
	{
		dest[i + j] = s2[j];
		j++;
	}
	dest[i + j] = '\0';
}

/* ************************************************************************** *
 *			/!\\/!\\/!\\ Modified version /!\\/!\\/!\\
 *
 * The ft_strjoin function takes two C-style strings (s1 and s2), concatenates
 * them into a newly allocated string, and returns a pointer to the result.
 * If either input is NULL, it treats it as an empty string, and the function
 * returns NULL if memory allocation fails.
 *
 * Mods : `if c != 0` --> adds the char c between the joined strings
 * ***************************************************************************/
char	*ft_strjoin(char const *s1, char const *s2, char c)
{
	size_t	join_len;
	char	*join;

	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	if (c)
		join_len = ft_strlen(s1) + 1 + ft_strlen(s2);
	else
		join_len = ft_strlen(s1) + ft_strlen(s2);
	join = malloc(sizeof(char) * (join_len + 1));
	if (join == NULL)
		return (NULL);
	copy_strings(join, s1, s2, c);
	return (join);
}
