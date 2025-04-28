/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abddahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:23:23 by abddahma          #+#    #+#             */
/*   Updated: 2024/10/31 22:21:50 by abddahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen(s);
	if (c == 0)
		return ((char *)s + len);
	len++;
	while (len > 0)
	{
		if (s[len - 1] == (char)c)
			return ((char *)(&s[len - 1]));
		len--;
	}
	if (s[0] == (char)c)
		return ((char *)s);
	return (NULL);
}
