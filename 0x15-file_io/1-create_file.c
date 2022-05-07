#include "main.h"
#include <fcntl.h>
#include <string.h>

/**
 * create_file - creates a file
 *
 * @filename: name of the file
 * @text_content: text to write to file
 *
 * Description: The created file must have those permissions: rw-------.
 * If the file already exists, do not change the permissions.
 * if the file already exists, truncate it
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fd, num_bytes;

	if (filename == NULL)
	{
		return (-1);
	}
	fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0600);
	if (fd == -1)
	{
		return (-1);
	}

	if (text_content == NULL)
	{
		num_bytes = write(fd, "", 0);
	}
	else
	{
		num_bytes = write(fd, text_content, strlen(text_content));
	}
	close(fd);
	if (num_bytes == -1)
	{
		return (-1);
	}
	return (1);
}
