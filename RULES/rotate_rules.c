/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_rules.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 11:53:11 by mbabayan          #+#    #+#             */
/*   Updated: 2024/06/28 01:35:12 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void rotate(t_list **stack)
{
	t_list *temporary;
	t_list *last;

	temporary = (*stack);
	(*stack) = (*stack)->next;
	last = ft_lstlast((*stack));
	ft_lstadd_back(&last, temporary);
	temporary->next = NULL;
}

void rotate_a(t_list **stack_a, int flag)
{
	if (!(*stack_a) || ft_lstsize((*stack_a)) < 2)
		return ;
	rotate(stack_a);
	if (flag)
		ft_printf("ra\n");
}

void rotate_b(t_list **stack_b, int flag)
{
	if (!(*stack_b) || ft_lstsize((*stack_b)) < 2)
		return ;
	rotate(stack_b);
	if (flag)
		ft_printf("rb\n");
}

void rotate_ab(t_list **stack_a, t_list **stack_b, int flag)
{
	if ((*stack_a) && ft_lstsize((*stack_a)) > 1)
		rotate_a(stack_a, 0);
	if ((*stack_b) && ft_lstsize((*stack_b)) > 1)
		rotate_b(stack_b, 0);
	if (flag)
		ft_printf("rr\n");
}
