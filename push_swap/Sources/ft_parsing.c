/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 14:44:44 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/07/30 14:46:59 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_char_checker(char *str);
static char	*ft_join_all_args(int argc, char *argv[]);

/*
Parsing of the input args. Checks for unauthorized chars. Duplicates are checked
later. We assume that argc >= 2 (argc == 1 checked in the main.c)

@return On success, an array of strings containing the numbers,
in the following format : "x" or "-x" or "+x"

NULL if a malloc error occurs or if the parsing detects unauthorized chars
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
		join = ft_strjoin(tmp, argv[i++], 1);
		if (!join)
			return (free(tmp), NULL);
		free(tmp);
	}
	return (join);
}

/**
 * @brief Checks if the given string contains only valid characters.
 *
 * This static function inspects the input string and determines whether
 * all characters meet the required criteria (e.g., digits, signs, etc.).
 *
* The function uses a local variable `only_32` that checks if the string
 * contains only whitespaces (ASCII 32). For example: "   "
 *
 * @param str Pointer to the null-terminated string to check.
 * @return int Returns 1 if the string contains only valid characters,
 * 0 otherwise.
 */
static int	ft_char_checker(char *str)
{
	int	i;
	int	only_32;

	i = 0;
	only_32 = 1;
	while (str[i])
	{
		if ((!ft_isdigit(str[i]) && str[i] != 32 && str[i] != '+'
				&& str[i] != '-') || ((str[i] == '-' || str[i] == '+') && !str[i
					+ 1]) || ((str[i] == '-' || str[i] == '+') && str[i + 1]
				&& !ft_isdigit(str[i + 1])) || ((str[i] == '-' || str[i] == '+')
				&& ft_isdigit(str[i - 1])))
			return (0);
		if (str[i] != 32)
			only_32 = 0;
		i++;
	}
	if (only_32)
		return (0);
	return (1);
}

/**
 * Frees a dynamically allocated array of strings.
 *
 * This function iterates through the given null-terminated array of strings
 * and frees each individual string, then frees the array itself.
 *
 * @param split A null-terminated array of strings to be freed.
 */
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
