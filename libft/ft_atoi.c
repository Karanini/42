#include <stdio.h>

int	ft_atoi(const char *nptr)
{
	size_t	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13)
		|| nptr[i] == '+')
		i++;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res *= 10;
		res += nptr[i] - '0';
		i++;
	}
	return (res * sign);
}

/*int	main(void)
{
	char str_nb1[] = "-32";
	char str_nb2[] = "+42";
	char str_nb3[] = "3200000";

	int nb1 = ft_atoi(str_nb1);
	int nb2 = ft_atoi(str_nb2);
	int nb3 = ft_atoi(str_nb3);

	printf("nb1 = %d\n", nb1);	
	printf("nb2 = %d\n", nb2);	
	printf("nb3 = %d\n", nb3);
}*/
