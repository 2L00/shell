/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abddahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 08:30:12 by abddahma          #+#    #+#             */
/*   Updated: 2025/04/19 17:08:51 by abddahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main()
{
	char **prompt;
	char **split;
	char *read_l = NULL;
	int i = 1;

	while (1)
	{

//		if (av[i] == NULL)
//			return 0;
		read_l = readline("minishell->$ ");
		if (read_l == NULL || *read_l == '\0')
			continue;
		if (read_l)
			split = ft_split(read_l, ' ');
		i = 0;
		while (split[i])
		{
			printf("%s\n", split[i]);
			i++;
		}
	}


}
