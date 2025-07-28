/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:59:55 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/07/28 17:27:16 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* ************************************************************************** *
			/!\\/!\\/!\\ Modified version for push_swap /!\\/!\\/!\\

* The ft_strdup function creates a duplicate of the input string s by
* allocating memory for the new string, copying the characters from the
* original string, and appending a null terminator. If memory allocation
* fails, the function returns NULL.
*
Mods for push_swap (to normalize the list to be able to identify duplicates
* afterwards):
*
* (1) adds a whitespace 32 instead of a '+' sign for each number
* (2) adds a whitespace 32 instead of a '-' sign only before 0
* ************************************************************************** */
char	*ft_strdup(const char *s)
{
	char	*s_c;
	size_t	s_len;
	size_t	i;

	i = 0;
	s_len = ft_strlen(s);
	s_c = malloc(sizeof(char) * (s_len + 1));
	if (s_c == NULL)
		return (NULL);
	while (s[i])
	{
		if (s[i] == '+' || (s[i] == '-' && s[i + 1] && s[i + 1] == '0'))
			// || (s[i] == '0' && s[i + 1] && s[i + 1] == '0'))
			s_c[i] = 32;
		else
			s_c[i] = s[i];
		i++;
	}
	s_c[i] = '\0';
	return (s_c);
}
