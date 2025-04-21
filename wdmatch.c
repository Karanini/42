
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (argv[1][i] && argv[2][j])
	{
		if (argv[1][i] == argv[2][j])
		{
			i++;
			j++;
		}
		else
			j++;
	}
	if (!argv[1][i])
		printf("%s\n", argv[1]);
	else
		printf("\n");
	return (0);
}
