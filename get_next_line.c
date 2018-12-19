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

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

char *my_realloc(char *ptr)
{
    char *temp = ptr;
    int i = 0;

    ptr = malloc(sizeof(char) * (my_strlen(ptr) + READ_SIZE));
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

char *read_line(char *str, int sizeStr)
{

}

char *get_next_line(int fd)
{
    char *str = malloc(sizeof(char) * READ_SIZE);
    char *buffer = malloc(sizeof(char) * READ_SIZE);
    static char over[READ_SIZE];
    int count = 0;
    int size;
    int sizeStr = 0;

    for (int i = 0; over[i] != 0; i++) {
        str[i] = over[i];
        sizeStr++;
    }
    while (*buffer != '\n') {
        size = read(fd, buffer, READ_SIZE);
        str = my_realloc(str);
        buffer[size] = '\0';
        count = 0;
        for (; *buffer != '\n' && count < size; *buffer++) {
            str[sizeStr] = *buffer;
            count++;
            sizeStr++;
        }
    }
    *buffer++;
    for (int i = 0; *buffer != '\0'; i++) {
        over[i] = *buffer;
        *buffer++;
    }
    return (str);
}