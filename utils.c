/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 23:50:02 by mbabayan          #+#    #+#             */
/*   Updated: 2024/06/19 12:35:20 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exiting(void *str, char **split, char *error_m)
{
	if (str)
		free(str);
	if (split)
		free_darray(split);
	if (error_m[0] != '\0')
		ft_printf("%s\n", error_m);
	exit (1);
}