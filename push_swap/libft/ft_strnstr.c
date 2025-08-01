/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:04:53 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/08/01 13:42:42 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Locates the first occurrence of the null-terminated string 'little'
 *        in the string 'big',
	where not more than 'len' characters are searched.
 *
 * This function searches for the first occurrence of the substring 'little'
 * within the first 'len' characters of the string 'big'. If 'little' is an
 * empty string, 'big' is returned; if 'little' occurs nowhere in 'big', NULL
 * is returned. If 'little' occurs within 'len' characters of 'big', a pointer
 * to the first character of the first occurrence is returned.
 *
 * @param big    The string to be searched.
 * @param little The substring to search for.
 * @param len    The maximum number of characters to search.
 * @return A pointer to the first occurrence of 'little' in 'big',
	or NULL if not found.
 */
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!little[j])
		return ((char *)(big));
	while (big[i] && i < len)
	{
		while (big[i + j] == little[j] && (i + j) < len)
		{
			j++;
			if (!little[j])
				return ((char *)(big + i));
		}
		j = 0;
		i++;
	}
	return (NULL);
}
