/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abddahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 08:30:12 by abddahma          #+#    #+#             */
/*   Updated: 2025/04/19 16:40:38 by abddahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int ac, char **av, char **env)
{
	char **prompt;
	char **split;
	char *read_l;
	int i = 1;

	while (1)
	{
		split = ft_split(av[i], ' ');

//		if (av[i] == NULL)
//			return 0;
		read_l = readline("minishell->$ ");
		if (read_l == NULL || *read_l == '\0')
			continue;
//			return 0;
		printf("%s\n", read_l);
		i++;
	}

	i = 0;
	while (split[i])
	{
		printf("%s\n", split[i]);
		i++;
	}
}
