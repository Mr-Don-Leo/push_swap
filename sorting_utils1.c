/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:14:17 by mbabayan          #+#    #+#             */
/*   Updated: 2024/07/05 01:47:10 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cef	replace(t_cef cheapest, t_cef compare)
{
	cheapest.cost = compare.cost;
	cheapest.flag = compare.flag;
	cheapest.src = compare.src;
	cheapest.dest = compare.dest;
	return (cheapest);
}

t_cef	cheapest(t_list *node, t_list **stack1, t_list **stack2)
{
	t_cef			info;
	unsigned int	temp;

	info.src = node;
	info.dest = find_node(stack2, node->content);
	info.cost = compare(info.src->i, info.dest->i);
	info.flag = 1;
	temp = compare(ft_lstsize(*stack2) - info.dest->i, ft_lstsize(*stack1)
			- info.src->i);
	if (temp < info.cost)
		assign_cost_flag(temp, &info, 2);
	temp = info.src->i + (ft_lstsize(*stack2) - info.dest->i);
	if (temp < info.cost)
		assign_cost_flag(temp, &info, 3);
	temp = info.dest->i + (ft_lstsize(*stack1) - info.src->i);
	if (temp < info.cost)
		assign_cost_flag(temp, &info, 4);
	return (info);
}

t_cef	effective_move(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;
	t_cef	best;
	t_cef	compare;

	if (!stack_a || !(*stack_a) || !stack_b || !(*stack_b))
	{
		best.cost = 0;
		best.src = (*stack_a);
		best.dest = (*stack_b);
		best.flag = 1;
		return (best);
	}
	temp = (*stack_a);
	best = cheapest(temp, stack_a, stack_b);
	temp = temp->next;
	while (temp)
	{
		compare = cheapest(temp, stack_a, stack_b);
		if (compare.cost < best.cost)
			best = replace(best, compare);
		temp = temp->next;
	}
	return (best);
}

void	change_stack_order(t_cef best, t_list **stack_a, t_list **stack_b)
{
	if (best.flag == 1)
		rot_stacks_top(best, stack_a, stack_b);
	else if (best.flag == 2)
		rot_stacks_down(best, stack_a, stack_b);
	else if (best.flag == 3)
		rot_a_revrot_b(best, stack_a, stack_b);
	else if (best.flag == 4)
		rot_b_revrot_a(best, stack_a, stack_b);
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*biggest;

	while (ft_lstsize(*stack_a) > 3)
	{
		change_stack_order(effective_move(stack_a, stack_b), stack_a, stack_b);
		push_b(stack_a, stack_b, 1);
		set_indexs(*stack_a);
		set_indexs(*stack_b);
	}
	if (ft_lstsize(*stack_a) != 3)
		return ;
	biggest = get_max_node(*stack_a);
	if ((*stack_a)->content == biggest->content)
		rotate_a(stack_a, 1);
	else if ((*stack_a)->next->content == biggest->content)
		reverse_rotate_a(stack_a, 1);
	if (!check_if_sorted(*stack_a))
		swap_a(*stack_a, 1);
	set_indexs(*stack_a);
	push_all_to_a(stack_a, stack_b);
}
