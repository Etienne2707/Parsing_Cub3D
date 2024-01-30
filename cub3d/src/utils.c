#include "parsing.h"

int skip_space(char *str, int i)
{
    if (!str)
        return (-1);
    while (str[i] == 32 && str[i] != '\0')
        i++;
    return (i);
}

void    printtab(char *str)
{
    int i;
    i = 0;

    while (str[i] != '\0')
    {
        printf("%c",str[i]);
        i++;
    }
    printf("\n");
}

char *get_nmalloc(char *str, int start, int end)
{
    char *dest;
    int i;

    i = 0;
    dest = malloc(sizeof(char *) * end - start + 1);
    if (!dest)
        return (NULL);
    while (start != end)
    {
        dest[i++] = str[start++];
    }
    dest[i] = 0;
    return (dest);
}

int ft_strstr(char *str, char *to_find)
{
	int i;
	int j;

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (to_find[j] == str[i + j])
		{
			if (to_find[j + 1] == '\0')
			{
				return (i);
			}
			j++;
		}
		i++;
	}
	return (0);
}


void    printdoubletab(char **str)
{
    int i;
    int k;

    i = 0;
    k = 0;
    while (str[k] != 0)
    {
        printtab(str[k]);
        k++;
    }
}

int check_arg_after(char *str, int last)
{
    int i;

    i = 0;
    if (str[last] == '\n')
        return (0);
    last = skip_space(str,last);
    printf("%d",str[last]);
    if (str[last] != '\n')
    {
        return (-1);
    }
}