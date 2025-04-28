/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abddahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 13:51:33 by abddahma          #+#    #+#             */
/*   Updated: 2024/10/27 15:56:45 by abddahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr_s;
	size_t	i;

	i = 0;
	ptr_s = malloc (sizeof(char) * ft_strlen(s) + 1);
	if (!ptr_s)
		return (NULL);
	while (s[i])
	{
		ptr_s[i] = s[i];
		i++;
	}
	ptr_s[i] = '\0';
	return (ptr_s);
}
