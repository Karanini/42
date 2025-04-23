/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:04:53 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/04/23 16:04:55 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

/*int	main(int argc, char *argv[])
{
	(void)argc;
	printf("res : %s\n", ft_strnstr(argv[1], argv[2], 8));
	//printf("res OG : %s\n", strnstr(argv[1], argv[2], 8));
	return (0);
}*/
