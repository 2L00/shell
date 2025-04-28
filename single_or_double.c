#include "minishell.h"

static void	init_quote_state(t_quote_state *state)
{
	state->in_single = 0;
	state->in_double = 0;
	state->escape_next = 0;
	state->is_dollar = 0;
}

char	*get_env_value(char **envp, char *var_name)
{
	char	*full_var;
	int		i;
	size_t	var_len;

	if (!var_name || !envp)
		return (NULL);
	full_var = ft_strjoin(var_name, "=");
	if (!full_var)
		return (NULL);
	var_len = ft_strlen(full_var);
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], full_var, var_len) == 0)
		{
			free(full_var);
			return (envp[i] + var_len);
		}
		i++;
	}
	free(full_var);
	return (NULL);
}

static int	should_include_char(char c, t_quote_state *state)
{
	state->is_dollar = 0;
	if (state->escape_next)
	{
		state->escape_next = 0;
		return (1);
	}
	if (c == '\\' && !state->in_double && !state->in_single)
	{
		state->escape_next = 1;
		return (1);
	}
	if (c == '\'' && !state->in_double)
	{
		state->in_single = !state->in_single;
		return (0);
	}
	if (c == '$')
	{
		state->is_dollar = 1;
		//    return (0);
	}
	if (c == '"' && !state->in_single)
	{
		state->in_double = !state->in_double;
		return (0);
	}
	return (1);
}

static char	*expand_dollar(t_shell *shell, char *token, int *i)
{
	char	*var_name;
	char	*value;
	char	*dup;

	int start = ++(*i); // Skip '$' and remember start position
	// Handle special cases
	if (token[*i] == '?')
	{
		(*i)++;
		return (ft_itoa(shell->exit_status));
	}
	if (token[*i] == '$')
	{
		(*i)++;
		return (ft_itoa(getpid()));
	}
	// Find end of variable name
	while (ft_isalnum(token[*i]))
		(*i)++;
	var_name = ft_substr(token, start, *i - start);
	if (!var_name)
		return (NULL);
	value = get_env_value(shell->envp, var_name);
	free(var_name);
	if (value != NULL)
	{
		dup = ft_strdup(value);
		return (dup);
	}
	else
		return (ft_strdup(""));
}

static char	*process_quotes_in_token(char *token, t_shell *shell)
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
	while (token[i])
	{
		if (token[i] == '$' && !state.in_single && token[i + 1] && token[i
			+ 1] != '\'')
		// if (token[i] == '$' && !state.in_single && token[i + 1] != '\')
		{
			expansion = expand_dollar(shell, token, &i);
			if (!expansion)
			{
				free(result);
				return (NULL);
			}
			temp = ft_strjoin(result, expansion);
			free(result);
			free(expansion);
			result = temp;
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
		processed = process_quotes_in_token(tokens[i], shell);
		if (processed)
		{
			free(tokens[i]);
			tokens[i] = processed;
		}
		i++;
	}
}
