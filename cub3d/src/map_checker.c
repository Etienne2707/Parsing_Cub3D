#include "../includes/parsing.h"


int check_char(char **map)
{
    int i;
    int k;
    int n_counter;

    i = 0;
    n_counter = 0;
    while (map[i] != 0)
    {
        k = 0;
        while (map[i][k] != '\0')
        {
            //printf("%c",map[i][k]);
            if (map[i][k] != 32 && map[i][k] != '1' && map[i][k] != '0' && map[i][k] != 'N')
                return (-1);
            if (map[i][k] == 'N')
                n_counter++;
            k++;
        }
        i++;
    }
    if (n_counter > 1)
        return (-1);
    return (1);

}

int check_map(char **map)
{
    if (check_char(map) == -1)
        return (-1);
    
}
