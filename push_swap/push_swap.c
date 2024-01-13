/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychaaibi <ychaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 14:29:33 by ychaaibi          #+#    #+#             */
/*   Updated: 2022/01/06 18:05:02 by ychaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_box	*box;

	if (ac == 1)
		return (0);
	box = ft_parse(ac - 1, &av[1]);
	stack_sort(box);
	return (0);
}
