/*
** EPITECH PROJECT, 2018
** CPE_getnextline_2018
** File description:
** get_next_line
*/

#include "get_next_line.h"
#include "my.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int fd = -1;
int line = 0;

void my_putchar(char c)
{
    write(1, &c, 1);
}

void open_file(void)
{
    fd = open("test.txt", O_RDONLY);
}

void close_file(void)
{
    if (fd != -1)
        close(fd);
}

char *get_next_line(int fd2)
{
    char buffer[4096];
    char *s = malloc(sizeof(char) * READ_SIZE);
    int j = 0;
    int i;

    fd = fd2;
    open_file();
    read(fd, buffer, READ_SIZE);
    for (i = 0; buffer[i] != '\n' && i < READ_SIZE; i++) {
        s[j] = buffer[i];
        j++;
    }
    if (buffer[i] == '\n') {
        line++;
    } else {
        read(fd, buffer, READ_SIZE);
        for (i = 0; buffer[i] != '\n' && i < READ_SIZE; i++) {
            s[j] = buffer[i];
            j++;
        }
        if (buffer[i] == '\n')
            line++;
    }
    close_file();
    return (s);
}