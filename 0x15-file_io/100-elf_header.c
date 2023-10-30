#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <elf.h>

/**
 * displayElfHeader - Display the ELF header magic bytes.
 * @buffer: Pointer to the ELF header.
 */
void displayElfHeader(const unsigned char *buffer)
{
int i;
printf("ELF Header:\n  Magic:   ");
for (i = 0; i < 16; ++i)
{
printf("%02x%c", buffer[i], i < 15 ? ' ' : '\n');
}
}

/**
 * elfType - Display the ELF file type.
 * @buffer: Pointer to the ELF header.
 * @bigEndian: 1 for big-endian, 0 for little-endian.
 */
void elfType(const unsigned char *buffer, int bigEndian)
{
char *typeTable[5] = {
"NONE (No file type)",
"REL (Relocatable file)",
"EXEC (Executable file)",
"DYN (Shared object file)",
"CORE (Core file)"
};
unsigned int type;
printf("  %-34s ", "Type:");
if (bigEndian)
{
type = 0x100 * buffer[16] + buffer[17];
}
else
{
type = 0x100 * buffer[17] + buffer[16];
}
if (type < 5)
{
printf("%s\n", typeTable[type]);
}
else if (type >= ET_LOOS && type <= ET_HIOS)
{
printf("OS Specific: (%4x)\n", type);
}
else if (type >= ET_LOPROC && type <= ET_HIPROC)
{
printf("Processor Specific: (%4x)\n", type);
}
else
{
printf("<unknown: %x>\n", type);
}
}

/**
 * main - Entry point of the program.
 * @argc: The number of arguments.
 * @argv: An array of argument strings.
 *
 * Return: 0 on success, 98 on error.
 */
int main(int argc, const char *argv[])
{
unsigned char buffer[18];
int bigEndian;
int fd;

if (argc != 2)
{
write(STDERR_FILENO, "Usage: elf_header elf_filename\n", 31);
exit(98);
}

fd = open(argv[1], O_RDONLY);
if (fd == -1)
{
write(STDERR_FILENO, "Error: Can't read from file\n", 28);
exit(98);
}

if (read(fd, buffer, 18) == -1)
{
write(STDERR_FILENO, "Error: Can't read from file\n", 28);
close(fd);
exit(98);
}

displayElfHeader(buffer);

bigEndian = (buffer[EI_DATA] == ELFDATA2MSB) ? 1 : 0;

elfType(buffer, bigEndian);

close(fd);

return (0);
}

