#ifndef PARSING_H
#define PARSING_H

#include "../libft/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>


typedef struct s_parsing
{
    int lcount;
    char **map;
    char **pos;
}   t_parsing;

int main(int ac, char **argv);

//parsing
int get_config(t_parsing *p,char *dest);

//utils
int skip_space(char *str, int i);
void    printdoubletab(char **str);
void    printtab(char *str);
int ft_strstr(char *str, char *to_find);
int check_arg_after(char *str, int last);
char *get_nmalloc(char *str, int start, int end);

#endif