/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:47:59 by mbabayan          #+#    #+#             */
/*   Updated: 2024/06/24 13:41:42 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *find_node(t_list *stack, int number)
{
	t_list *current;

	current = stack;
	while (current)
	{
		if (current->content == number)
			return (current);
		current = current->next;
	}
	return (NULL);
}
