#include"main.h"
/**
 * read_textfile - Reads and pri number of letters.
 * @filename: The name of the file to be read.
 * @letters: The maximum number of letters to read and print.
 *
 * Return: The actual number of letters read and printed, or -1 on failure.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t bytes_read, bytes_written;
	char *buffer;

	if (filename == NULL)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buffer = malloc(letters);
	if (buffer == NULL)
	{
		close(fd);
		return (0);
	}
	bytes_read = read(fd, buffer, letters);
	if (bytes_read == -1)
	{
		free(buffer);
		close(fd);
		return (0);
	}
	bytes_written = write(STDOUT_FILENO, buffer, bytes_read);
	free(buffer);
	close(fd);
	if (bytes_written != bytes_read)
		return (0);
	return (bytes_written);
}
