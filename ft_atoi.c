/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:25:17 by mbabayan          #+#    #+#             */
/*   Updated: 2024/06/19 12:58:10 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	limitcheck(long result, int *intarr, char **arr)
{
	if (result > INT_MAX || result < INT_MIN)
		exiting(intarr, arr, "Error");
}

static long	overflowcheck(const char *str, int *intarr, char **arr, int i)
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
			exiting(intarr, arr, "Error");
		i++;
	}
	return (result);
}

long	ft_atoi(const char *sp_inp_i, int *intarr, char **sp_inp)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (sp_inp_i[i] == 32 || (sp_inp_i[i] >= 9 && sp_inp_i[i] <= 13))
		i++;
	if (sp_inp_i[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (sp_inp_i[i] == '+')
		i++;
	result = overflowcheck(sp_inp_i, intarr, sp_inp, i);
	result = result * sign;
	return (limitcheck(result, intarr, sp_inp), result);
}
