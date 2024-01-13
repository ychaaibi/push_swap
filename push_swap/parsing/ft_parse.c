/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychaaibi <ychaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 11:40:11 by ychaaibi          #+#    #+#             */
/*   Updated: 2022/01/06 18:01:14 by ychaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

int	ft_isnumber(char *s)
{
	if (*s == '+' || *s == '-')
		s++;
	while (*s)
	{
		if (!(*s >= '0' && *s <= '9'))
			return (0);
		s++;
	}
	return (1);
}

t_box	*ft_parse(int ac, char **av)
{
	int		i;
	int		j;

	i = 0;
	if (ac == 1)
		av = ft_split(av[0], ' ', &ac);
	if (!av)
		exit(0);
	while (i < ac)
	{
		j = i + 1;
		if (!ft_isnumber(av[i]))
			ft_error();
		while (j < ac)
			if (ft_atoi(av[i]) == ft_atoi(av[j++]))
				ft_error();
		i++;
	}
	return (box_init(ac, av));
}
