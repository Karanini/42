/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:57:57 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/08/18 17:30:32 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int		fill_words(char const *s, char c, size_t nb_words,
					char **split);
/*
* MODIFIED VERSION to take into account the '  ' argument as one word
*/
char	**ft_split(char const *s, char c)
{
	size_t	nb_words;
	char	**split;

	nb_words = word_count(s, c);
	split = malloc(sizeof(char *) * (nb_words + 1));
	if (split == NULL)
		return (NULL);
	if (fill_words(s, c, nb_words, split) == -1)
		return (NULL);
	return (split);
}
/* besoin de modifier fill_words pour prendre en compte le edge case ' ' passé
* en argument d'une commande */
static int	fill_words(char const *s, char c, size_t nb_words, char **split)
{
	size_t	i;
	size_t	start_word;
	size_t	end_word;
	char	og_separator;

	i = 0;
	og_separator = c;
	start_word = 0;
	while (i < nb_words)
	{
		while (s[start_word] && s[start_word] == c)
			start_word++;
		end_word = start_word + 1;
		if (s[start_word] == '\'')
			c = '\'';
		while (s[end_word] && s[end_word] != c)
			end_word++;
		if (c == '\'')
			split[i] = ft_substr(s, start_word, end_word - start_word + 1);
		else
			split[i] = ft_substr(s, start_word, end_word - start_word);
		if (split[i] == NULL)
			return (free_tab(split), -1);
		start_word = end_word + 1;
		i++;
		c = og_separator;
	}
	return (split[i] = NULL, 0);
}

	// if (s[start_word] == '\'')
	// 	{
	// 		while (s[end_word] && s[end_word++] != '\'')
	// 			end_word++;
	// 	}
	// 	else
	// 	{
/*
* MODIFIED VERSION to take into account the '  ' argument as one word
* edge case not working at the moment : when a non-32 char directly
* follows the '  ' the following word is not counted. For example '  'abc
* the word abc would not be counted.
*/
size_t	word_count(char const *s, char c)
{
	size_t	i;
	size_t	nb_words;

	i = 0;
	nb_words = 0;
	if (!s)
		return (nb_words);
	while (s[i])
	{
		if (s[i] != c && s[i] != '\'')
		{
			nb_words++;
			i++;
		}
		else if (s[i] == '\'')
		{
			while (s[i] == '\'')
			{
				i++;
				while (s[i] != '\'')
					i++;
				i++;
				nb_words++;
			}
		}
		while (s[i] && s[i] != c)
			i++;
		while (s[i] && s[i] == c)
			i++;
	}
	return (nb_words);
}

void	free_tab(char **split)
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

// int	main(int argc, char *argv[])
// {
// 	(void)argc;
// 	char **tab_split;
// 	int	i;

// 	printf("word count : %zu\n", word_count(argv[1], 32));
// 	tab_split = ft_split(argv[1], 32);
// 	i = 0;
// 	while (tab_split[i])
// 	{
// 		printf("word number %d : %s\n", i, tab_split[i]);
// 		i++;
// 	}
// 	return (0);
// }
