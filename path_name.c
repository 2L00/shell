/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_name.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  abddahma < abddahma@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 16:27:53 by  abddahma         #+#    #+#             */
/*   Updated: 2025/04/20 16:27:55 by  abddahma        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static char	*cmds_paths(char **ev)
{
	int	i;

	i = 0;
	while (ev[i])
	{
		if (!ft_strncmp(ev[i], "PATH=", 5))
			return (ev[i] + 5);
		i++;
	}
	return (NULL);
}

char	*find_cmd_path(char *cmd, char **envp)
{
	char	*path;
	char	**dirs;
	char	*full_path;
	int		i;
	char	*temp;

	path = cmds_paths(envp);
	if (!path)
		return (NULL);
	dirs = ft_split(path, ':');
	full_path = NULL;
	i = 0;
	while (dirs[i])
	{
		temp = ft_strjoin(dirs[i], "/");
		full_path = ft_strjoin(temp, cmd);
		free(temp);
		if (!full_path)
			return (ft_free(dirs), NULL);
		if (access(full_path, F_OK) == 0)
			return (ft_free(dirs), full_path);
		free(full_path);
		i++;
	}
	return (ft_free(dirs), NULL);
}
