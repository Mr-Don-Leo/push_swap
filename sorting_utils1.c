/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:14:17 by mbabayan          #+#    #+#             */
/*   Updated: 2024/07/01 20:39:53 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cef cheapest(t_list *temp_node, t_list **stack_a, t_list **stack_b)
{
	t_cef *best;
	int				temp;
	int				a_flag;
	best->source = temp_node;
	best->destination = find_node(*stack_b, temp_node->content);
	best->cost = compare(best->destination->index, best->source->index);
	temp = compare(ft_lstsize(*stack_a) - best->source->index,
			ft_lstsize(*stack_b) - best->destination->index);
	best->flag = 1;
	return (find_cheapest(temp, best, stack_a, stack_b));	
}

t_cef	find_cost_effective_move(t_list **stack_a, t_list **stack_b)
{
	t_cef best;
	t_cef comparison;
	t_list *temporary;

	if (!(*stack_a) || !(*stack_b))
	{
		init_best(&best, stack_a, stack_b);
		return (best);	
	}
	temporary = *stack_a;
	best = cheapest(temporary, stack_a, stack_b);
	temporary = temporary->next;
	while (temporary)
	{
		comparison = cheapest(temporary, stack_a, stack_b);
		if (comparison.cost < best.cost)
		{
			best.cost =  comparison.cost;
			best.source = comparison.source;
			best.destination = comparison.destination;
			best.flag = comparison.flag;
		}
		temporary = temporary->next;
	}
	return (best);
}

void	move_effectively(t_list **stack_a, t_list **stack_b)
{
	t_cef move;

	move = find_cost_effective_move(stack_a, stack_b);
	if (move.flag == 1)
		// rot both up
	if (move.flag == 2)
		// rot both down
	if (move.flag == 3)
		// rota, rev rot b
	if (move.flag == 4)
		// rev rot a, rob b
	return ;
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	while (ft_lstsize(*stack_a) > 3)
	{
		move_effectively(stack_a, stack_b);
		push_b(stack_a, stack_b, 1);
		set_indexs(*stack_a);
		set_indexs(*stack_b);
	}
}