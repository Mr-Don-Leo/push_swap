/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reordering.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 20:05:02 by mbabayan          #+#    #+#             */
/*   Updated: 2024/07/05 16:19:27 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rot_stacks_top(t_cef best, t_list **s_a, t_list **s_b)
{
	if (!best.src || !best.dest || !(*s_a) || !(*s_b))
		return ;
	while (best.src->i > 0 && best.dest->i > 0)
	{
		if (!(*s_a) || !(*s_b))
			break ;
		rotate_ab(s_a, s_b, 1);
		best.src->i--;
		best.dest->i--;
	}
	while (best.src->i > 0)
	{
		if (!(*s_a))
			break ;
		rotate_a(s_a, 1);
		best.src->i--;
	}
	while (best.dest->i > 0)
	{
		if (!(*s_b))
			break ;
		rotate_b(s_b, 1);
		best.dest->i--;
	}
}

void	rot_stacks_down(t_cef best, t_list **s_a, t_list **s_b)
{
	if (!best.src || !best.dest || !(*s_a) || !(*s_b))
		return ;
	while ((ft_lstsize(*s_a) - best.src->i) > 0 && (ft_lstsize(*s_b)
			- best.dest->i) > 0)
	{
		if (!(*s_a) || !(*s_b))
			break ;
		reverse_rotate_ab(s_a, s_b, 1);
		best.src->i++;
		best.dest->i++;
	}
	while ((ft_lstsize(*s_a) - best.src->i) > 0)
	{
		if (!(*s_a))
			break ;
		reverse_rotate_a(s_a, 1);
		best.src->i++;
	}
	while ((ft_lstsize(*s_b) - best.dest->i) > 0)
	{
		if (!(*s_b))
			break ;
		reverse_rotate_b(s_b, 1);
		best.dest->i++;
	}
}

void	rot_a_revrot_b(t_cef best, t_list **s_a, t_list **s_b)
{
	if (!best.src || !best.dest || !(*s_a) || !(*s_b))
		return ;
	while (best.src->i > 0)
	{
		if (!(*s_a))
			break ;
		rotate_a(s_a, 1);
		best.src->i--;
	}
	while ((ft_lstsize(*s_b) - best.dest->i) > 0)
	{
		if (!(*s_b))
			break ;
		reverse_rotate_b(s_b, 1);
		best.dest->i++;
	}
}

void	rot_b_revrot_a(t_cef best, t_list **s_a, t_list **s_b)
{
	if (!best.src || !best.dest || !(*s_a) || !(*s_b))
		return ;
	while ((ft_lstsize(*s_a) - best.src->i) > 0)
	{
		if (!(*s_a))
			break ;
		reverse_rotate_a(s_a, 1);
		best.src->i++;
	}
	while (best.dest->i > 0)
	{
		if (!(*s_b))
			break ;
		rotate_b(s_b, 1);
		best.dest->i--;
	}
}

void	push_all_to_a(t_list **s_a, t_list **s_b)
{
	if (!(*s_b))
		return ;
	while (get_max_node(*s_b)->i != 0)
	{
		if (get_max_node(*s_b)->i <= ft_lstsize(*s_b) / 2)
			rotate_b(s_b, 1);
		else
			reverse_rotate_b(s_b, 1);
		set_indexs(*s_b);
	}
	if ((*s_a)->content < (*s_b)->content)
		while (ft_lstlast(*s_a)->content > (*s_b)->content)
			reverse_rotate_a(s_a, 1);
	while (*s_b)
	{
		push_a(s_a, s_b, 1);
		while ((*s_b) && ft_lstlast(*s_a)->content > (*s_b)->content
			&& ft_lstlast(*s_a)->content < (*s_a)->content)
			reverse_rotate_a(s_a, 1);
	}
}
