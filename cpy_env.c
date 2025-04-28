#include "minishell.h"


static void	cpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

void	store_envp(char **envp, t_shell *shell)
{
	int		j;
	size_t	len;

	j = 0;
	while (envp[j])
		j++;
	shell->envp = malloc(sizeof(char *) * (j + 1));
	j = 0;
	while (envp[j])
	{
		len = ft_strlen(envp[j]);
		shell->envp[j] = malloc(len + 1);
		cpy(shell->envp[j], envp[j]);
		j++;
	}
	shell->envp[j] = NULL;
}
