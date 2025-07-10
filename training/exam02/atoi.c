





int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == 32 || (str[i] >= '\b' && str[i] <= '\r'))
		i++;
	if (str[i] == '+')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - 48;
		i++;
	}
	return (sign * res);
}

#include<stdio.h>

int	main(int argc, char *argv[])
{
	(void)argc;
	int	nbr = ft_atoi(argv[1]);
	printf("%d\n", nbr);
	return(0);
}
