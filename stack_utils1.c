/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 23:50:02 by mbabayan          #+#    #+#             */
/*   Updated: 2024/07/05 02:05:59 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_indexs(t_list *stack)
{
	t_list	*current;
	int		i;

	current = stack;
	i = 0;
	while (current)
	{
		current->i = i;
		current = current->next;
		i++;
	}
}

void	init_stack(t_list **stack, int size, int *array)
{
	int		i;
	t_list	*new_node;

	i = 0;
	while (i < size)
	{
		new_node = ft_lstnew(array[i]);
		if (!new_node)
		{
			ft_lstclear(stack, free);
			free(array);
			exiting(NULL, NULL, "Error");
		}
		ft_lstadd_back(stack, new_node);
		i++;
	}
	set_indexs(*stack);
	free(array);
}

t_list	*get_max_node(t_list *stack)
{
	t_list	*max_node;
	t_list	*current;

	if (!stack)
		return (NULL);
	current = stack;
	max_node = current;
	while (current)
	{
		if (current->content > max_node->content)
			max_node = current;
		current = current->next;
	}
	return (max_node);
}

t_list	*get_min_node(t_list **stack)
{
	t_list	*minimum;
	t_list	*temporary;

	if (!stack || !(*stack))
		return (NULL);
	temporary = (*stack);
	minimum = temporary;
	while (temporary)
	{
		if (temporary->content < minimum->content)
			minimum = temporary;
		temporary = temporary->next;
	}
	return (minimum);
}

int	check_if_sorted(t_list *stack)
{
	t_list	*current;

	current = stack;
	while (current->next)
	{
		if (current->content > current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}
