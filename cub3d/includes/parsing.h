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

typedef struct s_malloc
{
    char *pointer;
    char **pointer2;
	struct s_malloc	*next;
	struct s_malloc	*back;

}  t_malloc;


typedef struct s_parsing
{
    int lcount;
    char **map;
    t_pos *begin;
    t_pos *pos;
    t_malloc *_malloc;
    t_malloc *_mbegin;
}   t_parsing;

typedef struct s_map
{
    int _last;
    int _first;
    int _Pcounter;
    char **_map;
    int _Ypos;
    int _Xpos;
} t_map;
int main(int ac, char **argv);

//parsing
int get_config(t_parsing *p,char *dest);
int check_arg_before(char *src,char *find);
int check_arg_after(char *str, int last);
int check_map(char **map);


//map
int parsing_map(t_parsing *p);

//free_global
int push_malloc(t_parsing *p,char *str);
int push_malloc_double(t_parsing *p,char **str);

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