/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:00:03 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/07/18 17:36:27 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	copy_strings(char *dest, const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s1[i])
	{
		if (s1[i] == '+' || (s1[i] == '-' && s1[i + 1] && s1[i + 1] == '0'))
			dest[i] = 32;
		else
			dest[i] = s1[i];
		i++;
	}
	dest[i++] = 32;
	j = 0;
	while (s2[j])
	{
		if (s2[j] == '+' || (s2[j] == '-' && s1[j + 1] && s1[j + 1] == '0'))
			dest[i + j] = 32;
		else
			dest[i + j] = s2[j];
		j++;
	}
	dest[i + j] = '\0';
}
/* ************************************************************************** *
*			/!\\/!\\/!\\ Modified version for push_swap /!\\/!\\/!\\
*
* The ft_strjoin function takes two C-style strings (s1 and s2), concatenates
* them into a newly allocated string, and returns a pointer to the result.
* If either input is NULL, it treats it as an empty string, and the function
* returns NULL if memory allocation fails.
*
* Mods for push_swap : (1) adds a whitespace 32 between the joined strings
* (2) adds a whitespace 32 instead of a '+' sign for each number and a '-' sign
* only before 0
* ************************************************************************** */
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	join_len;
	char	*join;

	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	join_len = ft_strlen(s1) + 1 + ft_strlen(s2);
	join = malloc(sizeof(char) * (join_len + 1));
	if (join == NULL)
		return (NULL);
	copy_strings(join, s1, s2);
	return (join);
}

// int	main(int argc, char **argv)
// {
// 	char	*s;

// 	if (argc == 3)
// 	{
// 		s = ft_strjoin(argv[1], argv[2]);
// 		printf("join : %s\n", s);
// 	}
// 	return (0);
// }
