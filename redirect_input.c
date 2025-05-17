#include "minishell.h"

int  redirect_output (char *token, int *i, t_shell *shell, char *result)
// {
//   int x = ++(*pos_prompt);
//
//   int fd = open(shell->prompt[x], O_CREAT | O_WRONLY | O_TRUNC, 0644);
//   if (fd < 0)
//   {
//     printf("ERROR in  FD");
//     return;
//   }
//
//   if (dup2(fd, STDOUT_FILENO) < 0) {
//     perror("minishell");
//     close(fd);
//     return;
//   }
//   close(fd);
//   printf("prompt    %s\n", shell->prompt[x]);
//   run_simple_cmd(shell, shell->envp);
// }
//
//
//

//int handle_output_redir(t_shell *shell, int *i, int saved_stdout, int flags)
{

    int saved_stdout = 0,  flags = 0;
    int fd;
    char *filename;

    if (!shell->prompt[*i + 1]) {
        ft_putstr_fd("minishell: syntax error near unexpected token `newline'\n", 2);
        return 0;
    }

    filename = shell->prompt[*i + 1];
    fd = open(filename, O_CREAT | O_WRONLY | flags, 0644);
    if (fd < 0) {
        perror("minishell");
        return 0;
    }

    if (dup2(fd, STDOUT_FILENO) < 0) {
        perror("minishell");
        close(fd);
        return 0;
    }
    close(fd);

    shell->prompt[*i] = NULL;
    shell->prompt[*i + 1] = NULL;
    *i += 1;
    return 1;
}
