#include "get_next_line.h"

int main(void)
{
	int fdes;
	char *line;
	int	i;

	i = 31;
	fdes = open("HP1.txt", O_RDONLY);
	line = get_next_line(fdes);
	// printf("get_next_line return==%s\n", line);
	// fflush(stdout);
	printf("%s", line);
	while (line)
	{
		line = get_next_line(fdes);
		// printf("get_next_line return==%s\n", line);
		// fflush(stdout);
		printf("%s", line);
		i--;
	}
	return (0);
}
