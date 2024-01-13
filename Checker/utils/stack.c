/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychaaibi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 16:21:16 by ychaaibi          #+#    #+#             */
/*   Updated: 2021/12/19 17:38:01 by ychaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int	ft_issorted_stack(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->nodes[i]->val < stack->nodes[i + 1]->val)
			return (0);
		i++;
	}
	return (1);
}

int	ft_isempty_stack(t_stack *stack)
{
	return (!stack->size);
}

void	stack_fill(t_stack *stack, char	**vals, int size)
{
	int	i;

	i = size - 1;
	while (i >= 0)
		stack_push(stack, node_init(ft_atoi(vals[i--])));
}
