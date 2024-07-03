/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 16:03:56 by mbabayan          #+#    #+#             */
/*   Updated: 2024/07/02 10:28:15 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cef	*init_best(t_list **stack_a, t_list **stack_b)
{
	t_cef *best;
	best->source = *stack_a;
	best->destination = *stack_b;
	best->cost = 0;
	best->flag = 1;
	return (best);
}

t_cef	*find_cheapest(int temp, t_cef *best,
	t_list **stack_a, t_list **stack_b)
{
	if (temp < best->cost)
	{
		best->cost = temp;
		best->flag = 2;	
	}
	temp = best->source->index + (ft_lstsize(*stack_b) - best->destination->index);
	if (temp < best->cost)
	{
		best->cost = temp;
		best->flag = best->flag * 3;
	}
	else 
		best->flag = best->flag * 4;
	if (temp < best->cost)
		best->cost = temp;
	if (temp <  best->cost)
		best->flag = best->flag * 4;
	else 
		best->flag = best->flag * 5;
	if (temp < best->cost)
		best->cost = temp;
	return (best);
}

int	compare(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}
