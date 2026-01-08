/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:06:56 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/04/29 11:22:39 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t				s_len;
	char				*res;
	unsigned int		i;

	s_len = ft_strlen(s);
//si s ou f sont NULL on return NULL pour eviter un comportement indefini 	
	if (!s || !f)
		return (NULL);
	res = malloc(sizeof(char) * (s_len + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		res[i] = (*f)(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}

/*static char	ft_putp(unsigned int i, char c)
{
	 return (i + c);
}

int	main(void)
{
	char *strp = ft_strmapi("hello", &ft_putp);
	printf("strp : %s", strp);
	return (0);
}*/
