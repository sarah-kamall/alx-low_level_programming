#include"main.h"
int create_file(const char *filename, char *text_content)
{
    int ac, i, byteswritten, fp;
    char *context;
    i = 0; 
    if (!filename)
        return (-1);
    ac = access(filename, W_OK);
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
    return (1);
}

