/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:59:14 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/05/07 14:49:55 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* ************************************************************************** *
The ft_strchr function searches for the first occurrence of the character c
* (converted to an unsigned char) in the string s. It returns a pointer to the
* located character in the string or NULL if the character is not found; 
* if c is '\0', it returns a pointer to the null terminator of the string.
* ***************************************************************************/
char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	ch;

	ch = (unsigned char)c;
	i = 0;
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

// #include <stdio.h>

// int main(void)
// {
// 	printf("%s\n", ft_strchr("teste",'\0'));
// 	return (0);
// }
