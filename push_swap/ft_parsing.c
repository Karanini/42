/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 14:44:44 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/07/28 14:35:49 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_char_checker(char *str);
static int	ft_duplicate_checker(char *tab_str[]);
static char	*ft_join_all_args(int argc, char *argv[]);

/*
Parsing of the input args. Checks for unauthorized chars and double values.
We assume that argc >= 2
*/
char	**ft_parsing(int argc, char *argv[], size_t *total_size)
{
	int		i;
	char	**tab_str;
	char	*join;

	i = 1;
	while (i < argc)
	{
		if (!ft_char_checker(argv[i]))
			return (NULL);
		i++;
	}
	join = ft_join_all_args(argc, argv);
	if (!join)
		return (NULL);
	*total_size = word_count(join, 32);
	tab_str = ft_split(join, 32);
	if (!tab_str)
		return (free(join), NULL);
	free(join);
	if (ft_duplicate_checker(tab_str))
		return (ft_free_tab_str(tab_str), NULL);
	return (tab_str);
}

static char	*ft_join_all_args(int argc, char *argv[])
{
	char	*join;
	int		i;
	char	*tmp;

	i = 1;
	join = ft_strdup(argv[i++]);
	if (!join)
		return (NULL);
	while (i < argc)
	{
		tmp = ft_strdup(join);
		if (!tmp)
			return (free(join), NULL);
		free(join);
		join = ft_strjoin(tmp, argv[i++]);
		if (!join)
			return (free(tmp), NULL);
		free(tmp);
	}
	// ft_printf("join : %s\n", join);
	return (join);
}

static int	ft_char_checker(char *str)
{
	int	i;
	int	only_32;

	i = 0;
	only_32 = 1;
	while (str[i])
	{
		if ((!ft_isdigit(str[i]) && str[i] != 32 && str[i] != '+'
				&& str[i] != '-')
				|| (str[i] == '-' && !str[i + 1])
				|| (str[i] == '+' && !str[i + 1])
				|| (str[i] == '-' && str[i + 1] && !ft_isdigit(str[i + 1]))
				|| (str[i] == '+' && str[i + 1] && !ft_isdigit(str[i + 1])))
			return (0);
		if (str[i] != 32)
			only_32 = 0;
		i++;
	}
	if (only_32)
		return (0);
	return (1);
}

static int	ft_duplicate_checker(char *tab_str[])
{
	int	i;
	int	j;

	i = 0;
	while (tab_str[i])
	{
		j = i + 1;
		while (tab_str[j])
		{
			if (!ft_strcmp(tab_str[i], tab_str[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_free_tab_str(char **split)
{
	size_t	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
