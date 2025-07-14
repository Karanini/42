


void	ft_sort(int tab[], int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = 0;
	tmp = 0;
	while (i < size)
	{
		j = i + 1;
		while (j > 0)
		{
			if (tab[j - 1] > tab[j])
			{
				tmp = tab[j - 1];
				tab[j - 1] = tab[j];
				tab[j] = tmp;
			}
			j--;
		}
		i++;
	}
}

#include <stdio.h>

int	main(void)
{
	int	tab[] = {320, -32, 32, 0, 230, -8000};
	ft_sort(tab, 6);
	for (int i=0; i < 6; i++)
		printf("%d, ", tab[i]);
	printf("\n");
	return (0);
}
