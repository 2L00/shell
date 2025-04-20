/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  abddahma < abddahma@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 16:27:23 by  abddahma         #+#    #+#             */
/*   Updated: 2025/04/20 16:53:46 by abddahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_handler(int x)
{
	(void)x;
	printf("\n");
	return ;
}

int main(int ac, char **argv, char **envp)
{
	t_shell shell;
	char **split;
	char *read_l = NULL;
	pid_t pid;
	int i = 1, x = 0;
	int status = 0;
	struct sigaction sa;

	sa.sa_handler = ft_handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGINT, &sa, NULL);
	while (1)
	{
		read_l = readline("minishell->$ ");
		if (read_l == NULL)
                {
                        printf("the user press control D\n");
                        exit(0);
                }
		if (*read_l == '\0')
			continue;
		if (strlen(read_l) != 0)
		{
			char str[1024];
			add_history(read_l);
			strcpy(str, read_l);
		}
		shell.prompt = ft_split(read_l, ' ');
		i = 0;
		while (shell.prompt[i])
		{
			printf(">>  %s\n", shell.prompt[i]);
			i++;
		}
		i = 0;
		
		run_simple_cmd(&shell, envp);

	}


}
