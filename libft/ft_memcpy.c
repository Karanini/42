#include <stdio.h>

void	*ft_memcpy(void* dest, const void* src, size_t n)
{
	unsigned char	*d;
	const unsigned char	*s;
	size_t	i;

	i = 0;
	d = (unsigned char *) dest;
	s = (const unsigned char *) src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

int	main(void)
{
	int d[] = {0, 0, 0};
	int s[] = {32, 32, 32};
	int i = 0;

	ft_memcpy(d, s, sizeof(int) * 3);
	while (i < 3)
	{
		printf("%d\n", d[i]);
		i++;
	}
	return (0);
}
