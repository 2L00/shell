/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abddahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 23:19:18 by abddahma          #+#    #+#             */
/*   Updated: 2024/11/07 21:23:49 by abddahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	int		res;
	char	*ptt;

	ptt = (char *)nptr;
	res = 0;
	sign = 1;
	i = 0;
	while (ptt[i] == ' ' || (ptt[i] >= 9 && ptt[i] <= 13))
		i++;
	if (ptt[i] == '-' || ptt[i] == '+')
	{
		if (ptt[i] == '-')
			sign = sign * (-1);
		i++;
	}
	while (ptt[i] <= '9' && ptt[i] >= '0')
	{
		res = res * 10 + (ptt[i] - '0');
		i++;
	}
	return (res * sign);
}
