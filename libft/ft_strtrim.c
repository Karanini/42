char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	set_len;
	size_t	nb_set;
	size_t	jump;
	size_t	trim_len;
	char	*trim;

	if (!s1)
		s1 = "";
	if (!set)
		set = "";
	set_len = ft_strlen(set);
	nb_set = 0;
	i = 0;
	jump = 0;
	if (ft_strnstr(s1, set, set_len) == 1)
	{
		jump = set_len;
		nb_set = 1;
	}
	if (ft_strnstr((s1 + jump), set, ft_strlen(s1) - jump) == 1)
		nb_set = 2;
	trim_len = ft_strlen(s1) - (nb_set * set_len);
	trim = malloc(sizeof(char) * (trim_len + 1));
	if (trim == NULL)
		return (NULL);
	while (i < trim_len)
	{
		trim[i] = s[jump + i];
		i++;
	}
	trim[i] = '\0';
	return (trim);
}
