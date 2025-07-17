/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:05:45 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/05/01 13:15:04 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* ************************************************************************** *
* The ft_substr function creates and returns a new null-terminated substring 
* from the given string s, starting at the specified index start and with a 
* maximum length of len. If s is NULL or start exceeds the length of s, the 
* function returns either NULL or an empty string, and it dynamically 
* allocates memory for the substring, which must be freed by the caller.
* ************************************************************************** */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;
	size_t	subs_len;

	subs_len = 0;
	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	while (s[start + subs_len] && subs_len < len)
		subs_len++;
	subs = malloc(sizeof(char) * (subs_len + 1));
	if (subs == NULL)
		return (NULL);
	while (i < subs_len)
	{
		subs[i] = s[start + i];
		i++;
	}
	subs[i] = '\0';
	return (subs);
}

/*int	main(int argc, char **argv)
{
	unsigned int	start;
	size_t			len;

	(void)argc;
	start = ft_atoi(argv[2]);
	len = ft_atoi(argv[3]);
	printf("subs : %s", ft_substr(argv[1], start, len));
	return (0);
}

int	main(void)
{
	printf("subs : %s", ft_substr('\0', 0, 1));
	return (0);
}*/
