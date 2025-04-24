

#include "minishell.h"

int	unclosed_quotes(const char *str, t_shell *shell)
{

	int in_single = 0;
	int in_double = 0;

	while (*str)
	{
		if (*str == '\'' && !in_double)
			in_single = !in_single;
		else if (*str == '"' && !in_single)
			in_double = !in_double;
		str++;
	}
//	printf("%d    %d\n", in_single, in_double);
//	shell->in_single = in_single;
//	shell->in_double = in_double;
//	printf("%d    %d\n", shell->in_single, shell->in_double);
	return (!!(in_single + in_double));
}
