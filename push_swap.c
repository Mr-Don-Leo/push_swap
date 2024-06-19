/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 03:56:27 by mbabayan          #+#    #+#             */
/*   Updated: 2024/06/19 11:33:54 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_input parsed_values;
	
	if (argc < 2)
		exit (0);
	parsed_values = process_input(--argc, argv);
	while (parsed_values.index < parsed_values.total_values)
	{
		printf("%d\n", parsed_values.array[parsed_values.index]);
		parsed_values.index++;
	}
	// if (parsed_values.total_values == 1)
	
	
	return (0);
}