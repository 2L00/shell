#include "minishell.h"

int	valid_pipe(char *cmd, int *x, t_valid *va)
{
	int	i;

	i = *x;
	if (!va->has_cmd)
	{
		ft_putstr_fd("bash: syntax error near unexpected token\n", 2);
		return (0);
	}
	i++;
	while (ft_is_space(cmd[i]))
		i++;
	if (!cmd[i] || cmd[i] == '|')
	{
		ft_putstr_fd("bash: syntax error near unexpected token\n", 2);
		return (0);
	}
	va->has_cmd = 0;
	return (1);
}

void	help_red(char *cmd, int *x, t_valid *va)
{
	int	i;

	i = *x;
	while (ft_is_space(cmd[i]))
		i++;
	if (cmd[i] == '\'' && !va->dq)
		va->sq = !va->sq;
	else if (cmd[i] == '"' && !va->sq)
		va->dq = !va->dq;
}

int	help_go(char *cmd, int *x, t_valid *va)
{
	int	i;

	i = *x;
	if (cmd[i] == '>' || cmd[i] == '<')
		if (valid_output(cmd, &i, va) == 0)
			return (0);
	if (cmd[i] == '|')
		if (valid_pipe(cmd, &i, va) == 0)
			return (0);
	return (1);
}

int	valid_output_redir(char *cmd)
{
	t_valid	va;
	int		i;
	int		res;

	init_struct(&va);
	i = -1;
	while (cmd[++i])
	{
		help_red(cmd, &i, &va);
		if (va.sq || va.dq)
			continue ;
		if (!cmd[i])
			break ;
		res = help_go(cmd, &i, &va);
		if (res == 0)
			return (0);
		va.has_cmd = 1;
	}
	return (va.has_cmd);
}
