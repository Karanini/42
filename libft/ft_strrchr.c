/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:05:03 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/04/23 16:05:05 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	size_t	s_len;

	s_len = ft_strlen(s);
	i = s_len;
	if (c == '\0')
		return ((char *)(s + s_len));
	while (i > 0)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}

/*int	main(int argc, char *argv[])
{
	(void)argc;
	printf("chaine trouvee : %s\n", ft_strrchr(argv[1], argv[2][0]));
	return (0);
}*/		
