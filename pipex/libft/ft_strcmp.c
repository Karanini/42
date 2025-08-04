/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 18:14:32 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/07/18 18:33:38 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Compares two null-terminated strings lexicographically.
 *
 * @param str1 Pointer to the first string to compare.
 * @param str2 Pointer to the second string to compare.
 * @return An integer less than, equal to, or greater than zero if str1 is found,
 *         respectively, to be less than, to match, or be greater than str2.
 */
int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] && str2[i] && str1[i] == str2[i])
		i++;
	return (str1[i] - str2[i]);
}
