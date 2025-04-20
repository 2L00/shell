/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abddahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 08:30:12 by abddahma          #+#    #+#             */
/*   Updated: 2025/04/20 14:04:33 by abddahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int ac, char **argv, char **envp)
{
	//	char *argv[] = { "ls", NULL };
	//	char *envp[] = { NULL };
	t_shell shell;

	char **split;
	char *read_l = NULL;
	pid_t pid;
	int i = 1, x = 0;
	int status = 0;

	while (1)
	{
		read_l = readline("minishell->$ ");
		if (strlen(read_l) != 0)
		{
			char str[1024];
			add_history(read_l);
			strcpy(str, read_l);
		}
		else
			printf("exit of add hist\n");
		if (read_l == NULL)
			break;
		if (*read_l == '\0')
			continue;

		shell.prompt = ft_split(read_l, ' ');
		i = 0;
		while (shell.prompt[i])
		{
			printf(">>  %s\n", shell.prompt[i]);
			i++;
		}
		i = 0;
		while (shell.prompt[i])
		{
			if (shell.prompt[i][0] != '/')
			{
				char *cmd_path = find_cmd_path(shell.prompt[i], envp);
				pid = fork();
				if (pid == 0)
				{
					char **en = shell.prompt;					
					if (execve(cmd_path, en, envp) < 0)
						exit((perror("error \n"), 1));
				}
				else if (pid > 0)
					waitpid(pid, &status, 0);
				break;
			}
			else if (shell.prompt[i][0] == '/')
			{
				pid = fork();
				if (pid == 0)
				{
					char **en = shell.prompt;
					if (execve(shell.prompt[0], en, envp) < 0)
					{
						printf("bash: %s: %s\n", shell.prompt[0], strerror(errno));
						exit((1));
					}
				}
				else if (pid > 0)  
					waitpid(pid, &status, 0);
				break;
			}
			i++;
		}

	}


}
