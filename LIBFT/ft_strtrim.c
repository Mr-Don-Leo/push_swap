/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:19:27 by mbabayan          #+#    #+#             */
/*   Updated: 2024/07/05 12:31:22 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	index;

	index = 0;
	while (ft_strchr(set, s1[index]) && s1[index])
		index++;
	s1 = &s1[index];
	index = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[index]) && index > 0)
		index--;
	return (ft_substr(s1, 0, index + 1));
}
