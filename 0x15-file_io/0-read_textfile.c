#include "main.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

/**
 * read_textfile - Reads a text file and prints
 * it to the POSIX standard output
 * @filename: Name of the file to read
 * @letters: Number of letters to read and print
 * Return: The actual number of letters it could read and print
 */

size_t read_textfile(const char *filename, size_t letters)
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
close(fd);

if (bytes_read == -1)
{
free(buffer);
return (0);
}

bytes_written = write(STDOUT_FILENO, buffer, bytes_read);
free(buffer);

if (bytes_written == -1 || bytes_written != bytes_read)
return (0);

return (bytes_written);
}
