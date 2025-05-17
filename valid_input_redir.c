#include "minishell.h"

int	exist_quote(char *str, char c)
{
	int	in_single;
	int	in_double;
	int	i;

	in_single = 0;
	in_double = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			in_single = !in_single;
		if (str[i] == '"')
			in_double = !in_double;
		if (str[i] == c && (in_double || in_single))
		{
			printf("invalid redirection\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	valid_input_redir(char *cmd)
{
	int	in_quote;

	int (i), exist = 0;
	in_quote = 0;
	if (exist_quote(cmd, '<'))
		return (0);
	i = 0;
	while (cmd[i])
	{
		while (cmd[i] == ' ' || cmd[i] == '\t' || cmd[i] == '\n')
			i++;
		if (cmd[i] == '<' && (cmd[i + 1] == '>' || cmd[i + 1] == '<'))
			i += 2;
		if (exist == 0 && (cmd[i] == '|' || cmd[i] == '>' || cmd[i] == '<'))
			return (0);
		if (ft_isprint(cmd[i]) && cmd[i] != '>' && cmd[i] != '|')
			exist = 1;
		if (!cmd[i])
			break ;
		if (cmd[i] == '<')
			exist = 0;
		i++;
	}
	return (exist);
}
//
//
// int main(int ac, char **av)
// {
//   if (valid_input_redir(av[1]) == 0)
//   {
//     printf("error\n");
//   }
//   else {
//     printf("valid :)))\n");
//   }
//
// }
