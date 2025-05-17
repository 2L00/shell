#include "minishell.h"

int	exist_quotes(char *str)
{
	int	in_single;
	int	in_double;
	int	i;

	in_single = 0;
	in_double = 0;
	i = 0;
	printf("%s\n", str);
	while (str[i])
	{
		if (str[i] == '\'' && !in_double)
			in_single = !in_single;
		else if (str[i] == '"' && !in_single)
			in_double = !in_double;
		if (in_single || in_double)
		{
			ft_putstr_fd("minishell: syntax error: unclosed quotes\n", 2);
			return (1);
		}
		return (0);
	}
}

int	valid_output_redir(char *cmd)
{
	int(i), exist = -1;
	if (exist_quotes(cmd))
		return (0);
	i = -1;
	while (cmd[++i])
	{
		while (cmd[i] && (cmd[i] == ' ' || cmd[i] == '\t' || cmd[i] == '\n'))
			i++;
		if (cmd[i] && cmd[i] == '>' && cmd[i + 1] == '>')
			i += 2;
		if (exist == 0 && (!cmd[i] || cmd[i] == '|' || cmd[i] == '>'
				|| cmd[i] == '<'))
			return (0);
		if (cmd[i] == '>' && cmd[i + 1] == '|')
		{
			if (!exist)
				return (ft_putstr_fd("minishell: syntax error\n", 2), 0);
			i += 1;
			exist = 0;
			continue ;
		}
		if (ft_isprint(cmd[i]))
			exist = 1;
		if (cmd[i] == '>')
			exist = 0;
	}
	return (exist);
}
