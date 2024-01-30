#include "parsing.h"

char **init_config(char **config)
{
    config = malloc(sizeof(char *) * 6);
    if (!config)
        return (NULL);
    config[0] = "NO ";
    config[1] = "SO ";
    config[2] = "WE ";
    config[3] = "EA ";
    config[4] = "F ";
    config[5] = "C ";

    return (config);

}

int get_confg_path(t_parsing *t, char **config, char *dest)
{
    int i;
    int index;
    int last;

    index = 0;
    while(index < 6)
    {
        i = strstr(dest,config[index]) - dest + ft_strlen(config[index]);             
        i = skip_space(dest,i);
        last = i;
        while (dest[last] != '\n' &&  dest[last] != '\0' && dest[last] != 32) // les tabulations
            last++;
        if (check_arg_after(dest,last) == -1)
            return (-1);
        if (last == i)
        {
            printf("Pas de path ! ");
            return (-1);
        }
        t->pos[index] = get_nmalloc(dest,i,last);
        index++;
    }
    printdoubletab(t->pos);
    return (1);
}

int get_config(t_parsing *p,char *dest)
{
    char **config;
    size_t index;

    config = init_config(config);
    if (!config)
        return (0);
    if (get_confg_path(p,config,dest) == -1)
    {
        return (-1);
    }
    return(0);
    
}
