#include "parsing.h"

char *get_pos(char *map,char *config)
{
    int i;
    int k;
    char *tmp;

    i = 0;

    i = ft_strstr(map,config)+ ft_strlen(config);
    //printf("%s\n",map);
    i = skip_space(map,i) ; 
    //printf("le retour de i : %d %d\n",i,map[i]);
    k = i;
    while (map[k] != 32 && map[k] != '\0')
        k++; 
    if (check_only_space(map,k) == -1)
        return (NULL);
    tmp = get_nmalloc(map,i,k);
    if (!tmp)
        return (NULL);
    return (tmp);
    
}

int set_pos(t_parsing *p,char *map,char *config)
{
    map = get_pos(map,config);
    if (!map)
        return (-1);
    //printf("map :%s\n",map);
    if ((get_list(&p->pos,p,map,config) == -1) || (check_path(p->pos) == -1))
        return (-1);
}

char** get_pos_remove(t_parsing *p,char **map,char *config,int index)
{
    char **dest;
    int i;
    int k;


    i = 0;
    k = 0;
    dest = malloc(sizeof(char *) * ft_strlen_double(map));
    if (!dest)
        return (NULL);
    while (map[i] != 0)
    {
        if (i == index)
        {
            if (set_pos(p,p->map[i],config) == -1)
                return (NULL);
            i++; // mettre dans pos
        }
        if (map[i] == 0)
            break;
        //printf("index == %d i == %d\n map[i] == %s\n",index,i,map[i]);
        dest[k] = strdup(map[i]);
        k++;      
        i++;
    }
    
    dest[k] = 0;
    free_double_array(p->map);
    return (dest);
    
}