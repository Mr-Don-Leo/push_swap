/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 03:56:27 by mbabayan          #+#    #+#             */
/*   Updated: 2024/07/05 02:09:31 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_input	parsed_values;
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc < 2)
		exit(0);
	parsed_values = process_input(--argc, argv);
	if (parsed_values.total_values == 1)
	{
		free(parsed_values.array);
		exit(0);
	}
	stack_a = NULL;
	stack_b = NULL;
	init_stack(&stack_a, parsed_values.total_values, parsed_values.array);
	if (!check_if_sorted(stack_a))
	{
		sort(&stack_a, &stack_b);
		while (!check_if_sorted(stack_a))
			reverse_rotate_a(&stack_a, 1);
	}
	ft_lstclear(&stack_a, free);
	return (0);
}
