/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:16:23 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/04/23 10:31:59 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_is_negative(int n)
{
	if (n < 0)
		ft_putchar('N');
	else
		ft_putchar('P');
}

/*int	main(void)
{
	printf("32 is ");
	fflush(stdout); 
on flush cad on vide le buffer pour que le "32 is" se printe avant le resultat 
de ft_is_negative
	ft_is_negative(32);
	printf("\n");
	printf("-32 is ");
	fflush(stdout);
	ft_is_negative(-32);
	printf("\n");
	printf("0 is ");
	fflush(stdout);
	ft_is_negative(0);
	printf("\n");
	return (0);
}*/
