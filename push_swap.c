/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 03:56:27 by mbabayan          #+#    #+#             */
/*   Updated: 2024/07/01 22:42:36 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "push_swap.h"

void print_stack(t_list *stack)
{
	t_list *temp;

	temp = stack;
	while (temp)
	{
		printf("%d\n", temp->content);
		temp = temp->next;
	}
	sleep(1);
}

int main(int argc, char **argv)
{
	t_input parsed_values;
	t_list *stack_a;
	t_list *stack_b;
	
	if (argc < 2)
		exit (0);
	parsed_values = process_input(--argc, argv);
	if (parsed_values.total_values == 1)
	{
		free(parsed_values.array);
		exit (0);
	}
	stack_a = NULL;
	stack_b = NULL;
	init_stack(&stack_a, parsed_values.total_values, parsed_values.array);
	
	printf("STACK_A\n------------\n");
	print_stack(stack_a);
	printf("\n------------\nPROCESS\n");
	if (!check_if_sorted(stack_a))
	{
		sort(&stack_a, &stack_b);
	}


	
	return (0);
}

