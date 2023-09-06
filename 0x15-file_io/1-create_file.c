#include"main.h"
/**
* create_file - Create or overwrite a file with the given text content.
* @filename: The name of the file to be created or overwritten.
* @text_content: The content to be written to the file.
*
* Description:
* This function creates a new file or overwrites an existing file with the
* file doesn't exist, it creates a new empty file. The function then writes
* the contents of the text_content string to the file. If the file already
* exists, its previous contents are replaced with the new text content.
*
* Return:
* On success, returns 1. On failure, returns -1.
*
* File Permissions:
* The function uses the O_CREAT flag when opening the file, so it's important
* to specify the desired file permissions (mode) when calling this function.
* The recommended mode for most use cases is 0600, which grants read and write
* permissions to the file owner and no permissions to others.
*/
int create_file(const char *filename, char *text_content)
{
	int ac, i, byteswritten, fp;
	char *context;

	i = 0;
	if (!filename)
		return (-1);
	ac = access(filename, W_OK | F_OK);
	if (ac == -1)
	{
		fp = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0600);
	}
	else
	{
		fp = open(filename, O_RDWR);
	}
	if (fp == -1)
		return (-1);
	context = text_content;
	while (*text_content)
	{
		i++;
		text_content++;
	}
	byteswritten = write(fp, context, i);
	if (byteswritten == -1)
		return (-1);
	close(fp);
	return (1);
}

