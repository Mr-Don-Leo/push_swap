/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_values_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 14:33:12 by mbabayan          #+#    #+#             */
/*   Updated: 2024/06/15 23:53:40 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_digit(char *str)
{
	int index;

	index = 0;
	if (str[index] == '-' || str[index] == '+')
		index++;
	while (str[index])
	{
		if (!ft_isdigit(str[index]))
			return (1);
		index++;
	}
	return (0);
}

char	**free_darray(char **split_values)
{
	int	index;

	index = 0;
	while (split_values[index])
		free (split_values[index++]);
	free (split_values);
	return (NULL);
}

void	check_duplicates(int *array, int total_values)
{
	int	index;
	int	index2;

	index = 0;
	while (index < total_values)
	{
		index2 = index + 1;
		while (index2 < total_values)
		{
			if (array[index] == array[index2])
				// TODO: free struct, and return error dupe
			index2++;
		}
		index++;
	}
}