/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_place.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychaaibi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 18:21:36 by ychaaibi          #+#    #+#             */
/*   Updated: 2021/12/19 18:21:54 by ychaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_valid_place(t_stack *stack, int value, int i)
{
	return ((stack->nodes[i + 1]->val > stack->nodes[i]->val
			&& (value < stack->nodes[i]->val
				|| value > stack->nodes[i + 1]->val))
		|| (value > stack->nodes[i + 1]->val
			&& value < stack->nodes[i]->val));
}
