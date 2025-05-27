#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int	fdes;
	char	*buff;
	ssize_t	bytes_read;
	int	nbytes;

	nbytes = 10;

	fdes = open("32.txt", O_RDONLY);
	buff = malloc(sizeof(char) * nbytes);
	if (buff == NULL)
		return (1);
	bytes_read = 0;
	do
	{
		bytes_read = read(fdes, buff, nbytes);
		printf("%s", buff);
	} while (bytes_read);
	printf("%zd\n", bytes_read);
	bytes_read = read(fdes, buff, nbytes);
	printf("%zd\n", bytes_read);
	return (0);
}
