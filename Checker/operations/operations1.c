/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychaaibi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 14:07:54 by ychaaibi          #+#    #+#             */
/*   Updated: 2021/12/19 17:40:02 by ychaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	stack_push_for(t_box *box, char for_stack)
{
	if (for_stack == 'a')
		stack_push(box->a, stack_pop(box->b));
	else
		stack_push(box->b, stack_pop(box->a));
}

void	stack_rotate_for(t_box *box, char for_stack)
{
	if (for_stack == 'a')
		stack_rotate(box->a);
	else if (for_stack == 'b')
		stack_rotate(box->b);
	else
	{
		stack_rotate(box->a);
		stack_rotate(box->b);
	}
}

void	stack_reverse_rotate_for(t_box *box, char for_stack)
{
	if (for_stack == 'a')
		stack_reverse_rotate(box->a);
	else if (for_stack == 'b')
		stack_reverse_rotate(box->b);
	else
	{
		stack_reverse_rotate(box->a);
		stack_reverse_rotate(box->b);
	}
}

void	stack_swap_for(t_box *box, char for_stack)
{
	if (for_stack == 'a')
		stack_swap(box->a);
	else if (for_stack == 'b')
		stack_swap(box->b);
	else
	{
		stack_swap(box->a);
		stack_swap(box->a);
	}
}
