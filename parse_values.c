/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_values.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 14:31:16 by mbabayan          #+#    #+#             */
/*   Updated: 2024/06/15 23:54:02 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int *parse_array(char **split_values, int total_values)
{
	int index;
	int *array;
	int check;

	index = 0;
	array = malloc(sizeof(int) * total_values);
	if (!array)
		return (free_darray(split_values));
	while (++index < total_values)
	{
		if (check_digit(split_values[index]) == 0)
		{
			array[index] = ft_atoi(split_values[index]);
			index++;
		}
		else
			return (free_darray(split_values));
	}
	check_duplicates(array, total_values);
	return (array);
}

