/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 03:57:11 by mbabayan          #+#    #+#             */
/*   Updated: 2024/07/02 10:27:09 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "LIBFT/libft.h"
# include <stdio.h>
# include "PRINTF/ft_printf.h"
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_input
{
	int		index;
	int		total_values;
	char	*value_string;
	int		*array;
	char	**split_values;
}	t_input;
// cef = cost effective move
typedef struct s_cef
{
	t_list	*source;
	t_list	*destination;
	int		cost;
	int		flag;
}	t_cef;

/*
 * Input Parsing
*/
t_input	process_input(int argc, char **argv);
int		check_space(char *str);
int		count_values(char **split_values);
int		check_digit(char *str);
char	**free_darray(char **split_values);
int		*parse_array(char **split_values, int total_values);
int		add_to_array(int *array, char **split_values, int index);
void	exiting(void *str, char **split, char *error_m);
long	ft_atoi(const char *sp_inp_i, int *intarr, char **sp_inp);
/*
 * Stack Operations
*/
void	push_a(t_list **stack_a, t_list **stack_b, int flag);
void	push_b(t_list **stack_a, t_list **stack_b, int flag);
void	swap_a(t_list *stack_a, int flag);
void	swap_b(t_list *stack_b, int flag);
void	swap_ab(t_list *stack_a, t_list *stack_b, int flag);
void	rotate_a(t_list **stack_a, int flag);
void	rotate_b(t_list **stack_b, int flag);
void	rotate_ab(t_list **stack_a, t_list **stack_b, int flag);
void	reverse_rotate_a(t_list **stack_a, int flag);
void	reverse_rotate_b(t_list **stack_b, int flag);
void	reverse_rotate_ab(t_list **stack_a, t_list **stack_b, int flag);
/*
 * Stack Utils
*/
void	init_stack(t_list **stack, int size, int *array);
void	set_indexs(t_list *stack);
t_list	*find_node(t_list *stack, int number);
int		check_if_sorted(t_list *stack);
t_list	*get_min_node(t_list *stack);
t_list	*get_max_node(t_list *stack);
/*
 * Sort Utils
*/
void	sort(t_list **stack_a, t_list **stack_b);
t_cef	init_best(t_list **stack_a, t_list **stack_b);
int		compare(int a, int b);
t_cef	*find_cheapest(int temp, t_cef *best,
			t_list **stack_a, t_list **stack_b);
void	rot_stacks_top(t_cef best, t_list **s_a, t_list **s_b);
void	rot_stacks_down(t_cef best, t_list **s_a, t_list **s_b);
void	rot_a_revrot_b(t_cef best, t_list **s_a, t_list **s_b);
void	rot_b_revrot_a(t_cef best, t_list **s_a, t_list **s_b);
void	push_all_to_a(t_list **s_a, t_list **s_b);

#endif
