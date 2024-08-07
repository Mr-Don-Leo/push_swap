/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_rules.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 11:53:19 by mbabayan          #+#    #+#             */
/*   Updated: 2024/07/04 11:53:24 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_rotate(t_list **stack)
{
	t_list	*temp;
	t_list	*temp2;

	if (!stack || !(*stack))
		return ;
	temp2 = (*stack);
	temp = ft_lstlast(*stack);
	ft_lstadd_front(stack, temp);
	while (temp2->next != temp)
		temp2 = temp2->next;
	temp2->next = NULL;
}

void	reverse_rotate_a(t_list **stack_a, int flag)
{
	if (!(*stack_a) || (*stack_a)->next == NULL)
		return ;
	reverse_rotate(stack_a);
	if (flag)
		ft_printf("rra\n");
}

void	reverse_rotate_b(t_list **stack_b, int flag)
{
	if ((*stack_b)->next == NULL)
		return ;
	reverse_rotate(stack_b);
	if (flag)
		ft_printf("rrb\n");
}

void	reverse_rotate_ab(t_list **stack_a, t_list **stack_b, int flag)
{
	if ((*stack_a)->next != NULL)
		reverse_rotate_a(stack_a, 0);
	if ((*stack_b)->next != NULL)
		reverse_rotate_b(stack_b, 0);
	if (flag)
		ft_printf("rrr\n");
}
