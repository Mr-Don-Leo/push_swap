/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 11:53:35 by mbabayan          #+#    #+#             */
/*   Updated: 2024/06/28 03:48:38 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void push(t_list **from_stack, t_list **to_stack)
{
	t_list *new;
	new = (*from_stack);
	if (!new)
		return ;
	(*from_stack) = (*from_stack)->next;
	new->next = (*to_stack);
	(*to_stack) = new;
}

void push_a(t_list **stack_a, t_list **stack_b, int flag)
{
	if (!stack_b)
		return ;
	push(stack_b, stack_a);
	if (flag)
		ft_printf("pa\n"); 
}

void push_b(t_list **stack_a, t_list **stack_b, int flag)
{
	if (!stack_b)
		return ;
	push(stack_a, stack_b);
	if (flag)
		ft_printf("pb\n"); 
}
