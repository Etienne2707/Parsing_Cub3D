#include "parsing.h"

int ft_check_format(char *src,char *format)
{
    char *str;
    int i;
    int k;

    i = ft_strlen(src) - 4;
    k = 0;
    str = malloc(sizeof(char) * 5);
    if (!str)
        return (-1);
    while (src[i] != '\0')
    {
        str[k++] = src[i++];
    }
    str[k] = '\0';
    printf("%s\n",str);
    if (ft_strncmp(str,format,4) != 0)
    {
        free(str);
        return (-1);
    }
    free(str);
    return (1);
}