
# include <errno.h>
# include <unistd.h>
# include <stdio.h>

int	main(void)
{
	char *argv[4] = {"   ", "  ", "  ", NULL};
	execve(argv[0], argv, NULL);
	if (errno == ENOENT)
		printf("command not found");
	return (127);
}
