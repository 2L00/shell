// #include "minishell.h"
//
// void	init_quote_state(t_quote_state *state)
// {
// 	state->in_single = 0;
// 	state->in_double = 0;
// 	state->escape_next = 0;
// 	state->is_dollar = 0;
// }
//
// static char	*get_env_value(char **envp, char *var_name)
// {
// 	char	*full_var;
// 	int		i;
// 	size_t	var_len;
//
// 	if (!var_name || !envp)
// 		return (NULL);
// 	full_var = ft_strjoin(var_name, "=");
// 	if (!full_var)
// 		return (NULL);
// 	var_len = ft_strlen(full_var);
// 	i = 0;
// 	while (envp[i])
// 	{
// 		if (ft_strncmp(envp[i], full_var, var_len) == 0)
// 		{
// 			free(full_var);
// 			return (envp[i] + var_len);
// 		}
// 		i++;
// 	}
// 	free(full_var);
// 	return (NULL);
// }
//
// int	should_include_char(char c, t_quote_state *state)
// {
// 	state->is_dollar = 0;
// 	if (state->escape_next)
// 	{
// 		state->escape_next = 0;
// 		return (1);
// 	}
// 	if (c == '\\' && !state->in_double && !state->in_single)
// 	{
// 		state->escape_next = 1;
// 		return (1);
// 	}
// 	if (c == '\'' && !state->in_double)
// 	{
// 		state->in_single = !state->in_single;
// 		return (0);
// 	}
// 	if (c == '$')
// 		state->is_dollar = 1;
// 	if (c == '"' && !state->in_single)
// 	{
// 		state->in_double = !state->in_double;
// 		return (0);
// 	}
// 	return (1);
// }
//
// char	*return_env_val(int *i, char *token, t_shell *shell, int start)
// {
// 	char	*var_name;
// 	char	*value;
// 	char	*dup;
//
// 	while (ft_isalnum(token[*i]))
// 		(*i)++;
// 	var_name = ft_substr(token, start, *i - start);
// 	if (!var_name)
// 		return (NULL);
// 	value = get_env_value(shell->envp, var_name);
// 	free(var_name);
// 	if (value != NULL)
// 	{
// 		dup = ft_strdup(value);
// 		return (dup);
// 	}
// 	return (ft_strdup(""));
// }
//
// char	*expand_dollar(t_shell *shell, char *token, int *i)
// {
// 	char	*var_name;
// 	char	*value;
// 	char	*dup;
// 	int		start;
//
// 	start = ++(*i); // Skip '$' and remember start position
// 	if (token[*i] == '?')
// 	{
// 		(*i)++;
// 		//    run_simple_cmd(shell, shell->envp);
// 		return (ft_itoa(shell->exit_status));
// 	}
// 	if (token[*i] == '$')
// 	{
// 		(*i)++;
// 		return (ft_itoa(getpid()));
// 	}
// 	dup = return_env_val(i, token, shell, start);
// 	return (dup);
// }
