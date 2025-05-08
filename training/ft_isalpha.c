/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:46:11 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/04/30 17:16:41 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

// int	main(int argc, char** argv)
// {
// 	if (argc == 2)
// 	{
// 		printf("resultat : %d\n", ft_isalpha(argv[1][0]));
// 		return (0);
// 	}
// }
