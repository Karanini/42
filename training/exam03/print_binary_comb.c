/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_binary_comb.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 10:40:53 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/12/05 10:49:39 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#define NB_DIGITS 4

void	rec_print(char *str, int i, int nb_digits)
{
	if (i == nb_digits)
		puts(str);
	else
	{
		str[i] = '0';
		rec_print(str, i + 1, nb_digits);
		str[i] = '1';
		rec_print(str, i + 1, nb_digits);
	}
}

int		main(void)
{
	char *str;

	str = malloc(sizeof(char) * (NB_DIGITS + 1));
	if (!str)
		return (1);
	rec_print(str, 0, NB_DIGITS);
	return (0);
}
