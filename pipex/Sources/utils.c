/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 14:11:51 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/08/27 14:23:16 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_cmd_name_not_valid(char *cmd_name)
{
	size_t	i;

	i = 0;
	while (cmd_name[i])
	{
		if (cmd_name[i] != 32 && cmd_name[i] != '\'')
			return (0);
		i++;
	}
	return (1);
}
