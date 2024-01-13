/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychaaibi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 14:35:31 by ychaaibi          #+#    #+#             */
/*   Updated: 2022/01/06 18:56:07 by ychaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	put_moves(t_stack *stack, int value)
{
	int	i;
	int	moves;
	int	moves_target;

	moves_target = INT_MAX;
	if (stack->size <= 1)
		return (0);
	if ((stack->nodes[0]->val > stack->nodes[stack->size - 1]->val
			&& (value < stack->nodes[stack->size - 1]->val
				|| value > stack->nodes[0]->val))
		|| (value > stack->nodes[0]->val
			&& value < stack->nodes[stack->size - 1]->val))
		return (0);
	i = stack->size - 2;
	while (i >= 0)
	{
		if (is_valid_place(stack, value, i))
		{
			moves = moves_to_val(stack, stack->size - i - 1);
			if (abs(moves) < abs(moves_target))
				moves_target = moves;
		}
		i--;
	}
	return (moves_target);
}

void	find_closest_to_move(t_box *box, int *rotation)
{
	int	moves[3];
	int	moves_target;
	int	i;

	moves_target = INT_MAX;
	i = 0;
	while (i < box->b->size)
	{
		moves[0] = moves_to_val(box->b, i);
		moves[1] = put_moves(box->a, box->b->nodes[box->b->size - i - 1]->val);
		moves[2] = abs(moves[0]) + abs(moves[1]);
		if (moves[1] > 0 && moves[0] > 0)
			moves[2] -= min(moves[0], moves[1]);
		if (moves[1] < 0 && moves[0] < 0)
			moves[2] += max(moves[0], moves[1]);
		if (moves[2] < moves_target)
		{
			moves_target = moves[2];
			rotation[0] = moves[0];
			rotation[1] = moves[1];
		}
		i++;
	}
}			

void	move_b_to_a(t_box *box)
{
	int	rotation[2];
	int	i;

	i = 0;
	while (box->b->size)
	{
		find_closest_to_move(box, rotation);
		stack_rotate_n(box, rotation[1], rotation[0]);
		stack_push_for(box, 'a');
	}
}

void	better_swap(t_box *box)
{
	int	length_sorted_circle;

	stack_swap(box->a);
	length_sorted_circle = stack_longest_sorted_circle(box->a, 0);
	if (length_sorted_circle > box->sorted_circle_size)
	{
		box->sorted_circle_size = length_sorted_circle;
		stack_longest_sorted_circle(box->a, 1);
		ft_putstr("sa\n");
	}
	else
		stack_swap(box->a);
}

void	stack_sort(t_box *box)
{
	int	group;
	int	moves;

	group = 1;
	while (box->a->size > box->sorted_circle_size)
	{
		moves = least_moves_in_group(box->a, group, box->group_size);
		if (moves == INT_MAX)
		{
			group++;
			continue ;
		}
		better_swap(box);
		if (box->a && !box->a->nodes[box->a->size - 1]->keep && moves == 0)
			stack_push_for(box, 'b');
		else
			stack_rotate_n(box, min(1, max(-1, moves)), 0);
	}
	move_b_to_a(box);
	stack_rotate_n(box, moves_to_val(box->a, index_min(box->a)), 0);
}
