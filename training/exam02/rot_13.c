












#include<unistd.h>

int	main(int argc, char *argv[])
{
	int	i;

	if (argc != 2)
	{
		write(0, "\n", 1);	
		return (0);
	}
	i = 0;
	while (argv[1][i])
	{
		if ((argv[1][i] >= 'a' && argv[1][i] <= 'm') || (argv[1][i] >= 'A' && argv[1][i] <= 'M'))
			argv[1][i] += 13;
		else if ((argv[1][i] >= 'n' && argv[1][i] <= 'z') || (argv[1][i] >= 'N' && argv[1][i] <= 'Z'))
			argv[1][i] -= 13;
		write(0, &argv[1][i], 1);
		i++;
	}
	write(0, "\n", 1);
	return (0);
}

