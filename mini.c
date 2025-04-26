/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  abddahma < abddahma@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 16:27:23 by  abddahma         #+#    #+#             */
/*   Updated: 2025/04/25 15:42:20 by snait-ai         ###   ########.fr       */
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
	int					status;
	struct sigaction	sa;

	(void)ac;
	(void)argv;
	int i;
	read_l = NULL;
	i = 0;
	status = 0;
	sa.sa_handler = ft_handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGINT, &sa, NULL);
	while (1)
	{
		read_l = create_prompt(&shell);
		if (read_l != NULL && read_l[0] == '\0')
		{
			free(read_l);
			continue ;
		}
		if (read_l)
		{
			shell.command = read_l;
			shell.prompt = ft_split_shell(read_l, " \t\n");
			handle_shell_quotes(shell.prompt);
			i = 0;
			run_simple_cmd(&shell, envp);
		}
	}
}
