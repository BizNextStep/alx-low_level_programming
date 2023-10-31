#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * append_text_to_file - a function that appends text at the end of a file.
 * @filename: is the name of the file.
 * @text_content: is the NULL terminated string to add at the end of the file.
 *
 * Return: 1 on success and -1 on failure.
 * Do not create the file if it does not exist.
 * If filename is NULL return -1.
 * If text_content is NULL, do not add anything to the file.
 * Return 1 if the file exists and -1 if the file does not exist or if you do
 * not have the required permissions to write the file.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int file, write_file, close_file;
	ssize_t text_length = 0;

	if (!filename)
		return (-1);

	file = open(filename, O_WRONLY | O_APPEND);
	if (file == -1)
		return (-1);

	if (text_content)
	{
		while (text_content[text_length])
			text_length++;

		write_file = write(file, text_content, text_length);
		if (write_file == -1 || write_file != text_length)
		{
			close_file = close(file);
			if (close_file == -1)
				return (-1);
			return (-1);
		}
	}

	close_file = close(file);
	if (close_file == -1)
		return (-1);

	return (1);
}
