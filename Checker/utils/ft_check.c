/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychaaibi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 16:34:07 by ychaaibi          #+#    #+#             */
/*   Updated: 2021/12/19 17:27:24 by ychaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	do_instruction(char *s, t_box *box)
{
	if (!ft_strcmp(s, "sa") || !ft_strcmp(s, "ss"))
		stack_swap_for(box, 'a');
	if (!ft_strcmp(s, "sb") || !ft_strcmp(s, "ss"))
		stack_swap_for(box, 'b');
	if (!ft_strcmp(s, "pa"))
		stack_push_for(box, 'a');
	if (!ft_strcmp(s, "pb"))
		stack_push_for(box, 'b');
	if (!ft_strcmp(s, "ra") || !ft_strcmp(s, "rr"))
		stack_rotate_for(box, 'a');
	if (!ft_strcmp(s, "rb") || !ft_strcmp(s, "rr"))
		stack_rotate_for(box, 'b');
	if (!ft_strcmp(s, "rra") || !ft_strcmp(s, "rrr"))
		stack_reverse_rotate_for(box, 'a');
	if (!ft_strcmp(s, "rrb") || !ft_strcmp(s, "rrr"))
		stack_reverse_rotate_for(box, 'b');
}

void	ft_check(t_list *instructions, t_box *box)
{
	while (instructions)
	{
		do_instruction(instructions->content, box);
		instructions = instructions->next;
	}
}
