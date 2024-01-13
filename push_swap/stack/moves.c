/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychaaibi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 14:31:02 by ychaaibi          #+#    #+#             */
/*   Updated: 2021/12/20 09:05:16 by ychaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	stack_get_index(int *arr, int size, int val)
{
	int	i;

	i = -1;
	while (++i < size)
		if (arr[i] == val)
			return (i);
	return (-1);
}

int	moves_to_val(t_stack *stack, int val)
{
	if (val > stack->size / 2)
		return (val - stack->size);
	return (val);
}

int	least_moves_in_group(t_stack *stack, int group_current, int group_size)
{
	int	i;
	int	least_moves;

	i = 0;
	least_moves = INT_MAX;
	while (i < stack->size)
	{
		if (stack->nodes[stack->size - i - 1]->val <= group_size * group_current
			&& !stack->nodes[stack->size - i - 1]->keep)
		{
			if (abs(moves_to_val(stack, i)) < abs(least_moves))
			{
				least_moves = moves_to_val(stack, i);
				if (!least_moves)
					return (least_moves);
			}
		}
		i++;
	}
	return (least_moves);
}
