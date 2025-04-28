/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abddahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 22:01:22 by abddahma          #+#    #+#             */
/*   Updated: 2024/10/30 16:36:50 by abddahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_exist(char c, char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr_s1;
	size_t	i;
	size_t	len;

	i = 0;
	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	len = ft_strlen(s1);
	while (s1[i] && ft_exist(s1[i], (char *)set) == 1)
		i++;
	while (len > i && ft_exist(s1[len - 1], (char *)set) == 1)
		len--;
	ptr_s1 = malloc(sizeof(char) * len - i + 1);
	if (!ptr_s1)
		return (NULL);
	ft_memcpy(ptr_s1, s1 + i, len - i);
	ptr_s1[len - i] = '\0';
	return (ptr_s1);
}
