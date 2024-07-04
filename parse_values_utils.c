/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_values_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 14:33:12 by mbabayan          #+#    #+#             */
/*   Updated: 2024/07/05 02:05:34 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_digit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

char	**free_darray(char **split_values)
{
	int	i;

	i = 0;
	while (split_values[i])
		free(split_values[i++]);
	free(split_values);
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

int	add_to_array(int *array, char **split_values, int i)
{
	if (i == 0)
		array[i] = ft_atoi(split_values[i], array, split_values);
	else
	{
		if (dup_check(array, ft_atoi(split_values[i], array, split_values),
				i) == 0)
			array[i] = ft_atoi(split_values[i], array, split_values);
		else
			return (free(array), 1);
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
	exit(1);
}
