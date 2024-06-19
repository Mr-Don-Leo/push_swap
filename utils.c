/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 23:50:02 by mbabayan          #+#    #+#             */
/*   Updated: 2024/06/18 00:21:36 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exiting(void *str, char **split, char *error_m)
{
	if (str)
		free(str);
	if (split)
		free_darray(split);
	ft_printf("%s\n", error_m);
	exit (1);
}