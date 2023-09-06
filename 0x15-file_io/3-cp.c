#include"main.h"
/**
* main - Entry point of the program.
*
* Description:
* This is the main function that serves as the entry point of the program.
* It is executed when the program is run, and it typically contains the
* high-level logic and control flow of the program.
*
* Return:
* - 0 on successful execution, indicating a normal program termination.
* -A non-zero value on error or exceptional termination, indicating an issue.
*/
int main(int argc, char **argv)
{
	int fp0, fp1, bytesread, byteswritten;
	char *filefrom, *fileto, *buffer;

	filefrom = argv[1];
	fileto = argv[2];
	if (argc < 3)
	{
		dprintf(2, "Usage: cp file_from file_to\n");
		exit(97);
	}
	fp0 = open(filefrom, O_RDONLY);
	if (access(filefrom, R_OK | F_OK) == -1 || fp0 == -1)
	{
		dprintf(2, "Error: Can't read from file %s\n", filefrom);
		exit(98);
	}
	if (access(fileto, F_OK | W_OK) == -1)
		fp1 = open(fileto, O_RDWR | O_CREAT | O_TRUNC, 0664);
	else
		fp1 = open(fileto, O_RDWR | O_TRUNC);
	buffer = malloc(1024);
	if (!buffer)
		return (-1);
	bytesread = read(fp0, buffer, 1024);
	while (bytesread != 0)
	{
		if (bytesread == -1)
		{
			dprintf(2, "Error: Can't read from file %s\n", filefrom);
			exit(98);
		}
		byteswritten = write(fp1, buffer, bytesread);
		if (byteswritten == -1)
		{
			dprintf(2, "Error: Can't write to %s\n", fileto);
			exit(99);
		}
		bytesread = read(fp0, buffer, 1024);
	}
	if (close(fp0) == -1)
	{
		dprintf(2, "Error: Can't close fd %d\n", fp0);
		exit(100);
	}
	if (close(fp1) == -1)
	{
		dprintf(2, "Error: Can't close fd %d\n", fp1);
		exit(100);
	}
	return (0);
}

