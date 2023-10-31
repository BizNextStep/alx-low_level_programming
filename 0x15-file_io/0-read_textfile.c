#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * read_textfile - a function that reads a text file and prints
 * it to the POSIX standard output.
 * @filename: file name.
 * @letters: numbers of letters printed.
 *
 * Return: returns the actual number of letters it could read and print
 * if the file can not be opened or read, return 0
 * if filename is NULL return 0
 * if write fails or does not write the expected amount of bytes, return 0.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int file;
	ssize_t read_file, write_file;
	char *buffer;

	if (!filename)
		return (0);

	file = open(filename, O_RDONLY);
	if (file == -1)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (!buffer)
		return (0);

	read_file = read(file, buffer, letters);
	if (read_file == -1)
	{
		free(buffer);
		return (0);
	}

	write_file = write(STDOUT_FILENO, buffer, read_file);
	if (write_file == -1 || read_file != write_file)
	{
		free(buffer);
		return (0);
	}

	free(buffer);
	close(file);

	return (read_file);
}
