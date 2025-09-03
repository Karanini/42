/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:59:14 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/07/30 14:37:02 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* ************************************************************************** *
The ft_strchr function searches for the first occurrence of the character c
* (converted to an unsigned char) in the string s.

@return A pointer to the
* located character in the string or NULL if !s or if
the character is not found;
* if c is '\0', it returns a pointer to the null terminator of the string.
*
* Added if !s return NULL for GNL
* ***************************************************************************/
char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	ch;

	ch = (unsigned char)c;
	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == ch)
			return ((char *)(s + i));
		i++;
	}
	if (ch == '\0')
		return ((char *)(s + i));
	return (NULL);
}
