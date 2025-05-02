/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc_commented.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:47:32 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/04/30 17:14:21 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total_size;

	total_size = nmemb * size;
	// on ecrit comme ca sinon nmemb
	//	* size risque d'overflow avant la comparaison a SIZE_MAX
	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	// pas la peine de verifier si nmemb ou size valent 0 car La norme C autorise calloc(0,
	//	x) ou calloc(x, 0), qui peut retourner soit NULL,
	//	soit un pointeur unique utilisable (tant qu’on ne le déréférence pas).
	// if (nmemb == 0 || size == 0)
	//	return (NULL);
	ptr = malloc(total_size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, (total_size));
	return (ptr);
}
