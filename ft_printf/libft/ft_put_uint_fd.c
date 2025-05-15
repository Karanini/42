
#include "libft.h"

static void	ft_put_unsigned(unsigned int n, int fd)
{
	if (n >= 10)
	{
		ft_put_unsigned(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
	else
	{
		ft_putchar_fd(n + '0', fd);
	}
}

int	ft_put_uint_fd(unsigned int n, int fd)
{
	int len = 1;
	unsigned int tmp = n;
	while (tmp >= 10)
	{
		tmp /= 10;
		len++;
	}
	ft_put_unsigned(n, fd);
	return (len);
}

