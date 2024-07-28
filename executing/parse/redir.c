#include "parsing.h"

int	input_redirection(char *file1)
{
	int	fd;

	fd = open(file1, O_RDONLY);
	if (fd < 0)
		return (error_nofile(file1));
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (1);
}