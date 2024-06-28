/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 11:52:50 by mbabayan          #+#    #+#             */
/*   Updated: 2024/06/22 14:43:02 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void swap(t_list *stack)
{
	int temporary;

	temporary = stack->content;
	stack->content = stack->next->content;
	stack->next->content = temporary;
}

void swap_a(t_list *stack_a, int flag)
{
	if (!stack_a || !stack_a->next)
		return ;
	swap(stack_a);
	if (flag)
		ft_printf("sa\n");
}

void swap_b(t_list *stack_b, int flag)
{
	if (!stack_b || !stack_b->next)
		return ;
	swap(stack_b);
	if (flag)
		ft_printf("sb\n");
}

void swap_ab(t_list *stack_a, t_list *stack_b, int flag)
{
	if (stack_a && stack_a->next)
		swap_a(stack_a, 0);
	if (stack_b && stack_b->next)
		swap_b(stack_b, 0);
	if (flag)
		ft_printf("ss\n");
}
