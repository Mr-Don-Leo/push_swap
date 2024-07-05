/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:25:17 by mbabayan          #+#    #+#             */
/*   Updated: 2024/07/05 11:47:57 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	limitcheck(long result, int *array, char **split_values)
{
	if (result > INT_MAX || result < INT_MIN)
		exiting(array, split_values, "Error");
}

static long	overflowcheck(const char *str, int *array, char **split_values,
		int i)
{
	long	result;
	long	temp;

	result = 0;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		temp = result;
		result *= 10;
		result += str[i] - '0';
		if (result < temp)
			exiting(array, split_values, "Error");
		i++;
	}
	return (result);
}

long	ft_atoi(const char *split_index, int *array, char **split_values)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (split_index[i] == 32 || (split_index[i] >= 9
			&& split_index[i] <= 13))
		i++;
	if (split_index[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (split_index[i] == '+')
		i++;
	result = overflowcheck(split_index, array, split_values, i);
	result = result * sign;
	limitcheck(result, array, split_values);
	return (result);
}
