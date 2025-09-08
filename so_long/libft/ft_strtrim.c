/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:05:23 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/09/08 15:41:55 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strtrim_one_char(char const *s1, char const *set);

static int	ft_char_in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		else
			i++;
	}
	return (0);
}

/**
 * @brief Trims all characters from the beginning and end of the string 's1'
 *        that are present in the string 'set'.
 *
 * This function allocates and returns a copy of 's1' with the characters
 * specified in 'set' removed from the start and end of the string.
 *
 * Update 09/08/25 : handles correctly the `strlen(s1) == 1` edge case
 *
 * @param s1  The string to be trimmed.
 * @param set The set of characters to trim from 's1'.
 * @return A new trimmed string, or NULL if the allocation fails.
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start_trim;
	size_t	end_trim;
	size_t	trim_len;
	char	*str_trim;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	else if (ft_strlen(s1) == 1)
		return (ft_strtrim_one_char(s1, set));
	start_trim = 0;
	end_trim = ft_strlen(s1) - 1;
	while (ft_char_in_set(s1[start_trim], set) == 1)
		start_trim++;
	while (ft_char_in_set(s1[end_trim], set) == 1)
		end_trim--;
	if (start_trim > end_trim)
		return (ft_strdup(""));
	trim_len = end_trim - start_trim + 1;
	str_trim = ft_substr(s1, start_trim, trim_len);
	return (str_trim);
}

static char	*ft_strtrim_one_char(char const *s1, char const *set)
{
	if (ft_char_in_set(s1[0], set))
		return (ft_strdup(""));
	else
		return (ft_strdup(s1));
}
