#include "../includes/parsing.h"


int only_wall(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] != '1')
            return (-1);
        i++;
    }
    return (1);
}

int skip_string(char *str)
{
    int i;
    
    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= 33 && str[i] <= 127)
            return (-1);
        i++;
    }
    return (1);
}

int get_first_map(char **map)
{
    int i;

    i = 0;
    while (map[i] != 0)
    {
        if (skip_string(map[i]) == -1)
            return (i);
        i++;
    }
    return (i);
}

int get_last_map(char **map,int first)
{
    int i;

    i = first;
    while (map[i] != 0)
    {
        if (skip_string(map[i])== 1)
            return (i);
        i++;
    }
    return (i);
}

int get_map(t_map *m, char **src)
{
    int i;
    int k;

    i = m->_first;
    k = 0;
    while(i < m->_last)
    {
        m->_map[k] = strdup(src[i]);
        k++;
        i++;
    }
    m->_map[k] = 0;
    return (1);
}

int get_map_struct(t_map *map,char **src)
{
    map->_first = get_first_map(src);
    map->_last = get_last_map(src,map->_first);
    map->_map = malloc(sizeof(char *) * map->_last - map->_first + 1);
    if (!map->_map)
        return (-1);
    get_map(map,src);
    printf("last = %d first = %d\n", map->_last, map->_first);
}

int check_wall_posX(t_map *m, int y, int x)
{
    int _x;
    int result ;

    _x = x;
    result = 0;
    while (m->_map[y][x++] != '\0')
    {
        if (m->_map[y][x] == '1')
        {
            result++;
            break ;
        }
    }
    while (_x-- != 0)
    {
        if (m->_map[y][x] == '1')
        {
            result++;
            break ;
        }
    }
    printf("%d",result);
    if (result == 2)
        return (1);
    return (-1);
}

int check_wall_posY(t_map *m, int y, int x)
{
    int _y;
    int result ;
    int start = y;

    _y = y;
    result = 0;
    while (m->_map[y++][x] != 0)
    {
        if (m->_map[y][x] == '1')
        {
            result++;
            break ;
        }
    }
    while (_y-- != 0)
    {
        if (m->_map[y][x] == '1')
        {
            result++;
            break ;
        }
    }
    if (result == 0)
        printf("y = %d et x = %d\n",start,x);
    printf("%d",result);
    if (result == 2)
        return (1);
    return (-1);
}

int check_wall_pos(t_map *m, int y, int x)
{
    if (check_wall_posX(m,y,x) == -1)
        return (-1);
    if (check_wall_posY(m,y,x) == -1)
        return (-1);
    return (1);
}
int check_wall(t_map *m)
{
    int i;
    int k;

    i = 0;
    while (m->_map[i] != 0)
    {
        k = 0;
        while (m->_map[i][k] != '\0')
        {
            if (m->_map[i][k] == '0')
            {
                if (check_wall_pos(m,i,k) == -1)
                    return (-1);
            }
            k++;
        }
        i++;
    }
    printf("\n");
    return (1);
}



int parsing_map(t_parsing *p)
{
    t_map *map;
    
    map = malloc(sizeof(t_map));
    if (!map)
        return (-1);
    get_map_struct(map,p->map); 
    if (check_wall(map) == -1)
        return (-1);
    printdoubletab(map->_map);
    return (1);
}


