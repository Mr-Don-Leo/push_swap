/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 16:03:56 by mbabayan          #+#    #+#             */
/*   Updated: 2024/07/05 01:38:40 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_cost_flag(unsigned int temp, t_cef *info, int flag)
{
	info->cost = temp;
	info->flag = flag;
}

int	compare(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}
