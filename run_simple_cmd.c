/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simple_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  abddahma < abddahma@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 16:28:05 by  abddahma         #+#    #+#             */
/*   Updated: 2025/04/25 13:23:47 by abddahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	with_backslash(t_shell *shell, char *cmd_path, char **envp, int i)
{
	pid_t	pid;
	char	**en;
	int		status;

	status = 0;
	pid = fork();
	if (pid == 0)
	{
		en = shell->prompt;
		if (execve(shell->prompt[i], en, envp) < 0)
		{
			printf("bash: %s: %s\n", shell->prompt[i], strerror(errno));
			exit((1));
		}
	}
	else if (pid > 0)
		waitpid(pid, &status, 0);
	return ;
}

static void	with_out_backslash(t_shell *shell, char *cmd_path, char **envp,
		int x)
{
	pid_t	pid;
	char	**en;
	int		status;
	int		i;

	status = 0;
	pid = fork();
	if (pid == 0)
	{
		en = shell->prompt;
		i = x;
		// while (en[i])
		//{
		//	printf("en     %s\n", en[i]);
		//	i++;
		//}
		if (execve(cmd_path, en, envp) < 0)
			exit((printf("%s: command not found\n", shell->prompt[i]),
					shell->exit_status));
	}
	else if (pid > 0)
		waitpid(pid, &shell->exit_status, 0);
	return ;
}

void	run_simple_cmd(t_shell *shell, char **envp)
{
	pid_t	pid;
	char	*cmd_path;
	char	**en;

	int(i), status = 0;
	i = 0;
	while (shell->prompt[i])
	{
		if (shell->prompt[i][0] != '/')
		{
			cmd_path = find_cmd_path(shell->prompt[i], envp);
			with_out_backslash(shell, cmd_path, envp, i);
			return ;
		}
		else if (shell->prompt[i][0] == '/')
		{
			with_backslash(shell, cmd_path, envp, i);
			return ;
		}
		i++;
	}
}
