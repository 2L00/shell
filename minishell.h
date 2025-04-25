/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abddahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 08:26:04 by abddahma          #+#    #+#             */
/*   Updated: 2025/04/25 13:23:59 by abddahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define _GNU_SOURCE

# include "../libft/libft.h"
# include <errno.h>
# include <libgen.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_shell
{
	char	**prompt;

	int		in_double;
	int		in_single;
	char	*command;
	int expand;

	char	*pwd;
	char	**cmd;

}			t_shell;

typedef struct s_split_state
{
	int		in_single;
	int		in_double;
	int		escape_next;
	int		arg_start;
	int		arg_len;
}			t_split_state;

typedef struct s_quote_state
{
	int		in_single;
	int		in_double;
	int		escape_next;
}			t_quote_state;

char		**ft_split(const char *s, char c);
char		*find_cmd_path(char *cmd, char **envp);

void		run_simple_cmd(t_shell *shell, char **envp);
char		*create_prompt(t_shell *shell);
int			unclosed_quotes(const char *str, t_shell *shell);
void		handle_all_quotes(t_shell *shell);
void		single_or_double(char **cmd, t_shell *shell);
void		handle_shell_quotes(char **cmd, t_shell *shell);
char		**ft_split_shell(const char *str, const char *delim);

#endif
