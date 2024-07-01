/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 20:05:02 by mbabayan          #+#    #+#             */
/*   Updated: 2024/07/01 20:58:05 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rot_stacks_top(t_cef best, t_list **s_a, t_list **s_b)
{
	while (best.source->index > 0 && best.destination->index > 0)
	{
		rotate_ab(s_a, s_b, 1);
		best.source->index--;
		best.destination->index--;
	}
	while (best.source->index > 0)
	{
		rotate_a(s_a, 1);
		best.source->index--;
	}
	while (best.destination->index > 0)
	{
		
		rotate_b(s_b, 1);
		best.destination->index--;
	}
}

void	rot_stacks_down(t_cef best, t_list **s_a, t_list **s_b)
{
	while ((ft_lstsize(*s_a) - best.source->index) > 0
		&& (ft_lstsize(*s_b) - best.destination->index) > 0)
	{
		reverse_rotate_ab(s_a, s_b, 1);
		best.source->index++;
		best.destination->index++;
	}
	while ((ft_lstsize(*s_a) - best.source->index) > 0)
	{
		reverse_rotate_a(s_a, 1);
		best.source->index++;
	}
	while ((ft_lstsize(*s_b) - best.destination->index) > 0)
	{
		reverse_rotate_b(s_b, 1);
		best.destination->index++;
	}
}

void rot_a_revrot_b(t_cef best, t_list **s_a, t_list **s_b)
{
	while (best.source->index > 0 && (ft_lstsize(*s_b) - best.destination->index) > 0)
	{
		rotate_a(s_a, 1);
		reverse_rotate_b(s_b, 1);
		best.source->index--;
		best.destination->index++;
	}
	while (best.source->index > 0)
	{
		rotate_a(s_a, 1);
		best.source->index--;
	}
	while ((ft_lstsize(*s_b) - best.destination->index) > 0)
	{
		reverse_rotate_b(s_b, 1);
		best.destination->index++;
	}
}

void rot_b_revrot_a(t_cef best, t_list **s_a, t_list **s_b)
{
	while ((ft_lstsize(*s_a) - best.source->index) > 0 && best.destination->index > 0)
	{
		reverse_rotate_a(s_a, 1);
		rotate_b(s_b, 1);
		best.source->index++;
		best.destination->index--;
	}
	while ((ft_lstsize(*s_a) - best.source->index) > 0)
	{
		reverse_rotate_a(s_a, 1);
		best.source->index++;
	}
	while (best.destination->index > 0)
	{
		rotate_b(s_b, 1);
		best.destination->index--;
	}
}
