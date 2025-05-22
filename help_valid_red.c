
#include "minishell.h"

int	is_quote(char c)
{
	return (c == '\'' || c == '"');
}
int	is_special(char c)
{
	return (c == '|' || c == '>' || c == '<');
}
int	ft_is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

void	init_struct(t_valid *va)
{
	va->sq = 0;
	va->dq = 0;
	va->has_cmd = 0;
	va->is_append = 0;
	va->is_heredoc = 0;
}

int	valid_output(char *cmd, int *x, t_valid *va)
{
	int	i;

	i = *x;
	va->is_append = (cmd[i] == '>' && cmd[i + 1] == '>');
	va->is_heredoc = (cmd[i] == '<' && cmd[i + 1] == '<');
	if (va->is_append || va->is_heredoc)
		i += 2;
	else
		i += 1;
	while (ft_is_space(cmd[i]))
		i++;
	if (!cmd[i] || is_special(cmd[i]))
	{
		ft_putstr_fd("bash: syntax error near unexpected token\n", 2);
		return (0);
	}
	return (1);
}
