void    *ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char *s;
	unsigned char *d;
	size_t	i;

	i = 0;
	s = (const unsigned char *)src;
	d = (unsigned char)dest;

	if (d == s || n == 0)
		return (d);
	if (d < s)
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	if (d > s)
	{
		i = n;
		while (i > 0)
		{
			d[i] = s[i];
			i--;
		}
	}
	return (d);
}
