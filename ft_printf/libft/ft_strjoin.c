/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:00:03 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/04/30 17:20:27 by bkaras-g         ###   ########.fr       */
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
		dest[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		dest[i + j] = s2[j];
		j++;
	}
	dest[i + j] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	join_len;
	char	*join;

	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	join_len = ft_strlen(s1) + ft_strlen(s2);
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
