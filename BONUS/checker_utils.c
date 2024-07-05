/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 14:14:34 by mbabayan          #+#    #+#             */
/*   Updated: 2024/07/05 14:53:03 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	count_int_array(int *array)
{
	int	index;

	index = 0;
	while (array[index] != 0 && array[index + 1] != 0)
		index++;
	return (index);
}

void	checker_push(t_list **stack_a, t_list **stack_b, char *move)
{
	if (check_move(move, "pa\n"))
		push_a(stack_a, stack_b, 0);
	if (check_move(move, "pb\n"))
		push_b(stack_a, stack_b, 0);
}

void	checker_swap(t_list **stack_a, t_list **stack_b, char *move)
{
	if (check_move(move, "sa\n"))
		swap_a(*stack_a, 0);
	if (check_move(move, "sb\n"))
		swap_b(*stack_b, 0);
}

void	checker_rotate(t_list **stack_a, t_list **stack_b, char *move)
{
	if (check_move(move, "ra\n"))
		rotate_a(stack_a, 0);
	if (check_move(move, "rb\n"))
		rotate_b(stack_b, 0);
	if (check_move(move, "rr\n"))
		rotate_ab(stack_a, stack_b, 0);
}

void	checker_rev_rotate(t_list **stack_a, t_list **stack_b, char *move)
{
	if (check_move(move, "rra\n"))
		reverse_rotate_a(stack_a, 0);
	if (check_move(move, "rrb\n"))
		reverse_rotate_b(stack_b, 0);
	if (check_move(move, "rrr\n"))
		reverse_rotate_ab(stack_a, stack_b, 0);
}
