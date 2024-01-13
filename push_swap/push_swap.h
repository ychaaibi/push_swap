/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychaaibi <ychaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 14:33:21 by ychaaibi          #+#    #+#             */
/*   Updated: 2022/01/06 18:01:23 by ychaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdio.h>

////////////////////////////Init//////////////////////////

typedef struct s_node
{
	int	val;
	int	keep;
}		t_node;

typedef struct s_stack
{
	t_node	**nodes;
	int		size;
}		t_stack;

typedef struct s_box
{
	t_stack	*a;
	t_stack	*b;
	int		sorted_circle_size;
	int		group_count;
	int		group_size;
}		t_box;

t_stack	*stack_init(int size);
t_node	*node_init(int val);
t_box	*box_init(int size, char **nodes);

///////////////////////////Free////////////////////////

void	free_stack(t_stack *stack);
void	free_box(t_box *box);

///////////////////////////Funcs///////////////////////

void	sort(int *arr, int size);
void	ft_putstr(char *s);
int		*values(t_node **nodes, int size);
int		min(int n1, int n2);
int		max(int n1, int n2);
int		abs(int n);

//////////////////////////Parsing///////////////////////

void	ft_error(void);
int		ft_isnumber(char *s);
int		ft_atoi(char *s);
char	**ft_split(char *s, char set, int *len);
char	*ft_substr(char *s, unsigned int start, size_t size);
t_box	*ft_parse(int ac, char **av);
void	stack_fill(t_stack *stack, char	**vals, int size);
void	stack_indexing(t_stack *stack);

//////////////////////////Operations////////////////////

t_node	*stack_pop(t_stack *stack);
void	stack_push(t_stack *stack, t_node *node);
void	stack_rotate(t_stack *stack);
void	stack_reverse_rotate(t_stack *stack);
void	stack_swap(t_stack *stack);

void	stack_push_for(t_box *box, char for_stack);
void	stack_rotate_for(t_box *box, char for_stack);
void	stack_reverse_rotate_for(t_box *box, char for_stack);
void	stack_swap_for(t_box *box, char for_stack);
void	stack_rotate_n(t_box *box, int a, int b);

////////////////////////Moves////////////////////////

int		stack_get_index(int	*arr, int size, int val);
int		least_moves_in_group(t_stack *stack, int group_current, int group_size);
int		moves_to_val(t_stack *stack, int val);

/////////////////////Stack Sort////////////////////

int		stack_sorted_circle(t_stack *stack, int end, int keep);
int		stack_longest_sorted_circle(t_stack *stack, int keep);

int		index_min(t_stack *stack);
int		put_moves(t_stack *stack, int val);
void	find_closest_to_move(t_box *box, int *rotation);
void	move_b_to_a(t_box *box);
void	better_swap(t_box *box);
int		is_valid_place(t_stack *stack, int value, int i);
void	stack_sort(t_box *box);

#endif
