#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - a program that copies the content of a file to another file.
 * @argc: is the number of arguments passed to the program.
 * @argv: is an array of pointers to the arguments.
 *
 * Return: 0 on success, or the corresponding error code on failure.
 */
int main(int argc, char *argv[])
{
	int file_from, file_to, close_from, close_to;
	ssize_t read_file, write_file;
	char buffer[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		return (97);
	}

	file_from = open(argv[1], O_RDONLY);
	if (file_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		return (98);
	}

	file_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	if (file_to == -1)
	{
		close_from = close(file_from);
		if (close_from == -1)
			dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		return (99);
	}

	while ((read_file = read(file_from, buffer, 1024)) > 0)
	{
		write_file = write(file_to, buffer, read_file);
		if (write_file == -1 || write_file != read_file)
		{
			close_from = close(file_from);
			if (close_from == -1)
				dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
			close_to = close(file_to);
			if (close_to == -1)
				dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_to);
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			return (99);
		}
	}

	if (read_file == -1)
	{
		close_from = close(file_from);
		if (close_from == -1)
			dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
		close_to = close(file_to);
		if (close_to == -1)
			dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_to);
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		return (98);
	}

	close_from = close(file_from);
	if (close_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
		return (100);
	}

	close_to = close(file_to);
	if (close_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_to);
		return (100);
	}

	return (0);
}
