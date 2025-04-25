/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  abddahma < abddahma@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 16:27:23 by  abddahma         #+#    #+#             */
/*   Updated: 2025/04/25 13:23:56 by abddahma         ###   ########.fr       */
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

	int (i), x = 0;
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
//		printf("read_l    %s\n", read_l);
		if (read_l != NULL && read_l[0] == '\0')
		{
			free(read_l);
			continue ;
		}
		if (read_l)
		{
			shell.command = read_l;
			shell.prompt = ft_split_shell(read_l, " \t\n");
//			handle_all_quotes(&shell);
			handle_shell_quotes(shell.prompt, &shell);
//			echo "''\" \" \"
//			single_or_double(shell.prompt, &shell);
			i = 0;
//			while (shell.prompt[i])
//			{
//				printf(">>  %s\n", shell.prompt[i]);
//				i++;
//			}
			i = 0;
			run_simple_cmd(&shell, envp);
		}
	}
}
