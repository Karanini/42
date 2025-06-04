#include "get_next_line.h"

/* ************************************************************************** *
The ft_strchr function searches for the first occurrence of the character c
* (converted to an unsigned char) in the string s. It returns a pointer to the
* located character in the string or NULL if the character is not found;
* if c is '\0', it returns a pointer to the null terminator of the string.
* ***************************************************************************/
char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	ch;

	ch = (unsigned char)c;
	i = 0;
	if (!s || !c)
		return (NULL);
	while (s[i])
	{
		if (s[i] == ch)
			return ((char *)(s + i));
		i++;
	}
	if (ch == '\0')
		return ((char *)(s + i));
	return (NULL);
}
/* ************************************************************************** *
* The ft_substr function creates and returns a new null-terminated substring
* from the given string s, starting at the specified index start and with a
* maximum length of len. If s is NULL or start exceeds the length of s, the
* function returns either NULL or an empty string, and it dynamically
* allocates memory for the substring, which must be freed by the caller.
* ************************************************************************** */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;
	size_t	subs_len;

	subs_len = 0;
	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	while (s[start + subs_len] && subs_len < len)
		subs_len++;
	subs = malloc(sizeof(char) * (subs_len + 1));
	if (subs == NULL)
		return (NULL);
	while (i < subs_len)
	{
		subs[i] = s[start + i];
		i++;
	}
	subs[i] = '\0';
	return (subs);
}
static void	copy_strings(char *dest, const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		dest[i + j] = s2[j];
		j++;
	}
	dest[i + j] = '\0';
}
/* ************************************************************************** *
* The ft_strjoin function takes two C-style strings (s1 and s2), concatenates
* them into a newly allocated string, and returns a pointer to the result.
* If either input is NULL, it treats it as an empty string, and the function
* returns NULL if memory allocation fails.
* ************************************************************************** */
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	join_len;
	char	*join;

	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	join_len = ft_strlen(s1) + ft_strlen(s2);
	join = malloc(sizeof(char) * (join_len + 1));
	if (join == NULL)
		return (NULL);
	copy_strings(join, s1, s2);
	return (join);
}
/* ************************************************************************** *
* The ft_strdup function creates a duplicate of the input string s by
* allocating memory for the new string, copying the characters from the
* original string, and appending a null terminator. If memory allocation
* fails, the function returns NULL.
* added if !s return NULL for GNL
* ************************************************************************** */
char	*ft_strdup(const char *s)
{
	char	*s_c;
	size_t	s_len;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	s_c = malloc(sizeof(char) * (s_len + 1));
	if (s_c == NULL)
		return (NULL);
	while (s[i])
	{
		s_c[i] = s[i];
		i++;
	}
	s_c[i] = '\0';
	return (s_c);
}
