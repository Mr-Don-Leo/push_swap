/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_values.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 14:31:16 by mbabayan          #+#    #+#             */
/*   Updated: 2024/06/19 12:57:03 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*parse_array(char **split_values, int total_values, t_input *p_values)
{
	int	index;
	int	*array;
	int	check;

	index = -1;
	array = malloc(sizeof(int) * total_values);
	if (!array)
		return (free_darray(split_values), NULL);
	while (++index < total_values)
	{
		if (check_digit(split_values[index], array) == 0)
		{
			if (add_to_array(array, split_values, index) == 1)
				return (free_darray(split_values), NULL);
		}
		else
		{
			printf("Error\n");
			return (free_darray(split_values), NULL);
		}
	}
	free_darray(split_values);
	return (array);
}
