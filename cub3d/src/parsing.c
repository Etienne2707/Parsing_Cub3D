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

int ft_endlinelen(char *dest, int index)
{
    while(dest[index] != '\0')
    {
        if (dest[index] == 10)
            return(index);
        index++;
    }
    return(index);
}

int ft_line_count(char *str)
{
    int i;
    int c;
    
    i = 0;
    c = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '\n')
            c++;
        i++;
    }
    return (c);
}

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

int init_map(char *dest, t_parsing *p)
{
    int i = 0;
    int k;
    int index;

    i = 0;
    index = 0;
    printf("ft : %d\n",ft_line_count(dest) + 1);
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
    printf("p->map = %d\n",index);
    p->map[index] = 0;
    return 1;
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

void print_list(t_pos *pos) 
{
    t_pos *current = pos;
    while (current != NULL) {
        printf("liste chaine arg: %s value : %s\n", current->arg, current->value);
        current = current->next;
    }
}


int set_pos(t_parsing *p,char *map,char *config)
{
    map = get_pos(map,config);
    if (!map)
        return (-1);
    //printf("map :%s\n",map);
    get_list(&p->pos,p,map,config);
    print_list(p->pos);
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
    printf("%s",dest[3]);
    return (dest);
    
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
                {
                    printf("!p->map");
                    return (-1);
                }
                break ;
            }
            index++;
        }
        if (p->map[index] == 0)
        {
            return (-1);
        }
        count++;
    }
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