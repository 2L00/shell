#ifndef MINISHELL_H
#define MINISHELL_H

#include <readline/history.h>
#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>

// enum user define data type 0
typedef enum e_lexer
{
    cmd,// 0
    word,// 1
    pipe,// 2
    in_red,// 3
    out_red,// 4
    herdoc,// 5
    append,// 6
    variable,// 7
} t_lexer;

typedef enum e_quote 
{
    no_quote,
    SINGLE_QUOTE,
    DOUBLE_QUOTE
} t_quote;

typedef struct s_token
{
    t_lexer type;
    char *value;
    int join;// 1 = join | 0 == no join
    t_quote qoute;
    struct s_token *next;
} t_token;

int is_operatore(char c);
int is_space(char ch);
int ft_find_closed_quote(char *str, char q);
void ft_add_token_back(t_token **lst, t_token *new);
void check_closed_quote(char *str);
t_token *create_token(char *content, t_lexer new_type, int x);
char *ft_substr(char const *s, unsigned int start, size_t len);
void ft_tokenizing_the_input(char *check, t_token **token);

#endif