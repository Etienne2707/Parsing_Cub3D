#include "parsing.h"

int init_pstruct(t_parsing *p)
{
    p->lcount = 0;
    p->map = NULL;
    p->pos = malloc(sizeof(char **) * 6);
    if (!p->pos)
        return (-1);
    return (0);
}

char *file_cpy(char *dest, char *str)
{
    if (!dest)
        dest = strdup(str);
    dest = ft_strjoin(dest,ft_strdup(str));
    if (!dest)
        return (NULL);
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
        
    }
    if (get_config(p,dest) == -1)
    {
        return(-1);
    }
    return (1);
    printf("%s", dest);
    printf("%d\n",p->lcount);
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
    if (fd == -1)
    {
        printf("Error file");
        return (-1);
    }
    if (parsing(p,fd) == -1)
    {
        printf("Error in parsing\n");
        return (-1);
    }
}