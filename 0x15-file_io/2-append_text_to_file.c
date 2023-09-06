#include"main.h"
/**
 * append_text_to_file - Appends text to a file or creates it if it doesn't exist.
 * @filename: The name of the file.
 * @text_content: The content to append.
 *
 * Description:
 * Appends text_content to the specified file or creates a new file if it doesn't exist.
 * Returns 1 on success, -1 on failure.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, byteswritten, i;
	char *content;
	
	i = 0;
	if (!filename)
		return (-1);
	if (access(filename, F_OK | W_OK) == -1)
		return (-1);
	else
	{
		fd = open(filename, O_RDWR | O_APPEND);
		if (fd == -1)
			return (-1);
		content = text_content;
		while (*text_content)
		{
			i++;
			text_content++;
		}
		byteswritten = write(fd, content, i);
		if (byteswritten == -1)
			return (-1);
		close(fd);
	}
	return (1);
}

