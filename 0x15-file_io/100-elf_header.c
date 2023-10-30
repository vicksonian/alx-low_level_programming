#include <elf.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
 * elfBitMode - Determine the ELF file's bit mode (32-bit or 64-bit).
 * @buffer: Pointer to the ELF header.
 * Return: The bit mode (32 or 64).
 */
int elfBitMode(const unsigned char *buffer)
{
int bitMode;
printf("  %-34s ", "Class:");
if (buffer[EI_CLASS] == ELFCLASS64)
{
printf("ELF64\n");
bitMode = 64;
}
else if (buffer[EI_CLASS] == ELFCLASS32)
{
printf("ELF32\n");
bitMode = 32;
}
else
{
printf("<unknown: %x>\n", buffer[EI_CLASS]);
bitMode = 32;
}
return (bitMode);
}

/**
 * elfEndianness - Determine the ELF file's endianness.
 * @buffer: Pointer to the ELF header.
 * Return: 1 for big-endian, 0 for little-endian.
 */
int elfEndianness(const unsigned char *buffer)
{
int bigEndian;
printf("  %-34s ", "Data:");
if (buffer[EI_DATA] == ELFDATA2MSB)
{
printf("2's complement, big endian\n");
bigEndian = 1;
}
else if (buffer[EI_DATA] == ELFDATA2LSB)
{
printf("2's complement, little endian\n");
bigEndian = 0;
}
else
{
printf("Invalid data encoding\n");
bigEndian = 0;
}
return (bigEndian);
}

/**
 * elfVersion - Display the ELF version.
 * @buffer: Pointer to the ELF header.
 */
void elfVersion(const unsigned char *buffer)
{
printf("  %-34s %u", "Version:", buffer[EI_VERSION]);
if (buffer[EI_VERSION] == EV_CURRENT)
{
printf(" (current)\n");
}
else
{
printf("\n");
}
}

/**
 * elfOSABI - Display the ELF OS/ABI.
 * @buffer: Pointer to the ELF header.
 */
void elfOSABI(const unsigned char *buffer)
{
const char *osTable[19] = {
"UNIX - System V",
"UNIX - HP-UX",
"UNIX - NetBSD",
"UNIX - GNU",
"<unknown: 4>",
"<unknown: 5>",
"UNIX - Solaris",
"UNIX - AIX",
"UNIX - IRIX",
"UNIX - FreeBSD",
"UNIX - Tru64",
"Novell - Modesto",
"UNIX - OpenBSD",
"VMS - OpenVMS",
"HP - Non-Stop Kernel",
"AROS",
"FenixOS",
"Nuxi CloudABI",
"Stratus Technologies OpenVOS"
};
printf("  %-34s ", "OS/ABI:");
if (buffer[EI_OSABI] < 19)
{
printf("%s\n", osTable[(unsigned int)(buffer[EI_OSABI])]);
}
else
{
printf("<unknown: %x>\n", buffer[EI_OSABI]);
}
}

/**
 * elfABIVersion - Display the ELF ABI version.
 * @buffer: Pointer to the ELF header.
 */
void elfABIVersion(const unsigned char *buffer)
{
printf("  %-34s %u\n", "ABI Version:", buffer[EI_ABIVERSION]);
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
 * elfEntryPoint - Display the ELF entry point address.
 * @buffer: Pointer to the ELF header.
 * @bitMode: The bit mode (32 or 64).
 * @bigEndian: 1 for big-endian, 0 for little-endian.
 */
void elfEntryPoint(const unsigned char *buffer, int bitMode, int bigEndian)
{
int addressSize = bitMode / 8;
printf("  %-34s 0x", "Entry point address:");
if (bigEndian)
{
while (addressSize && !*buffer)
{
--addressSize;
++buffer;
}
printf("%x", *buffer & 0xff);
while (--addressSize > 0)
{
printf("%02x", *(++buffer) & 0xff);
} }
else
{
buffer += addressSize;
while (addressSize && !*(--buffer))
{
--addressSize; }
printf("%x", *buffer & 0xff);
while (--addressSize > 0)
{
printf("%02x", *(--buffer) &0xff); }
printf("\n"); }

int main(int argc, const char *argv[])
{unsigned char buffer[18];
int bitMode;
int bigEndian;
int fd;
if (argc != 2)
{
write(STDERR_FILENO, "Usage: elf_header elf_filename\n", 31);
exit(98);
} fd = open(argv[1], O_RDONLY);
if (fd == -1)
{write(STDERR_FILENO, "Error: Can't read from file\n", 28);
exit(98); }
if (read(fd, buffer, 18) == -1)
{
write(STDERR_FILENO, "Error: Can't read from file\n", 28);
close(fd);
exit(98); }
displayElfHeader(buffer);
bitMode = elfBitMode(buffer);
bigEndian = elfEndianness(buffer);
elfVersion(buffer);
elfOSABI(buffer);
elfABIVersion(buffer);
elfType(buffer, bigEndian);
lseek(fd, 24, SEEK_SET);
if (read(fd, buffer, bitMode / 8) == -1)
{write(STDERR_FILENO, "Error: Can't read from file\n", 28);
close(fd);
exit(98); }
elfEntryPoint(buffer, bitMode, bigEndian);
close(fd);
return (0);
}

