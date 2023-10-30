#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>


/**
* create_file - Create a file with specified text content
* @filename: Name of the file to create
* @text_content: Text content to write to the file
* Return: 1 on success, -1 on failure
*/
int create_file(const char *filename, char *text_content)
{
int fd, result;
ssize_t len = 0;

if (filename == NULL)
return (-1);

fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
if (fd == -1)
return (-1);

if (text_content)
{
while (text_content[len])
len++;

result = write(fd, text_content, len);
if (result == -1)
{
close(fd);
return (-1);
}
}

close(fd);

return (1);
}
