
#include "minishell.h"

char	*create_prompt(t_shell *shell)
{
	char	*read_l;
	char	cwd[1024];
	char	*str;

	read_l = NULL;
	if (getcwd(cwd, sizeof(cwd)) == NULL) // for change the pwd
	{
		perror("getcwd() error");
		exit((1));
	}
	str = ft_strjoin(cwd, "->$");
	shell->pwd = str;
	read_l = readline(str);
	if (read_l == NULL)
	{
		printf("the user press control D\n");
		exit(0);
	}
	if (strlen(read_l) != 0)
		add_history(read_l);
	if (unclosed_quotes(read_l, shell)) // check if i have valid quotes
	{
		printf("hello command not found: %s\n", read_l);
		return (NULL);
	}
	return (read_l);
}
