

int	main(void)
{
	int	fd1[2];
	int	fd2[2];

	pipe(fd1);
	fork();
	pipe(fd2);
	fork();
	return(0);
}
