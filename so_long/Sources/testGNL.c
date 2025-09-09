
# include "libft.h"
# include "fcntl.h"

int main (int argc, char *argv[])
{
	int	fd;
	char	*line;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	ft_printf("%s", line);
	line = get_next_line(fd);
	ft_printf("%s", line);
	line = get_next_line(fd);
	ft_printf("%s", line);
	line = get_next_line(fd);
	ft_printf("%s", line);
	line = get_next_line(fd);
	ft_printf("%s", line);
	line = get_next_line(fd);
	ft_printf("%s", line);
	line = get_next_line(fd);
	ft_printf("%s", line);
}
