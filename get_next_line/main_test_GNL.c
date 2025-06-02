#include "get_next_line.h"

int main(void)
{
	int fdes;
	char *line;
	// int	i;

	// i = 31;
	fdes = open("gnlTester_files/nl", O_RDWR);
	line = get_next_line(fdes);
	printf("%s", line);
	free(line);
	fflush(stdout);
	line = get_next_line(fdes);
	printf("%s", line);
	free(line);
	close(fdes);
	// while (line)
	// {
	// 	line = get_next_line(fdes);
	// 	// printf("get_next_line return==%s\n", line);
	// 	// fflush(stdout);
	// 	printf("%s", line);
	// 	if (line)
	// 		free(line);
	// 	i--;
	// }
	return (0);
}
