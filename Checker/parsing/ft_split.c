/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychaaibi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 08:34:23 by ychaaibi          #+#    #+#             */
/*   Updated: 2021/12/19 16:52:50 by ychaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	freememory(char **mem)
{
	int	i;

	i = 0;
	while (mem[i])
		free(mem[i++]);
	free(mem);
}

int	wordlen(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

int	ft_wordcount(char *s, char c)
{
	int	count;

	if (!s)
		return (0);
	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

char	**fill(char **split, char *s, char c)
{
	int	k;
	int	i;
	int	len;

	k = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			len = wordlen(s + i, c);
			split[k] = ft_substr(s, i, len);
			if (!split[k++])
			{
				freememory(split);
				return (NULL);
			}
			i += len;
		}
	}
	split[k] = 0;
	return (split);
}

char	**ft_split(char *s, char c, int *len)
{
	char	**split;

	if (!s)
		return (NULL);
	*len = ft_wordcount(s, c);
	split = (char **)malloc(sizeof(char *) * ((*len) + 1));
	if (!split)
		return (NULL);
	return (fill(split, s, c));
}
