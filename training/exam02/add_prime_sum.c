


#include <unistd.h>
#include <stdio.h>

//number is positive or 0
int	ft_atoi(char *str)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - 48;
		i++;
	}
	return (res);
}

void	ft_putnbr(int nbr)
{
	char	c;

	c = 0;
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	c = nbr % 10 + 48;
	write(1, &c, 1);
}

int	main(int ac, char *av[])
{
	int	nbr;
	int	res;
	int	i;
	int	prime;

	/*int test = ft_atoi(av[1]);
	printf("atoi : %d\n", test);
	ft_putnbr(test);
	write(1, "\n", 1);*/

	if (ac != 2 || av[1][0] == '-')
	{
		write(1, "0\n", 2);
		return (0);
	}
	nbr = ft_atoi(av[1]);
	res = 0;
	i = 0;
	while (nbr > 1)
	{
		prime = 1;
		i = nbr - 1;
		while (i > 1)
		{
			if (nbr % i == 0)
				prime = 0;
			i--;
		}
		if (prime)
			res += nbr;
		nbr--;
	}
	ft_putnbr(res);
	write(1, "\n", 1);
	return (0);
}	
