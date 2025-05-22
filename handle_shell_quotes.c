#include "minishell.h"

char	*process_quotes(t_shell *shell, char *token, int *i, char *result)
{
	char	*temp;
	char	ch[2];
	char	*expansion;

	expansion = expand_dollar(shell, token, i);
	if (!expansion)
	{
		free(result);
		return (NULL);
	}
	temp = ft_strjoin(result, expansion);
	free(result);
	free(expansion);
	result = temp;
  return result;
}

static char	*process_quotes_in_token(char *token, t_shell *shell, int pos_prompt)
{
  t_quote_state	state;
  char			*result;
  char			*temp;
  char			ch[2];
  int				i;
  char			*expansion;

  shell->exit_status = 0;
  ch[0] = 0;
  ch[1] = 0;
  result = ft_strdup("");
  i = 0;
  if (!token || !result)
    return (NULL);
  init_quote_state(&state);

    // if (valid_output_redir(token, shell, pos_prompt))
    // {
    // return NULL;
    // }
    //
  while (token[i])
  {

    if (token[i] == '$' && !state.in_single && token[i + 1] && token[i
      + 1] != '\'')
    {
      result = process_quotes(shell, token, &i, result);
      if (!result)
        return (NULL);
      continue ;
    }

    if (should_include_char(token[i], &state))
    {
      ch[0] = token[i];
      temp = ft_strjoin(result, ch);
      free(result);
      if (!temp)
        return (NULL);
      result = temp;
    }
    i++;
  }

//     if (ft_strcmp(token, ">") == 0)// || ft_strcmp(token, ">>") == 0)
//     {
//         handle_redirection(shell);
//
// //      execute_command(shell->prompt, "input_file", "output_file");
// //      redirect_output(token, &pos_prompt, shell, result);
//     }

  return (result);
}



// int handle_input_redir(t_shell *shell, int *i, int saved_stdin)
// {
//     int fd;
//     char *filename;
//
//     if (!shell->prompt[*i + 1]) {
//         ft_putstr_fd("minishell: syntax error near unexpected token `newline'\n", 2);
//         return 0;
//     }
//
//     filename = shell->prompt[*i + 1];
//     fd = open(filename, O_RDONLY);
//     if (fd < 0) {
//         perror("minishell");
//         return 0;
//     }
//
//     if (dup2(fd, STDIN_FILENO) < 0) {
//         perror("minishell");
//         close(fd);
//         return 0;
//     }
//     close(fd);
//
//     shell->prompt[*i] = NULL;
//     shell->prompt[*i + 1] = NULL;
//     *i += 1;
//     return 1;
// }
//




// int handle_output_redir(t_shell *shell, int *i, int saved_stdout, int flags)
// {
//     int fd;
//     char *filename;
//
//     if (!shell->prompt[*i + 1]) {
//         ft_putstr_fd("minishell: syntax error near unexpected token `newline'\n", 2);
//         return 0;
//     }
//
//     filename = shell->prompt[*i + 1];
//     fd = open(filename, O_CREAT | O_WRONLY | flags, 0644);
//     if (fd < 0) {
//         perror("minishell");
//         return 0;
//     }
//
//     if (dup2(fd, STDOUT_FILENO) < 0) {
//         perror("minishell");
//         close(fd);
//         return 0;
//     }
//     close(fd);
//
//     shell->prompt[*i] = NULL;
//     shell->prompt[*i + 1] = NULL;
//     *i += 1;
//     return 1;
// }

// int handle_redirection(t_shell *shell)
// {
//     int i = 0;
//     int fd;
//     int saved_stdin = dup(STDIN_FILENO);
//     int saved_stdout = dup(STDOUT_FILENO);
//     int ret = 1;
//
//     while (shell->prompt[i] && ret)
//     {
//         // if (ft_strcmp(shell->prompt[i], "<") == 0)
//         // {
//         //     ret = handle_input_redir(shell, &i, saved_stdin);
//         // }
//         if (ft_strcmp(shell->prompt[i], ">") == 0)
//         {
//             ret = handle_output_redir(shell, &i, saved_stdout, O_TRUNC);
//         }
//         else
//         {
//             i++;
//         }
//     }
//
//     if (!ret) {
//         dup2(saved_stdin, STDIN_FILENO);
//         dup2(saved_stdout, STDOUT_FILENO);
//     }
//     close(saved_stdin);
//     close(saved_stdout);
//     return ret;
// }
//


// void split_redir(t_shell * shell)
// {
//   int i = 0;
//
//   while (shell->prompt[i])
//   { 
//     if (ft_strcmp(shell->prompt[i], ">"))
//         ft_split_shell(shell->prompt[i], ">");
// //      ft_split(shell->prompt[i], '>');
//     i++;
//   }
// }

void execute_command_shell(t_shell *shell)
{


  if (shell->redirect_output)
  {
  //   split_redir(shell);
        printf("you have redirect_output  out\n");
   }

   if (shell->redirect_input)
     printf("you have redirect_intput  in\n");
   if (!(shell)) 
   {
     shell->exit_status = 1;
     return;
   }

   if (shell->prompt[0])
   {
     run_simple_cmd(shell, shell->envp);
   }
}



void	handle_shell_quotes(char **tokens, t_shell *shell)
{
	char	*processed;
	int		i;

  init_shell_redir(shell);
  
  if (valid_output_redir(shell->command) == 0)
    return;

	i = 0;
	if (!tokens)
		return ;
	while (tokens[i])
  {

		// processed = process_quotes_in_token(tokens[i], shell, i);
		// if (processed)
		// {
		// 	free(tokens[i]);
		// 	tokens[i] = processed;
		// }
		//   printf("\033[31m%s\033[0m\n", tokens[i]);
		i++;
	}
//  printf("\033[31m%d\033[0m\n", shell->redirect_output);
// execute_command_shell(shell);

}
