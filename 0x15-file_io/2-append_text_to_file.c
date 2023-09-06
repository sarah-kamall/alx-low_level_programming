#include"main.h"
int append_text_to_file(const char *filename, char *text_content)
{
    int fd, numofbytes, byteswritten, i;
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

