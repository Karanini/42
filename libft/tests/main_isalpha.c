#include "libft.h"
#include <stdio.h>

int	main(void)
{
	printf("'a' - 1 = %d\n", ft_isalpha('a' - 1));
	printf("'z' + 1 = %d\n", ft_isalpha('z' + 1));
	printf("'A' = %d\n", ft_isalpha('A'));
	printf("'Z' + 1 = %d\n", ft_isalpha('Z' + 1));
	return(0);
}
