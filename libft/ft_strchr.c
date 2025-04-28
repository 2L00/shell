/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abddahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 22:41:36 by abddahma          #+#    #+#             */
/*   Updated: 2024/11/14 13:54:27 by abddahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	ptr_c;

	i = 0;
	ptr_c = (char)c;
	if (!s && ptr_c)
		return (NULL);
	while (s[i])
	{
		if (s[i] == ptr_c)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == ptr_c)
		return ((char *) &s[i]);
	return (NULL);
}
