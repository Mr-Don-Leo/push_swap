/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 03:56:27 by mbabayan          #+#    #+#             */
/*   Updated: 2024/06/15 13:10:40 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_input *parsed_values;
	
	if (argc < 2)
		exit (0);
	parsed_values = process_input(--argc, argv);
	
	
	return (0);
}