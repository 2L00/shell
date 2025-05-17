/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  abddahma < abddahma@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 16:27:23 by  abddahma         #+#    #+#             */
/*   Updated: 2025/04/26 12:49:02 by abddahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_handler(int x)
{
	(void)x;
	printf("\n");
	return ;
}

int	main(int ac, char **argv, char **envp)
{
	t_shell				shell;
	char				*read_l;
	pid_t				pid;
	int					status;
	struct sigaction	sa;
	int					j;

	int(i), x = 0;
	read_l = NULL;
	j = 0;
	store_envp(envp, &shell);  //this func for copy env in struct to use it in cmd like "echo $HOME"
	i = 0;
	status = 0;
	sa.sa_handler = ft_handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGINT, &sa, NULL);
	while (1)
	{
		read_l = create_prompt(&shell); //create prompt and history
		if (read_l != NULL && read_l[0] == '\0')
		{
			free(read_l);
			continue ;
		}
		if (read_l)
		{
			shell.command = read_l;
			shell.prompt = ft_split_shell(read_l, " \t\n");
			handle_shell_quotes(shell.prompt, &shell);
//			run_simple_cmd(&shell, envp);
		}
	}
}
