/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:57:57 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/04/30 16:10:39 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(char const *s, char c);
static void	ft_free(char **split, size_t nb_words);

char 	**ft_split(char const *s, char c)
{
	size_t	nb_words;
	char	**split;
	size_t	start_word;
	size_t	end_word;
	size_t	i;

	nb_words = word_count(s, c);
	split = malloc(sizeof(char*) * (nb_words + 1));
	if (split == NULL)
		return (NULL);
	start_word = 0;
	i = 0;
	while (i < nb_words)
	{
		while (s[start_word] == c)
			start_word++;
		end_word = start_word + 1;
		while(s[end_word] != c)
			end_word++;
		split[i] = ft_substr(s, start_word, end_word - start_word);
		if (split[i] == NULL)
		{
			ft_free(split, nb_words);
			return (NULL);
		}
		start_word = end_word + 1;
		i++;
	}
	split[i] = NULL;
	return (split);
}

static size_t	word_count(char const *s, char c)
{
	size_t	i;
	size_t	nb_words;
	size_t	c_present;

	i = 0;
	nb_words = 0;
	c_present = 0;
	//if (s[i] && (ft_strchr(s, c) == (s + ft_strlen(s)) 
	//	|| ft_strchr(s, c) == NULL))
	//	return (++nb_words);
	while (s[i])
	{
		while (s[i] == c)
		{
			i++;
			c_present = 1;
		}
		if (i >= 1 && s[i - 1] == c && s[i])
			nb_words++;
		if (s[i])
			i++;
	}
	if (nb_words == 0 && c_present == 0)
		nb_words++;
	return (nb_words);
}

static void	ft_free(char **split, size_t nb_words)
{
	size_t	i;

	i = 0;
	while (i < nb_words)
	{
		free(split[i]);
		i++;
	}
	free(split);
}


/*#include <stdio.h>

int	main(void)
{
	char **tab = ft_split("tripouille", 0);
	printf("tab[0]=%s\n", tab[0]);
	return (0);
}*/
