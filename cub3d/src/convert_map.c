#include "parsing.h"

void   get_player_all(t_parsing *p, t_map *m)
{
    int i;
    int y;

    while (m->_map[i] != 0)
    {
        y = 0;
        while (m->_map[i][y] != '\0')
        {
            if (m->_map[i][y] == 'N' || m->_map[i][y] == 'S' || m->_map[i][y] == 'E' || m->_map[i][y] == 'W')
            {
                p->_playerD = m->_map[i][y];
                p->_playerX = y;
                p->_playerY = i;
                m->_map[i][y] = '0';
            }
            y++;        
        }
        i++;
    }
    return ;
}

void    convert_map_int(t_parsing *p, t_map *m)
{
    int x;
    int y;

    y = 0;
    p->_map = malloc(sizeof(int *) * m->_last - m->_first + 1);
    if (!p->_map)
        return ;
    while (m->_map[y] != 0)
    {
        x = 0;
        p->_map[y] = malloc(sizeof(int) * ft_strlen(m->_map[y]));
        if (!p->_map[y])
            return ;
        while (m->_map[y][x] != '\0')
        {
            p->_map[y][x] = m->_map[y][x] - 48;
            if (m->_map[y][x] == 32)
                p->_map[y][x] = 0;
            printf("%d", p->_map[y][x]);
            x++;
        }
        printf("\n");
        y++;
    }
}

void struct_parsing(t_parsing *p, t_map *m)
{
    get_player_all(p,m);
    convert_map_int(p,m);
}