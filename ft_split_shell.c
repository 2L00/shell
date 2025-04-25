#include "minishell.h"

static void	init_split_state(t_split_state *state)
{
	state->in_single = 0;
	state->in_double = 0;
	state->escape_next = 0;
	state->arg_start = -1;
	state->arg_len = 0;
}

static int	is_separe(char c, const char *separe)
{
	while (*separe)
	{
		if (c == *separe)
			return (1);
		separe++;
	}
	return (0);
}

static void	handle_char(t_split_state *state, const char *str, int i)
{
	if (state->escape_next)
	{
		state->escape_next = 0;
		return ;
	}
	if (str[i] == '\\' && !state->in_single && !state->in_double)
	{
		state->escape_next = 1;
		return ;
	}
	if (str[i] == '\'' && !state->in_double)
	{
		state->in_single = !state->in_single;
		return ;
	}
	if (str[i] == '"' && !state->in_single)
	{
		state->in_double = !state->in_double;
		return ;
	}
}

static int	count_args(const char *str, const char *separe)
{
	t_split_state	state;
	int				count;
	int				i;

	count = 0;
	i = 0;
	init_split_state(&state);
	while (str[i])
	{
		handle_char(&state, str, i);
		if (!state.in_single && !state.in_double && !state.escape_next
			&& is_separe(str[i], separe))
		{
			if (state.arg_start != -1)
			{
				count++;
				state.arg_start = -1;
			}
		}
		else if (state.arg_start == -1)
		{
			state.arg_start = i;
		}
		i++;
	}
	if (state.arg_start != -1)
		count++;
	return (count);
}

static char	**fill_args(const char *str, const char *separe, char **args)
{
	t_split_state	state;
	int				i;
	int				arg_idx;

	i = 0;
	arg_idx = 0;
	init_split_state(&state);
	while (str[i])
	{
		handle_char(&state, str, i);
		if (!state.in_single && !state.in_double && !state.escape_next
			&& is_separe(str[i], separe))
		{
			if (state.arg_start != -1)
			{
				args[arg_idx] = ft_substr(str, state.arg_start, i
						- state.arg_start);
				arg_idx++;
				state.arg_start = -1;
			}
		}
		else if (state.arg_start == -1)
		{
			state.arg_start = i;
		}
		i++;
	}
	if (state.arg_start != -1)
	{
		args[arg_idx] = ft_substr(str, state.arg_start, i - state.arg_start);
		arg_idx++;
	}
	args[arg_idx] = NULL;
	return (args);
}

char	**ft_split_shell(const char *str, const char *separe)
{
	char	**args;
	int		arg_count;

	if (!str || !separe)
		return (NULL);
	arg_count = count_args(str, separe);
	args = (char **)malloc(sizeof(char *) * (arg_count + 1));
	if (!args)
		return (NULL);
	return (fill_args(str, separe, args));
}
