/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:14:17 by mbabayan          #+#    #+#             */
/*   Updated: 2024/07/02 10:27:42 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cef *cheapest(t_list *temp_node, t_list **stack_a, t_list **stack_b)
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
	t_cef *best;
	t_cef *comparison;
	t_list *temporary;

	if (!(*stack_a) || !stack_a || !stack_b || !(*stack_b))
	{
		best = init_best(stack_a, stack_b);
		return (best);	
	}

	printf("best: %d\n", best.cost);
	printf("best: %d\n", best.flag);
	printf("best: %d\n", best.source->content);
	printf("best: %d\n", best.destination->content);
	
	temporary = *stack_a;

	printf("temporary: %d\n", temporary->content);
	
	best = cheapest(temporary, stack_a, stack_b);

	printf("best: %d\n", best.cost);
	printf("best: %d\n", best.flag);
	printf("best: %d\n", best.source->content);
	printf("best: %d\n", best.destination->content);
	
	temporary = temporary->next;
	while (temporary)
	{
		comparison = cheapest(temporary, stack_a, stack_b);
		if (comparison->cost < best.cost)
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
	printf("MOVE: %d\n", move.flag);
	printf("SOURCE: %d\n", move.source->content);
	// printf("DESTINATION: %d\n", move.destination->content);
	if (move.flag == 1)
		rot_stacks_top(move, stack_a, stack_b);
	if (move.flag == 2)
		rot_stacks_down(move, stack_a, stack_b);
	if (move.flag == 3)
		rot_a_revrot_b(move, stack_a, stack_b);
	if (move.flag == 4)
		rot_b_revrot_a(move, stack_a, stack_b);
	return ;
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	t_list *biggest;

	while (ft_lstsize(*stack_a) > 3)
	{
		move_effectively(stack_a, stack_b);
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
