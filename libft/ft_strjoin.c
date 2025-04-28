/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abddahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 18:45:46 by abddahma          #+#    #+#             */
/*   Updated: 2024/11/15 10:26:20 by abddahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr_total;
	size_t	len_total;
	size_t	i;
	size_t	x;

	x = 0;
	i = 0;
	if (!s1 || !s2)
		return (NULL);
	len_total = ft_strlen(s1) + ft_strlen(s2);
	ptr_total = malloc (sizeof(char) * (len_total + 1));
	if (!ptr_total)
		return (NULL);
	while (s1 && s1[i])
	{
		ptr_total[i] = s1[i];
		i++;
	}
	while (s2 && s2[x])
		ptr_total[i++] = s2[x++];
	ptr_total[i] = '\0';
	return (ptr_total);
}
