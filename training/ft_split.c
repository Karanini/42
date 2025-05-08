/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:57:57 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/05/02 15:53:30 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(char const *s, char c);
static void		ft_free(char **split);
static int		fill_words(char const *s, char c, size_t nb_words,
					char **split);

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

static int	fill_words(char const *s, char c, size_t nb_words, char **split)
{
	size_t	i;
	size_t	start_word;
	size_t	end_word;

	i = 0;
	start_word = 0;
	while (i < nb_words)
	{
		while (s[start_word] == c)
			start_word++;
		end_word = start_word + 1;
		while (s[end_word] && s[end_word] != c)
			end_word++;
		split[i] = ft_substr(s, start_word, end_word - start_word);
		if (split[i] == NULL)
			return (ft_free(split), -1);
		start_word = end_word + 1;
		i++;
	}
	split[i] = NULL;
	return (0);
}

static size_t	word_count(char const *s, char c)
{
	size_t	i;
	size_t	nb_words;

	i = 0;
	nb_words = 0;
	if (!s)
		return (nb_words);
	while (s[i])
	{
		if (s[i] != c)
		{
			nb_words++;
			i++;
		}
		while (s[i] && s[i] != c)
			i++;
		while (s[i] && s[i] == c)
			i++;
	}
	return (nb_words);
}

static void	ft_free(char **split)
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
