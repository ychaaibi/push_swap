/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychaaibi <ychaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 10:11:05 by ychaaibi          #+#    #+#             */
/*   Updated: 2022/01/06 18:08:21 by ychaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check(t_stack *a, t_stack *b)
{
	if (ft_issorted_stack(a) && ft_isempty_stack(b))
		write(1, "\033[32mOK\n", 8);
	else
		write(1, "\033[31mKO\n", 8);
}

int	main(int ac, char **av)
{
	t_box	*box;
	t_list	*instructions;

	if (ac == 1)
		return (0);
	instructions = NULL;
	box = ft_parse(ac - 1, &av[1]);
	read_instructions(&instructions);
	ft_check(instructions, box);
	check(box->a, box->b);
	return (0);
}
