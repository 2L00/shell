/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abddahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 11:23:49 by abddahma          #+#    #+#             */
/*   Updated: 2024/10/30 16:10:46 by abddahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr_s;
	unsigned char		ptr_c;
	size_t				i;

	i = 0;
	ptr_c = (unsigned char)c;
	ptr_s = (const unsigned char *)s;
	while (i < n)
	{
		if (ptr_s[i] == ptr_c)
			return ((void *)(ptr_s + i));
		i++;
	}
	return (NULL);
}
