/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abddahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 08:26:04 by abddahma          #+#    #+#             */
/*   Updated: 2025/04/20 14:33:58 by snait-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

#include <stdlib.h>
# include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include "../libft/libft.h"
#include <signal.h>

typedef struct s_shell
{
	char **prompt;

}	t_shell;


char	**ft_split(const char *s, char c);
char    *find_cmd_path(char *cmd, char **envp) ;








#endif
