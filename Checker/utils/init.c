/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychaaibi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 14:29:21 by ychaaibi          #+#    #+#             */
/*   Updated: 2021/12/19 17:28:11 by ychaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

t_stack	*stack_init(int size)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		exit(0);
	stack->nodes = (t_node **)malloc(size * sizeof(t_node *));
	stack->size = 0;
	if (!stack->nodes)
		exit(0);
	return (stack);
}

t_node	*node_init(int val)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		exit(0);
	node->val = val;
	node->keep = 0;
	return (node);
}

t_box	*box_init(int size, char **nodes)
{
	t_box	*box;

	box = (t_box *)malloc(sizeof(t_box));
	if (!box)
		exit(0);
	box->a = stack_init(size);
	if (!box->a)
		exit(0);
	box->b = stack_init(size);
	if (!box->b)
		exit(0);
	stack_fill(box->a, nodes, size);
	return (box);
}
