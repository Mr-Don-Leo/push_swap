/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 13:11:39 by mbabayan          #+#    #+#             */
/*   Updated: 2024/06/19 15:14:19 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*join_strings(int argc, char **argv)
{
	int		index;
	char 	*str;
	
	index = 1;
	if (argv[1] == NULL || argv[1][0] == '\0')
		exiting(NULL, NULL, "Error\n");
	str = ft_strdup(argv[1]);
	while (++index <= argc)
	{
		if (check_space(argv[index]))
			exiting(str, NULL, "Error\n");
		str = ft_strjoin(str, argv[index]);
	}
	return (str);
}

t_input	process_input(int argc, char **argv)
{
	t_input	p_values;

	p_values.value_string = join_strings(argc, argv);
	p_values.split_values = ft_split(p_values.value_string, ' ');
	if (!p_values.split_values)
		exiting(p_values.value_string, NULL,
			"Error\n");
	p_values.total_values = count_values(p_values.split_values);
	p_values.index = 0;
	free(p_values.value_string);
	if (p_values.split_values[p_values.index] == 0
		|| p_values.split_values[p_values.index] == NULL)
		exiting(NULL, p_values.split_values, "Error\n");
	p_values.array = parse_array(p_values.split_values, p_values.total_values, &p_values);
	if (!p_values.array)
		exiting(NULL, NULL,
			"Error\n");
	return (p_values);
}

