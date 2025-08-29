/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:57:57 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/08/29 17:15:50 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	fill_words(char const *s, char c, size_t nb_words, char **split);
static void	word_count_single_quotes(char const *s, size_t *i,
				size_t *nb_words);
/*
 * MODIFIED VERSION to take into account arguments between single quotes
 * as one word.
 * Edge case not working at the moment (necessary for minishell):
 * when a non-32 char directly follows or precedes the '  '.
 * In this case -d'=' should become -d=
 *
 * UNSPECIFIED BEHAVIOR if a single quote is not closed by another single
 * quote (not to be treated in the minishell project)
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
		if (s[start_word] == '\'') //move lines following condition to another function ?
		{
			c = '\'';
			start_word++;
		}
		while (s[end_word] && s[end_word] != c)
			end_word++;
		split[i] = ft_substr(s, start_word, end_word - start_word);
		if (split[i] == NULL)
			return (free_tab(split), -1);
		start_word = end_word + 1;
		i++;
		c = og_separator;
	}
	return (split[i] = NULL, 0);
}

/*
 * MODIFIED VERSION to take into account arguments between single quotes
 * as one word.
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
			word_count_single_quotes(s, &i, &nb_words);
		while (s[i] && s[i] != c)
			i++;
		while (s[i] && s[i] == c)
			i++;
	}
	return (nb_words);
}
/*
* @brief counts a word delimited by single quotes. UNSPECIFIED BEHAVIOR if a
* single quote is not closed by another single quote (not to be treated in the
* minishell project)
*/
static void	word_count_single_quotes(char const *s, size_t *i, size_t *nb_words)
{
		(*i)++;
		while (s[*i] && s[*i] != '\'')
			(*i)++;
		if (s[*i] == '\'')
			(*i)++;
		(*nb_words)++;
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
// 	printf("%s\n", tab_split[i]);
// 	while (tab_split[i])
// 	{
// 		printf("word number %d : %s\n", i, tab_split[i]);
// 		i++;
// 	}
// 	return (0);
// }
