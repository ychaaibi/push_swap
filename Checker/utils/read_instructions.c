/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychaaibi <ychaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 13:49:21 by ychaaibi          #+#    #+#             */
/*   Updated: 2022/01/06 17:58:09 by ychaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	check_instruction(char *line)
{
	if (!ft_is_instruction(line))
	{
		ft_error();
		exit(0);
	}
}

void	read_instructions(t_list **instructions)
{
	char	line[4];
	char	c;
	int		i;

	i = 0;
	while (read(0, &c, 1))
	{
		if (i >= 4)
			ft_error();
		else if (c == '\n')
		{
			line[i] = 0;
			check_instruction(line);
			ft_lstadd_back(instructions, ft_lstnew(ft_strdup(line)));
			i = 0;
		}
		else
			line[i++] = c;
	}
}
