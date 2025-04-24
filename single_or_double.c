#include "minishell.h"

typedef struct s_quote_state
{
	int		in_single;
	int		in_double;
	int		escape_next;
}			t_quote_state;

static void	init_quote_state(t_quote_state *state)
{
	state->in_single = 0;
	state->in_double = 0;
	state->escape_next = 0;
}

static int	should_include_char(char c, t_quote_state *state)
{
	if (state->escape_next)
	{
		state->escape_next = 0;
		return (1);
	}
	if (c == '\\')
	{
		state->escape_next = 1;
		return (1);
	}
	if (c == '\'' && !state->in_double)
	{
		state->in_single = !state->in_single;
		return (0);
	}
	if (c == '"' && !state->in_single)
	{
		state->in_double = !state->in_double;
		return (0);
	}
	return (1);
}

static char	*process_quotes_in_token(char *token)
{
	t_quote_state	state;
	char			*result;
	char			*temp;
	char			ch[2] = {0, 0};
	int				i;

	result = ft_strdup("");
	i = 0;
	if (!token || !result)
		return (NULL);
	init_quote_state(&state);
	while (token[i])
	{
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
	return (result);
}

void	handle_shell_quotes(char **tokens, t_shell *shell)
{
	char	*processed;
	int		i;

	i = 0;
	if (!tokens)
		return ;
	while (tokens[i])
	{
		processed = process_quotes_in_token(tokens[i]);
		if (processed)
		{
			free(tokens[i]);
			tokens[i] = processed;
		}
		i++;
	}
}
