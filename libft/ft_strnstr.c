/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abddahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 20:46:35 by abddahma          #+#    #+#             */
/*   Updated: 2024/11/14 14:43:24 by abddahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	x;
	char	*pt_big;
	char	*pt_little;

	pt_little = (char *)little;
	pt_big = (char *)big;
	x = 0;
	i = 0;
	if (!pt_big && !len)
		return (NULL);
	if (pt_little[0] == '\0')
		return (pt_big);
	while (pt_big[i] && pt_little[x] && i < len)
	{
		x = 0;
		while ((pt_big[i + x] == pt_little[x]) && pt_little[x] && i + x < len)
			x++;
		if (pt_little[x] == '\0')
			return (pt_big + i);
		i++;
	}
	return (NULL);
}
