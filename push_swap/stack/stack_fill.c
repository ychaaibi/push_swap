/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychaaibi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 14:34:27 by ychaaibi          #+#    #+#             */
/*   Updated: 2021/12/20 08:45:35 by ychaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	index_min(t_stack *stack)
{
	int	index;
	int	i;

	i = 0;
	index = 0;
	while (i < stack->size)
	{
		if (stack->nodes[i]->val < stack->nodes[index]->val)
			index = i;
		i++;
	}
	return (stack->size - index - 1);
}

void	stack_fill(t_stack *stack, char	**vals, int size)
{
	int	i;

	i = size - 1;
	while (i >= 0)
		stack_push(stack, node_init(ft_atoi(vals[i--])));
}

void	stack_indexing(t_stack *stack)
{
	int	*sorted;
	int	i;

	sorted = values(stack->nodes, stack->size);
	sort(sorted, stack->size);
	i = -1;
	while (++i < stack->size)
		stack->nodes[i]->val = stack_get_index(sorted,
				stack->size, stack->nodes[i]->val);
	free(sorted);
}
