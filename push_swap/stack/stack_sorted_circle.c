/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorted_circle.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychaaibi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 14:37:01 by ychaaibi          #+#    #+#             */
/*   Updated: 2021/12/20 08:44:19 by ychaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	stack_sorted_circle(t_stack *stack, int end, int keep)
{
	int	i;
	int	before;
	int	count;

	before = stack->nodes[end]->val;
	if (keep)
		stack->nodes[end]->keep = 1;
	i = end - 1;
	if (i == -1)
		i = stack->size - 1;
	count = 1;
	while (i != end)
	{
		if (keep)
			stack->nodes[i]->keep = 0;
		if (stack->nodes[i]->val > before && count++)
		{
			before = stack->nodes[i]->val;
			if (keep)
				stack->nodes[i]->keep = 1;
		}
		if (--i == -1)
			i = stack->size - 1;
	}
	return (count);
}

int	stack_longest_sorted_circle(t_stack *stack, int keep)
{
	int	i;
	int	longest_sorted_circle_length;
	int	sorted_circle_length;
	int	longest_sorted_circle_index;

	longest_sorted_circle_length = INT_MIN;
	i = stack->size - 1;
	while (i >= 0)
	{
		sorted_circle_length = stack_sorted_circle(stack, i, 0);
		if (sorted_circle_length > longest_sorted_circle_length)
		{
			longest_sorted_circle_length = sorted_circle_length;
			longest_sorted_circle_index = i;
		}
		i--;
	}
	if (keep)
		stack_sorted_circle(stack, longest_sorted_circle_index, 1);
	return (longest_sorted_circle_length);
}
