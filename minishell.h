/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  abddahma < abddahma@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 08:26:04 by abddahma          #+#    #+#             */
/*   Updated: 2025/05/22 19:01:31 by  abddahma        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <errno.h>
# include <fcntl.h>
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
	int		exit_status;
	int		in_double;
	int		in_single;
	char	*command;
	int		expand;

	int		redirect_input;
	int		redirect_output;

	char	*outfile;
	char	*infile;

	char	*pwd;
	char	**cmd;
	char	**envp;

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
	int		is_dollar;
	char	**envp;
	int		escape_next;
}			t_quote_state;

typedef struct s_valid   // to check if i have valid redirection and pipe  i use it in valid_redir_pipe
{
	int	sq;
	int	dq;
	int	has_cmd;
	int	is_append;
	int	is_heredoc;

}		t_valid;



char		**ft_split(const char *s, char c);
char		*find_cmd_path(char *cmd, char **envp);

void		run_simple_cmd(t_shell *shell, char **envp);
char		*create_prompt(t_shell *shell);
int			unclosed_quotes(const char *str, t_shell *shell);
// void		handle_all_quotes(t_shell *shell);
// void		single_or_double(char **cmd, t_shell *shell);
void		handle_shell_quotes(char **cmd, t_shell *shell);
char		**ft_split_shell(const char *str, const char *delim);
void		store_envp(char **envp, t_shell *shell);

// int redirect_output(char *token, int *pos_prompt, t_shell *shell,
//	char *result);

int			redirect_output(char *token, int *pos_prompt, t_shell *shell,
				char *result);
// void redirect_output (char *token, int *i, t_shell *shell, char *result);
// void		execute_command(char **args, char *input_file, char *output_file);

// int			handle_redirection(t_shell *shell);

int			valid_input_redir(char *cmd);
// int	valid_output_redir(char *cmd);
// int			valid_output_redir(char *command);
// int			exist_quotes(char *str);
// int			validate_redirection(char **tokens, int *i, t_shell *shell,
				// int is_input);
// int exist_quotes(char *str);

void		init_shell_redir(t_shell *shell);
void		init_quote_state(t_quote_state *state);
char		*get_env_value(char **envp, char *var_name);
int			should_include_char(char c, t_quote_state *state);
char		*expand_dollar(t_shell *shell, char *token, int *i);

// int valid_heredoc(char *cmd);
// int	redir_out_append(char *cmd);
// int	valid_pipe(char *cmd);
//int	redir_out_append(char *cmd);
// void expand_dollar(t_quote_state *state, t_shell *shell, int *i,
//	char *token);
// char *expand_dollar(t_shell *shell, char *token, int *i);




int	ft_is_space(char c);

int	is_quote(char c);
int	is_special(char c);
void	init_struct(t_valid *va);
int	valid_output(char *cmd, int *x, t_valid *va);
int	valid_output_redir(char *cmd);

#endif
