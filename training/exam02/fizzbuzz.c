
#include<unistd.h>

void	ft_putnbr(int i)
{
	char	nbr = ' ';

	if (i <= 9)
	{
		nbr = (char)(i + 48);
		write(0, &nbr, 1);
		return ;
	}
	else if (i >= 10)
	{
		nbr = i / 10 + 48;
		write(0, &nbr, 1);
		nbr = i % 10 + 48;
		write(0, &nbr, 1);
		return ;
	}
}


int	main(void)
{
	int	i;

	i = 1;
	while (i <= 100)
	{
		if (i % 3 == 0 && i % 5 ==0)
			write(0, "fizzbuzz", 8);
		else if (i % 3 == 0)
			write(0, "fizz", 4);
		else if (i % 5 == 0)
			write(0, "buzz", 4);
		else
			ft_putnbr(i);
		write(0, "\n", 1);
		i++;
	}
	return (0);
}
