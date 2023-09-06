#include"main.h"
/**
 * read_textfile - Reads and prints a text file up to a specified number of letters.
 * @filename: The name of the file to be read.
 * @letters: The maximum number of letters to read and print.
 *
 * Return: The actual number of letters read and printed, or -1 on failure.
 */
ssize_t read_textfile(const char *filename, size_t letters) {
    int fd; 
    ssize_t bytes_read, bytes_written;
    char *buffer;

    if (filename == NULL)
        return (ssize_t) -1;

  
    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return (ssize_t) -1;

 
    buffer = malloc(letters);
    if (buffer == NULL) {
        close(fd);
        return (ssize_t) -1;
    }

     bytes_read = read(fd, buffer, letters);
    if (bytes_read == -1) {
        free(buffer);
        close(fd);
        return (ssize_t) -1;
    }

     bytes_written = write(STDOUT_FILENO, buffer, bytes_read);

 
    free(buffer);
    close(fd);

    if (bytes_written != bytes_read)
        return (ssize_t) -1;

    return bytes_written;
}
