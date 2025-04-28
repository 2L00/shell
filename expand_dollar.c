#include "minishell.h"

int	ft_valid_dollar(char *token, int i)
{
	if (token[i + 1] == ' ')
		return (0);
	if (token[i + 1] == '\t')
		return (0);
	if (token[i + 1] == '\n')
		return (0);
	if (token[i + 1] == '\0')
		return (0);
	return (1);
}

int	is_the_same(char *dest, char *src)
{
	int	i;

	i = 0;
	//  printf("%s               %s\n", src, dest);
	while (dest[i] && src[i])
	{
		if (dest[i] != src[i])
			return (1);
		i++;
	}
	return (0);
}

void	expand_dollar(t_quote_state *state, t_shell *shell, int *x, char *token)
{
	int			j;
	const char	*ptr = " \t\n";
	char		**str;
	char		*after_dollar;
	int			len;
	int			i;

	printf("you need $     %s\n", token);
	j = 0;
	i = *x;
	len = ft_strlen(token);
	after_dollar = malloc(len + 1);
	while (token[i]) // && ft_valid_dollar(token, i))
	{
		if (token[i] == '$') // && token[i + 1] == '$')
		{
			printf("in while     %c\n", token[i]);
			printf("%d\n", getpid());
			//      return ;
			//      i++;
		}
		//    else
		//    {
		after_dollar[j] = token[i];
		j++;
		i++;
	//	*x = i;
		//    }
	}
	after_dollar[j] = '=';
	j++;
	after_dollar[j] = '\0';
	j = 0;
	//  printf("%s\n", a fter_dollar);
	while (shell->envp[j])
	{
		if (is_the_same(shell->envp[j], after_dollar) == 0)
		{
			i = 0;
			while (shell->envp[j][i] != '=')
				i++;
			i++;
			while (shell->envp[j][i])
			{
				printf("%c", shell->envp[j][i]);
				i++;
			}
			printf("\n");
			return ;
		}
		j++;
	}
}
