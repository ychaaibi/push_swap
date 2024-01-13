/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_instruction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychaaibi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 13:43:19 by ychaaibi          #+#    #+#             */
/*   Updated: 2021/12/19 17:36:36 by ychaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int	ft_is_instruction(char *s)
{
	return (!(ft_strcmp(s, "sa") && ft_strcmp(s, "sb") && ft_strcmp(s, "ss")
			&& ft_strcmp(s, "ra") && ft_strcmp(s, "rb") && ft_strcmp(s, "rr")
			&& ft_strcmp(s, "rra") && ft_strcmp(s, "rrb") && ft_strcmp(s, "rrr")
			&& ft_strcmp(s, "pa") && ft_strcmp(s, "pb")));
}
