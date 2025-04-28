/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abddahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:37:30 by abddahma          #+#    #+#             */
/*   Updated: 2024/11/14 12:17:07 by abddahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmb, size_t size)
{
	void	*tmp;

	tmp = malloc(nmb * size);
	if (!tmp)
		return (NULL);
	ft_bzero(tmp, nmb * size);
	return (tmp);
}
