#include "parsing.h"

int put_map_line(t_parsing *p, char *dest, int start, int end, int index)
{
    int k = 0;

    p->map[index] = malloc(sizeof(char) * (end - start + 1));
    if (!p->map[index])
        return (-1);

    while (dest[start] != '\n' && dest[start] != '\0')
    {
        p->map[index][k] = dest[start];
        k++;
        start++;
    }

    p->map[index][k] = '\0';
    return (1);
}

int check_strstr(char *config, char *map)
{
    int i;
    int result;

    //printf("config == %s et map == %s\n",config,map);
    i = skip_space(map,0);
    result = ft_strstr(map,config);
    if (result == -1 || result != i)
        return (-1);
    //printf("i = %d et result = %d\n",i,result);
    return (result);
}

int get_info(t_parsing *p, char **config)
{
    int i;
    int count;
    int  index;

   
    count = 0;
    index = 0;
    while (config[count] != 0)
    { 
        index = 0;
        while(p->map[index] != 0)
        {
            if (check_strstr(config[count],p->map[index]) != -1)
            {
               // printf("index == %d\n",index);
                p->map = get_pos_remove(p,p->map,config[count],index);
                if (!p->map)
                    return (-1);
                break ;
            }
            index++;
        }
        if (p->map[index] == 0)
            return (-1);
        count++;
    }
    if (check_path(p->pos) == -1)
        return (-1);
    //printf("count = %d\n",  count);
    return (1);
}

int get_config(t_parsing *p, char *dest)
{
    char **config = init_config();
    if (!config)
        return 0;
    init_map(dest, p);
    if (get_info(p,config) == -1)
        return (-1);
    free(config);
    //printdoubletab(p->map);
    if (check_map(p->map) == -1)
        return (-1);
    return 0;
}