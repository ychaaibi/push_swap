/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychaaibi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 14:07:54 by ychaaibi          #+#    #+#             */
/*   Updated: 2021/12/19 18:13:08 by ychaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	stack_push_for(t_box *box, char for_stack)
{
	if (for_stack == 'a')
	{
		stack_push(box->a, stack_pop(box->b));
		ft_putstr("pa\n");
	}
	else
	{
		stack_push(box->b, stack_pop(box->a));
		ft_putstr("pb\n");
	}
}

void	stack_rotate_for(t_box *box, char for_stack)
{
	if (for_stack == 'a')
	{
		stack_rotate(box->a);
		ft_putstr("ra\n");
	}
	else if (for_stack == 'b')
	{
		stack_rotate(box->b);
		ft_putstr("rb\n");
	}
	else
	{
		stack_rotate(box->a);
		stack_rotate(box->b);
		ft_putstr("rr\n");
	}
}

void	stack_reverse_rotate_for(t_box *box, char for_stack)
{
	if (for_stack == 'a')
	{
		stack_reverse_rotate(box->a);
		ft_putstr("rra\n");
	}
	else if (for_stack == 'b')
	{
		stack_reverse_rotate(box->b);
		ft_putstr("rrb\n");
	}
	else
	{
		stack_reverse_rotate(box->a);
		stack_reverse_rotate(box->b);
		ft_putstr("rrr\n");
	}
}

void	stack_swap_for(t_box *box, char for_stack)
{
	if (for_stack == 'a')
	{
		stack_swap(box->a);
		ft_putstr("sa\n");
	}
	else if (for_stack == 'b')
	{
		stack_swap(box->b);
		ft_putstr("sb\n");
	}
	else
	{
		stack_swap(box->a);
		stack_swap(box->a);
		ft_putstr("ss\n");
	}
}

void	stack_rotate_n(t_box *box, int a, int b)
{
	while (a > 0 && b > 0)
	{
		a--;
		b--;
		stack_rotate_for(box, '2');
	}
	while (a < 0 && b < 0)
	{
		a++;
		b++;
		stack_reverse_rotate_for(box, '2');
	}
	while (a > 0 && a--)
		stack_rotate_for(box, 'a');
	while (a < 0 && a++)
		stack_reverse_rotate_for(box, 'a');
	while (b > 0 && b--)
		stack_rotate_for(box, 'b');
	while (b < 0 && b++)
		stack_reverse_rotate_for(box, 'b');
}
