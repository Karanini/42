
#include <unistd.h>

int	main(void)
{
	unsigned char c = 33;

	while (c < 150)
	{
		write(1, &c, 1);
		c++;
	}
	return (0);
}
