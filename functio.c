#include "minishell.h"

int is_space(char ch)
{
    return (ch == ' ' || ch == '\t' || ch == '\n');
}

int is_operatore(char c)
{
    return (c == '|' || c == '>' || c == '<');
}
// t_token *glo(void)
// {
//     static t_token g_token;
//     return (&g_token);
// }

   // glo()->value = "feeef";
    // printf("%s\n", glo()->value);

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    unsigned int i;
    char *sub_str;

    if (s == NULL)
        return (NULL);
    if (start >= strlen(s))
        len = 0;
    else if (len > strlen(s + start))
    {
        len = strlen(s + start);
    }
    sub_str = (char *)malloc((len + 1) * sizeof(char));
    if (sub_str == NULL)
        return (NULL);
    i = 0;
    while (start + i < strlen(s) && i < len)
    {
        sub_str[i] = s[start + i];
        i++;
    }
    sub_str[i] = '\0';
    return (sub_str);
}

t_token *create_token(char *content, t_lexer new_type, int x)
{
    t_token *new_token;

    new_token = malloc((sizeof(t_token)));
    if (!new_token)
        return NULL;
    new_token->value = content;
    new_token->join = x;
    new_token->type = new_type;
    new_token->next = NULL;
    // printf("hello\n %s\n", new_token->value);
    return (new_token);
}

void ft_add_token_back(t_token **lst, t_token *new)
{
    t_token *new_node;
    t_token *tmp;

    new_node = new;
    if (!(*lst))
        *lst = new_node;
    else
    {
        tmp = *lst;
        while (tmp->next)
        {
            tmp = tmp->next;
        }
        tmp->next = new_node;
    }
    new_node->next = NULL;
}