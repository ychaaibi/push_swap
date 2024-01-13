/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychaaibi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 14:28:56 by ychaaibi          #+#    #+#             */
/*   Updated: 2021/12/19 15:01:40 by ychaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				arr[i] ^= arr[j];
				arr[j] ^= arr[i];
				arr[i] ^= arr[j];
			}
			j++;
		}
		i++;
	}
}

int	*values(t_node **nodes, int size)
{
	int	i;
	int	*dup;

	dup = (int *)malloc(sizeof(int) * size);
	if (!dup)
		exit(0);
	i = -1;
	while (++i < size)
		dup[i] = nodes[i]->val;
	return (dup);
}
