/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abddahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 08:30:12 by abddahma          #+#    #+#             */
/*   Updated: 2025/04/19 14:12:19 by abddahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main()
{
	char **av;
	char **split;
	char *read_l;
//	if (ac < 2)
//		return 0;
	int i = 1;
	while (1)
	{
		//split = ft_split(av[i], ' ');

	//	if (av[i] == NULL)
//			return 0;
		read_l = readline(av[i]);
		if (read_l == NULL)
			return 0;
		printf("%s\n", read_l);
		i++;
	}

	i = 0;
//	while (split[i])
//	{
//		printf("%s\n", split[i]);
//		i++;
//	}
}
