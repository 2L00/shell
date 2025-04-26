
#include "minishell.h"

char	*create_prompt(t_shell *shell)
{
	char	*read_l;
	char	cwd[1024];
	char	*str;

	read_l = NULL;
	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		perror(YELLOW"getcwd() error"RESET);
		exit((1));
	}
	str = ft_strjoin(cwd, "->$ ");
	shell->pwd = str;
	read_l = readline(str);
	if (read_l == NULL)
	{
		printf(YELLOW"the user press control D\n"RESET);
		exit(0);
	}
	if (strlen(read_l) != 0)
		add_history(read_l);
	if (unclosed_quotes(read_l))
	{
		printf(RED"command not found: %s\n"RESET, read_l);
		return (NULL);
	}
	return (read_l);
}
