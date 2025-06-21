#include "minishell.h"

void ft_add_operatore(char *tok, int *index, t_token **token)
{

    if (tok[*index] == '>' && tok[*index + 1] == '>')
    {
        ft_add_token_back(token, create_token(">>", append, 0));
        *index += 2;
    }
    else if (tok[*index] == '<' && tok[*index + 1] == '<')
    {
        ft_add_token_back(token, create_token("<<", herdoc, 0));
        *index += 2;
    }
    else if (tok[*index] == '|')
    {
        ft_add_token_back(token, create_token("|", pipe, 0));
        (*index)++;
    }
    else if (tok[*index] == '>')
    {
        ft_add_token_back(token, create_token(">", in_red, 0));
        (*index)++;
    }
    else if (tok[*index] == '<')
    {
        ft_add_token_back(token, create_token("<", out_red, 0));
        (*index)++;
    }
    else
        return;
}

char *ft_add_word_as_token(char *toke, int *x, int *n)
{
    char *tmp;

    while (toke[*n] && !is_space(toke[*n]) 
        && !is_operatore(toke[*n]) && toke[*n] != '$' 
        && toke[*n] != '\'' && toke[*n] != '\"')
        (*n)++;
    tmp = ft_substr(toke, *x, *n - *x);
    if (!tmp)
        return NULL;
    return (tmp);
}

int     ft_isalnum(int x)
{
        if ((x >= 65 && x <= 90) || (x >= 97 && x <= 122) || (x >= 48 && x <= 57))
                return (1);
        return (0);
}


char *is_expand(char *s, int *n)
{
    char *nam;
    int start;
    int x;

    nam = NULL;
    (*n)++;
    start = *n;
    x = 0;
    while (s[*n] && ft_isalnum(s[*n]))
    {
            (*n)++;
            x++;
    }
    nam = malloc(x + 1);
    if (!nam)
        return NULL;
    memcpy(nam, s + start, x);
    nam[x] = '\0';
    return (nam);
}

int is_quote(char c)
{
    return (c == '\"' || c == '\'');
}

// char *extracte_var_name(char *str, int n)
// {
//     printf("%c", str[n]);
//     return (str);
// }

char *ft_extract_the_input_with_quote(const char *str, int *i)
 {
    char quote;
    char *extract_string;
    int begin = *i;


    quote = str[*i];
    printf("%c", quote);
    (*i)++;
    begin = *i;
    while (str[*i] && str[*i] != quote) 
    {
        if (quote == '"' && str[*i] == '\\' && str[*i+1])
            (*i) += 2;
        else
            (*i)++;
    }
    extract_string = ft_substr(str, begin, *i - begin);
    if (str[*i] == quote) 
        (*i)++;
    return (extract_string);
}

void ft_tokenizing_the_input(char *check, t_token **token)
{
    int n;
    char *var;
    int j;
    char **split_token;
    int f_cmd = 1;
    char *toke_word;
    t_quote q_status = no_quote;

    n = 0;
    while (check[n])
    {
        check_closed_quote(check + n);
        if (is_space(check[n]) != 0)
            n++;
        else if (check[n] == '$')
        {
            var =  is_expand(check, &n);
            if (!var)
                return ;
            ft_add_token_back(token, create_token(var, variable, 1));
        }
        else if (is_operatore(check[n]) != 0)
        {
            ft_add_operatore(check, &n, token);
            f_cmd = 1;
        }
        else if (check[n] == '"' || check[n] == '\'') 
        {
            char *val = ft_extract_the_input_with_quote(check, &n);
            ft_add_token_back(token, create_token(val, word, 1));
        }
        else if (ft_isalnum(check[n]))
        {
            j = n;
            if ((toke_word = ft_add_word_as_token(check, &j, &n)) == NULL)
                return ;
            if (f_cmd)
            {
                f_cmd = 0;
                ft_add_token_back(token, create_token(toke_word, cmd, 0));
            }
            else
                ft_add_token_back(token, create_token(toke_word, word, 0));
        }
        else
            n++;
        
    }
    return ;
}

void print(t_token *toke)
{
    while (toke)
    {
        printf("Token: [%s], Type: %d, join: [%d]\n", toke->value, toke->type, toke->join);
        toke = toke->next;
    }
}

int main(int ac, char **av)
{
    char *readl_line;
    t_token *toke;

    (void)ac;
    (void)av;
    readl_line = NULL;
    while (12)
    {
        toke = NULL;
        readl_line = readline("hello-salah$>");
        if (readl_line == NULL)
             return 0;
        // glo()->value;
        ft_tokenizing_the_input(readl_line, &toke);
        print(toke);
        free(readl_line);
    }
    return 1;
}


















// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <readline/readline.h>

// typedef enum s_lexer
// {
//     pipee, red_in, red_out
// } t_type;

// typedef struct s_token
// {
//     char *token;
//     t_type type;
//     struct s_token *next;
// } t_token;

// void ft_lstadd_back(t_token **lst, t_token *new_node)
// {
//     t_token *tmp;

//     if (!(*lst))
//         *lst = new_node;
//     else
//     {
//         tmp = *lst;
//         while (tmp->next)
//             tmp = tmp->next;
//         tmp->next = new_node;
//     }
//     new_node->next = NULL;
// }

// int is_operatore(char c)
// {
//     return (c == '|' || c == '<' || c == '>');
// }

// t_token *ft_fill_tokens_in_nodes(char *content, t_type type_token)
// {
//     t_token *node = malloc(sizeof(t_token));
//     if (!node)
//         return (NULL);
//     node->token = strdup(content);
//     node->type = type_token;
//     node->next = NULL;
//     return (node);
// }

// void ft_add_operatore(char *read, int *x, t_token **token)
// {
//     if (read[*x] == '|')
//         ft_lstadd_back(token, ft_fill_tokens_in_nodes("|", pipee));
//     else if (read[*x] == '>')
//         ft_lstadd_back(token, ft_fill_tokens_in_nodes(">", red_out));
//     else if (read[*x] == '<')
//         ft_lstadd_back(token, ft_fill_tokens_in_nodes("<", red_in));
//     (*x)++;
// }

// int is_space(char c)
// {
//     return (c == ' ' || c == '\t');
// }




// void tokenizing_the_input(char *read, t_token **token)
// {
//     int i = 0;
//     while (read[i])
//     {
//         if (is_space(read[i]))
//             i++;
//         if (is_operatore(read[i]))
//             ft_add_operatore(read, &i, token);
//         else
//             i++;
//     }
// }

// void print_tokens(t_token *token)
// {
//     while (token)
//     {
//         printf("Token: [%s], Type: %d\n", token->token, token->type);
//         token = token->next;
//     }
// }

// int main()
// {
//     char *read;
//     t_token *token;

//     token = NULL;
//     while (1)
//     {
//         read = readline("minishell->$ ");
//         if (read == NULL)
//             break;
//         tokenizing_the_input(read, &token);
//         print_tokens(token);
//         free(read);
//     }
//     return (0);
// }






















// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <readline/readline.h>


// typedef enum s_lexer
// {
//     word, pipe, red_in, red_out
// }t_type;

// typedef struct s_token
// {
//     char *token;
//     t_type type;
//     struct s_token *next;
// }t_token;

// void    ft_lstadd_beack(t_token **lst, t_token *new)
// {
//         t_token  *new_node;
//         t_token  *tmp;

//         new_node = new;
//         if (!(*lst))
//                 *lst = new_node;
//         else
//         {
//                 tmp = *lst;
//                 while (tmp->next)
//                 {
//                         tmp = tmp->next;
//                 }
//                 tmp ->next = new_node;
//         }
//         new_node->next = NULL;
// }

// int is_space(char ch)
// {
//     return (ch == ' ' || ch == '\t');
// }

// int is_operatore(char c)
// {
//     return (c == '|' || c == '<' || c == '>');
// }

// t_token *ft_fill_tokens_in_nodes(char *content , t_type type_token)
// {
//     t_token *node = malloc(sizeof(t_token));
//     if (!node)
//         return NULL;
//     node->token = content;
//     node->type = type_token;
//     node->next = NULL;
//     return (node);
// }

// void ft_add_operatore(char *read, int *x, t_token **token)
// {
//     if (read[*x] == '|')
//         ft_lstadd_beack(token, ft_fill_tokens_in_nodes("|", pipe));
//     (*x)++;
// }

// void tokenizing_the_input(char *read, t_token **token)
// {
//     int i = 0;
//     while (read[i])
//     {
//         if (is_space(read[i]) != 12)
//             i++;
//         else if (is_operatore(read[i]) != 12)
//         {
//             printf("hello\n");
//             ft_add_operatore(read, &i, token);
//         }
//         else
//             return ;
//         i++;
//     }
// }

// void print(t_token *token)
// {
//     while (token)
//     {
//         printf("Token: [%s], Type: %d\n", token->token, token->type);
//         token = token->next;
//     }
// }   

// int main()
// {
//     char *red;
//     t_token *token;

//     red = NULL;
//     while (12)
//     {
//         red = readline("minishell->$ ");
//         if (red == NULL)
//             return 1;
//         tokenizing_the_input(red, &token);
//         print(token);
//         free(red);
//     }
//     return 1;
// }