#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>


/**
* append_text_to_file - Append text to the end of a file
* @filename: Name of the file
* @text_content: Text content to append
* Return: 1 on success, -1 on failure
*/
int append_text_to_file(const char *filename, char *text_content)
{
int fd, result;
ssize_t len = 0;

if (filename == NULL)
return (-1);

fd = open(filename, O_WRONLY | O_APPEND);
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
