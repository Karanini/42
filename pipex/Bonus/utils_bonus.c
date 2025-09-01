/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 14:11:51 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/08/29 13:21:16 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

/**
 * Checks if the given command name is not valid.
 *
 * @param cmd_name A pointer to the command name string to validate.
 * @return Non-zero value if the command name is not valid, 0 otherwise.
 */
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
