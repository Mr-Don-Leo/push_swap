/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 12:41:24 by mbabayan          #+#    #+#             */
/*   Updated: 2024/06/28 02:22:24 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * function sets the 'next' pointer of the new element to point to the current
 * first element of the 'lst', then updates lst pointer to the 'new' element.
 */
void ft_lstadd_front(t_list **lst, t_list *new)
{
	if ((*lst))
	{
		new -> next = (*lst);
		(*lst) = new;	
	}
}
