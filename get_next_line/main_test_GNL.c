#include "get_next_line.h"

int main(void)
{
	int fdes;
	char *line;
	int	i;

	i = 4;
	fdes = open("32.txt", O_RDONLY);
	line = get_next_line(fdes);
	printf("get_next_line return==%s\n", line);
	fflush(stdout);
	while (i)
	{
		line = get_next_line(fdes);
		printf("get_next_line return==%s\n", line);
		fflush(stdout);
		i--;
	}
	return (0);
}
