/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_values.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 14:31:16 by mbabayan          #+#    #+#             */
/*   Updated: 2024/07/05 02:04:27 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*parse_array(char **split_values, int total_values)
{
	int	i;
	int	*array;

	i = 0;
	array = malloc(sizeof(int) * total_values);
	if (!array)
		return (free_darray(split_values), NULL);
	while (i < total_values)
	{
		if (check_digit(split_values[i]) == 0)
		{
			if (add_to_array(array, split_values, i) == 1)
				return (free_darray(split_values), NULL);
		}
		else
			return (free_darray(split_values), NULL);
		i++;
	}
	free_darray(split_values);
	return (array);
}
