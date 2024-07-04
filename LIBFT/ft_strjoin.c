/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:56:42 by mbabayan          #+#    #+#             */
/*   Updated: 2024/06/21 13:29:02 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * ft_strjoin allocates (with malloc(3)) and returns a new string, which is the
 * result of the concatenation of ’s1’ and ’s2’.
 */
char	*ft_strjoin(char *s1, char *s2)
{
	int		index;
	int		index2;
	char	*str;

	index = 0;
	index2 = 0;
	if (!s2 || !(*s2))
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!str)
		return (NULL);
	while (s1 && s1[index])
		str[index2++] = s1[index++];
	str[index2++] = ' ';
	index = 0;
	while (s2[index] && s2[index] != '\n')
		str[index2++] = s2[index++];
	str[index2] = '\0';
	if (s1)
		free(s1);
	return (str);
}
