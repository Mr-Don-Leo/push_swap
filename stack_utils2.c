/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:47:59 by mbabayan          #+#    #+#             */
/*   Updated: 2024/07/04 11:40:37 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_node(t_list **stack, int number)
{
	t_list	*current;
	t_list	*holder;

	if (!stack || !(*stack))
		return (NULL);
	holder = get_min_node(stack);
	if (number < holder->content)
		return (get_max_node(*stack));
	current = *stack;
	while (current)
	{
		if (current->content >= holder->content && number > current->content)
			holder = current;
		current = current->next;
	}
	return (holder);
}
