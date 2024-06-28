/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_values_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 14:33:12 by mbabayan          #+#    #+#             */
/*   Updated: 2024/06/24 13:00:52 by mbabayan         ###   ########.fr       */
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
int	dup_check(int *intarr, int number, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (number == intarr[i])
			return (1);
		else
			i++;
	}
	return (0);
}

int	add_to_array(int *array, char **split_values, int index)
{
	if (index == 0)
		array[index] = ft_atoi(split_values[index], array, split_values);
	else
	{
		if (dup_check(array, ft_atoi(split_values[index], array, split_values), index) == 0)
			array[index] = ft_atoi(split_values[index], array, split_values);
		else
			return (free (array), 1);
	}
	return (0);
}

void	exiting(void *str, char **split, char *error_m)
{
	if (str)
		free(str);
	if (split)
		free_darray(split);
	ft_printf("%s\n", error_m);
	exit (1);
}
