#include "minishell.h"

int ft_find_closed_quote(char *str, char q)
{
    int x = 1;

    while (str[x])
    {
        if (str[x] == q)
        {
            return 1;
        }
        x++;
    }
    return 0;

}

void check_closed_quote(char *str)
{
    if (*str == '\'' || *str == '\"')
    {
        if (ft_find_closed_quote(str, *str) != 0)
            printf("we fond the other quote\n");
        else
            printf("we did not fond the ather quote\n");
    }      
    return ;

}