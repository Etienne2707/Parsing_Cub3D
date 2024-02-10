#include "parsing.h"

char **init_config()
{
    char **config = malloc(sizeof(char *) * 7);
    if (!config)
        return NULL;
    config[0] = "NO ";
    config[1] = "SO ";
    config[2] = "WE ";
    config[3] = "EA ";
    config[4] = "F ";
    config[5] = "C ";
    config[6] = 0;

    return config;
}

int init_map(char *dest, t_parsing *p)
{
    int i = 0;
    int k;
    int index;

    i = 0;
    index = 0;
    p->map = malloc(sizeof(char *) * (ft_line_count(dest) + 2));
    if (!p->map)
        return (-1);

    while (i < ft_strlen(dest))
    {
        k = i;
        i = ft_endlinelen(dest, i);
        put_map_line(p, dest, k, i, index);
        i++;
        index++;
    }
    free(dest);
    p->map[index] = 0;
    return 1;
}