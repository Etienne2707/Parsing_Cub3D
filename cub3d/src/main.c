#include "parsing.h"

int init_pstruct(t_parsing *p)
{
    p->lcount = 0;
    p->map = NULL;
    p->pos = NULL;
    return (1);
}

char *file_cpy(char *dest, char *str)
{
    char *tmp;

    if (!dest)
        return (dest = strdup(str));
    tmp = ft_strjoin(dest,str);
    if (!tmp)
        return (NULL);
    free(dest);
    return (tmp);
}

int parsing(t_parsing *p, int fd)
{
    char *str;
    char *dest;

    dest = NULL;
    while (-1)
    {
        p->lcount++;
        str = get_next_line(fd);
        if (!str)
            break ;
        dest = file_cpy(dest,str);
        free(str);
    }
    if (get_config(p,dest) == -1)
    {
        return(-1);
    }
    if (parsing_map(p) == -1)
    {
        return (-1);
    }
    free_structs(p);
    return (1);
}

int main(int ac , char **argv)
{
    int fd;
    t_parsing *p;


    p = malloc(sizeof(t_parsing));
    if (!p)
        return -1;
    init_pstruct(p);
    if (ac != 2)
        return (-1);
    fd = open(argv[1], O_RDONLY);
    if (fd == -1 || ft_check_format(argv[1],".cub") == -1)
    {
        printf("%sError file%s\n",RED,RESET);
        return (-1);
    }
    if (parsing(p,fd) == -1)
    {
        printf("%sError in parsing%s\n",RED,RESET);
        return (-1);
    }
}
