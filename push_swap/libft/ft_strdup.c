/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:59:55 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/07/29 11:53:50 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* ************************************************************************** *
* The ft_strdup function creates a duplicate of the input string s by
* allocating memory for the new string, copying the characters from the
* original string, and appending a null terminator. If memory allocation
* fails, the function returns NULL.
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
			s_c[i] = s[i];
		i++;
	}
	s_c[i] = '\0';
	return (s_c);
}
