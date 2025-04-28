/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abddahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:41:37 by abddahma          #+#    #+#             */
/*   Updated: 2024/10/31 14:11:34 by abddahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_all_words(const char	*s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static void	*ft_free(char **strs, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

static char	*ft_strndup(const char *s, size_t n)
{
	char	*dup;

	dup = malloc((n + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	ft_memmove(dup, s, n);
	dup[n] = '\0';
	return (dup);
}

static void	lines_norm(char **split_s, const char *s, char c)
{
	size_t			i;
	const char		*iam_now;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			iam_now = s;
			while (*s && *s != c)
				s++;
			split_s[i] = ft_strndup(iam_now, s - iam_now);
			if (!split_s[i])
				ft_free(split_s, i);
			i++;
		}
	}
	split_s[i] = NULL;
}

char	**ft_split(const char *s, char c)
{
	char	**split_s;

	if (!s)
		return (NULL);
	split_s = malloc((ft_all_words(s, c) + 1) * sizeof(char *));
	if (!split_s)
		return (NULL);
	lines_norm(split_s, s, c);
	return (split_s);
}
