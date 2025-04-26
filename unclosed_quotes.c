

#include "minishell.h"

int	unclosed_quotes(const char *str)
{
	int	in_single;
	int	in_double;

	in_single = 0;
	in_double = 0;
	while (*str)
	{
		if (*str == '\'' && !in_double)
			in_single = !in_single;
		else if (*str == '"' && !in_single)
			in_double = !in_double;
		str++;
	}
	return (!!(in_single + in_double));
}
