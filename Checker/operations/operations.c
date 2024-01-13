/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychaaibi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 14:31:51 by ychaaibi          #+#    #+#             */
/*   Updated: 2021/12/19 17:26:43 by ychaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

t_node	*stack_pop(t_stack *stack)
{
	if (!stack->size)
		return (NULL);
	stack->size--;
	return (stack->nodes[stack->size]);
}

void	stack_push(t_stack *stack, t_node *node)
{
	stack->nodes[stack->size++] = node;
}

void	stack_rotate(t_stack *stack)
{
	t_node	*tmp;
	int		i;

	if (stack->size <= 1)
		return ;
	tmp = stack->nodes[stack->size - 1];
	i = stack->size - 1;
	while (i > 0)
	{
		stack->nodes[i] = stack->nodes[i - 1];
		i--;
	}
	stack->nodes[0] = tmp;
}

void	stack_reverse_rotate(t_stack *stack)
{
	t_node	*tmp;
	int		i;

	if (stack->size <= 1)
		return ;
	tmp = stack->nodes[0];
	i = 0;
	while (i < stack->size - 1)
	{
		stack->nodes[i] = stack->nodes[i + 1];
		i++;
	}
	stack->nodes[i] = tmp;
}

void	stack_swap(t_stack *stack)
{
	t_node	*node;

	if (stack->size <= 1)
		return ;
	node = stack->nodes[stack->size - 1];
	stack->nodes[stack->size - 1] = stack->nodes[stack->size - 2];
	stack->nodes[stack->size - 2] = node;
}
