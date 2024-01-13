/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychaaibi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 14:06:52 by ychaaibi          #+#    #+#             */
/*   Updated: 2021/12/19 17:53:50 by ychaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_putstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

int	max(int n1, int n2)
{
	if (n1 > n2)
		return (n1);
	return (n2);
}

int	min(int n1, int n2)
{
	if (n1 < n2)
		return (n1);
	return (n2);
}

int	abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}
