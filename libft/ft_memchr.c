void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*s1;
	unsigned char	c1;
	size_t	i;

	s1 = (const unsigned char *)s;
	c1 = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (s1[i] == c)
			return ((unsigned char *)(s1 + i));
		i++;
	}
	return (NULL);
}
