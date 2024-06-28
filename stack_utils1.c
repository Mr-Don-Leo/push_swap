/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 23:50:02 by mbabayan          #+#    #+#             */
/*   Updated: 2024/06/28 14:17:31 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_indexs(t_list *stack)
{
	t_list	*current;
	int		index;

	current = stack;
	index = 0;
	while (current)
	{
		current->index = index;
		current = current->next;
		index++;
	}
}

void init_stack(t_list **stack, int size, int *array)
{
	int index;
	t_list *new_node;

	index = 0;
	while (index < size) 
	{
		new_node = ft_lstnew(array[index]);
		if (!new_node)
		{
			ft_lstclear(stack, free);
			free(array);
			exiting(NULL, NULL, "Error");
		}
		ft_lstadd_back(stack, new_node);
		index++;
	}
	set_indexs(*stack);
	free(array);
}

t_list *get_max_node(t_list *stack)
{
	t_list *max_node;
	t_list *current;

	max_node = stack;
	current = stack;
	while (current)
	{
		if (current->content > max_node->content)
			max_node = current;
		current = current->next;
	}
	return (max_node);
}

t_list *get_min_node(t_list *stack)
{
	t_list *min_node;
	t_list *current;

	min_node = stack;
	current = stack;
	while (current)
	{
		if (current->content < min_node->content)
			min_node = current;
		current = current->next;
	}
	return (min_node);
}

int  check_if_sorted(t_list *stack)
{
	t_list *current;

	current = stack;
	while (current->next)
	{
		if (current->content > current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}