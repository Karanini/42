/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rip_training.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:00:19 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/11/27 17:25:51 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_check_balance(char *str, int start)
{
	int	i;
	int	open;
	int	close;

	i = start;
	open = 0;
	close = 0;
	while (str[i])
	{
		if (str[i] == '(')
			open++;
		else if (str[i] == ')')
		{
			close++;
			if (open - close < 0)
				return (open - close);
		}
		i++;
	}
	return (open - close);
}

void	ft_rec_rip(char *str, int i)
{
	int	bal;

	bal = ft_check_balance(str, i);
	if (!bal)
	{
		puts(str);
		return ;
	}
	else if (bal > 0)
	{
		while (str[i] && str[i] != '(')
			i++;
		if (!str[i])
			return ;
		ft_rec_rip(str, i + 1);
		str[i] = ' ';
		ft_rec_rip(str, i + 1);
		// if (!str[i])
		// 	return ;
		// else
		// 	str[i] = ' ';
		// while (str[i])
		// {
		// 	ft_rec_rip(str, i);
		// 	i++;
		// }
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	main(int argc, char *argv[])
{
	int	i;
	// int	len;

	if (argc != 2)
		return (1);
	i = 0;
	// len = ft_strlen(argv[1]);
	ft_rec_rip(argv[1], i);
	return (0);
}
