#include "main.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 *
 * @filename: name of the file
 * @letters: size of output to print
 *
 * Return: number of printed bytes or 0 if operation failed
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd, num_bytes, sz;
	char *buf;

	if (filename == NULL || letters == 0)
	{
		return (0);
	}

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		return (0);
	}

	buf = malloc(letters * sizeof(char));
	if (buf == NULL)
	{
		return (0);
	}
	sz = read(fd, buf, letters);
	if (sz == -1)
	{
		free(buf);
		close(fd);
		return (0);
	}
	if (sz != 0)
	{
		buf[sz + 1] = '\0';
	}
	else
	{
		buf[letters + 1] = '\0';
	}
	close(fd);

	num_bytes = write(STDOUT_FILENO, buf, letters);

	sz = strlen(buf);
	free(buf);

	if (num_bytes == -1) /* writing to stdout failed */
	{
		return (0);
	}
	return (sz);
}
