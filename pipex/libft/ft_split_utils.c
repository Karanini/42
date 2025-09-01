
#include "libft.h"

/*
* @brief counts a word delimited by single quotes. UNSPECIFIED BEHAVIOR if a
* single quote is not closed by another single quote (not to be treated in the
* minishell project)
*/
void	word_count_single_quotes(char const *s, size_t *i, size_t *nb_words)
{
		(*i)++;
		while (s[*i] && s[*i] != '\'')
			(*i)++;
		if (s[*i] == '\'')
			(*i)++;
		(*nb_words)++;
}

void    ft_change_sep_to_single_quote(char *c, size_t *start_word)
{
    *c = '\'';
    (*start_word)++;
}