#include "main.h"
#include <fcntl.h>
#include <string.h>

/**
 * append_text_to_file - appends text to file
 *
 * @filename: name of the file
 * @text_content: text to append to file
 *
 * Description: Do not create the file if it does not exist
 * If text_content is NULL, do not add anything to the file. Return 1
 * if the file exists and -1 if the file does not exist or if you do
 * not have the required permissions to write the file
 *
 * Return: 1 on success and -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, bytes;

	if (filename == NULL)
	{
		return (-1);
	}

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
	{
		return (-1);
	}
	if (text_content == NULL)
	{
		close(fd);
		return (1);
	}

	bytes = write(fd, text_content, strlen(text_content));
	close(fd);
	if (bytes == -1)
	{
		return (-1);
	}
	else
	{
		return (1);
	}
}
