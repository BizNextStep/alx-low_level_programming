#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * create_file - a function that creates a file and writes a NULL terminated
 * string to it.
 * @filename: is the name of the file to create.
 * @text_content: is a NULL terminated string to write to the file.
 *
 * Return: 1 on success, -1 on failure (file can not be created, file can not
 * be written, write “fails”, etc…)
 * The created file must have those permissions: rw-------.
 * If the file already exists, do not change the permissions.
 * If the file already exists, truncate it.
 * If filename is NULL return -1.
 * If text_content is NULL create an empty file.
 */
int create_file(const char *filename, char *text_content)
{
	int file, write_file, close_file;
	mode_t mode = S_IRUSR | S_IWUSR;
	ssize_t text_length = 0;

	if (!filename)
		return (-1);

	file = open(filename, O_WRONLY | O_CREAT | O_TRUNC, mode);
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
