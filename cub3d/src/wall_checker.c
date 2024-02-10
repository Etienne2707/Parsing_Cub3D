#include "parsing.h"

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
    while (m->_map[y] != 0)
    {
        if (x >= ft_strlen(m->_map[y]))
            return (-1);
        if (m->_map[y][x] == '1')
        {
            result++;
            break ;
        }
        y++;
    }    
    while (_y != -1)
    {
        if (x >= ft_strlen(m->_map[_y]))
            return (-1);
        if (m->_map[_y][x] == '1')
        {
            result++;
            break ;
        }
        _y--;
    }
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
            if (m->_map[i][k] == '0' || m->_map[i][k] == 'N')
            {
                if (check_wall_pos(m,i,k) == -1)
                {
                    printf("%d\n", i);
                    return (-1);
                }
            }
            k++;
        }
        i++;
    }

    return (1);
}
