/*
** EPITECH PROJECT, 2018
** CPE_getnextline_2018
** File description:
** get_next_line
*/

#include "get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

char *my_realloc(char *ptr)
{
    char *temp = ptr;
    int i = 0;

    ptr = malloc(sizeof(ptr) * READ_SIZE);
    while (temp[i]) {
        ptr[i] = temp[i];
        i++;
    }
    return (ptr);
}

void my_putchar(char c)
{
    write(1, &c, 1);
}

void move_ptr(char **str, int count)
{
    for (int i = 0; i < count; i++) {
        **str++;
    }
}

char *read_line(int fd)
{
    char *str = malloc(sizeof(char) * READ_SIZE);
    char *buffer = malloc(sizeof(char) * READ_SIZE);
    static int count = 0;
    int size = read(fd, buffer, READ_SIZE);
    int sizeStr = 0;

    buffer[size] = '\0';
    while (*buffer != '\n') {
        if (sizeStr > 0) {
            size = read(fd, buffer, READ_SIZE);
            str = my_realloc(str);
            buffer[size] = '\0';
        }
        count = 0;
        for (; *buffer != '\n' && count < size; *buffer++) {
            str[sizeStr] = *buffer;
            count++;
            sizeStr++;
        }
    }
    return (str);
}

char *get_next_line(int fd)
{
    char *s = read_line(fd);

    if (fd != -1)
        close(fd);
    return (s);
}