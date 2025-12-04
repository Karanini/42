/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rip_training.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:00:19 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/12/04 18:07:05 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str);

int	ft_check_balance(char *str)
{
	int	i;
	int	open;
	int	close;

	i = 0;
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

void	ft_rec_rip(char *str, int i, int len)
{
	int	bal;

	if (i > len)
		return ;
	bal = ft_check_balance(str);
	if (!bal)
		puts(str);
	else
	{
		if (str[i] == '_')
			str[i] = '(';
		ft_rec_rip(str, i + 1, len);
		if (str[i] == '(')
			str[i] = '_';
		ft_rec_rip(str, i + 1, len);
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
	int	len;

	if (argc != 2)
		return (1);
	i = 0;
	len = ft_strlen(argv[1]);
	printf("balance=%d\n", ft_check_balance(argv[1]));
	ft_rec_rip(argv[1], i, len);
	return (0);
}
