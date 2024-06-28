/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:25:17 by mbabayan          #+#    #+#             */
/*   Updated: 2024/06/25 12:54:50 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	limitcheck(long result, int *array, char **split_values)
{
	if (result > INT_MAX || result < INT_MIN)
		exiting(array, split_values, "Error");
}

static long	overflowcheck(const char *str, int *array, char **split_values, int index)
{
	long	result;
	long	temp;

	result = 0;
	while (str[index] != '\0' && str[index] >= '0' && str[index] <= '9')
	{
		temp = result;
		result *= 10;
		result += str[index] - '0';
		if (result < temp)
			exiting(array, split_values, "Error");
		index++;
	}
	return (result);
}

long	ft_atoi(const char *split_index, int *array, char **split_values)
{
	int		index;
	int		sign;
	long	result;

	index = 0;
	sign = 1;
	result = 0;
	while (split_index[index] == 32 || (split_index[index] >= 9 && split_index[index] <= 13))
		index++;
	if (split_index[index] == '-')
	{
		sign = -1;
		index++;
	}
	else if (split_index[index] == '+')
		index++;
	result = overflowcheck(split_index, array, split_values, index);
	result = result * sign;
	return (limitcheck(result, array, split_values), result);
}
