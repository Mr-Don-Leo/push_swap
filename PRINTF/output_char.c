/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:51:12 by mbabayan          #+#    #+#             */
/*   Updated: 2024/05/19 13:53:33 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	output_char(va_list arguments)
{
	char	character;

	character = va_arg(arguments, int);
	ft_putchar(character);
	return (1);
}
