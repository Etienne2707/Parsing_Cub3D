#ifndef PARSING_H
#define PARSING_H

#include "../libft/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

typedef struct s_pos
{
    char *arg;
    char *value;
	struct s_pos	*next;
	struct s_pos	*back;

}  t_pos;


typedef struct s_parsing
{
    int lcount;
    char **map;
    t_pos *begin;
    t_pos *pos;
}   t_parsing;

int main(int ac, char **argv);

//parsing
int get_config(t_parsing *p,char *dest);
int check_arg_before(char *src,char *find);
int check_arg_after(char *str, int last);
int check_map(char **map);

//utils
int skip_space(char *str, int i);
void    printdoubletab(char **str);
int check_only_space(char *str,int index);
int ft_strlen_double(char **str);
int push_front_list(t_parsing *p,char *arg, char *value);
void    printtab(char *str);
int ft_strstr(char *str, char *to_find);

char *get_nmalloc(char *str, int start, int end);

#endif