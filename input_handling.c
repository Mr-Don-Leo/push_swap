/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 13:11:39 by mbabayan          #+#    #+#             */
/*   Updated: 2024/06/15 14:29:25 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_input	*process_input(int argc, char **argv)
{
	t_input	p_values;

	p_values.value_string = join_strings(argc, argv);
	p_values.split_values = ft_split(p_values.value_string, ' ');
	if (!p_values.split_values)
		// TODO: error handling, raise_error("Error: invalid input"); ((((exiting(p_values.value_string, NULL);))))
	p_values.total_values = count_values(p_values.split_values);
	p_values.index = 0;
	free(p_values.value_string);
	if (p_values.split_values[p_values.index] == 0
		|| p_values.split_values[p_values.index] == NULL)
		// TODO: error handling, raise_error("Error: invalid input"); ((((exiting(NULL, p_values.split_values);))))
	p_values.array = parse_array(p_values.split_values, p_values.total_values);
	return (&p_values);
}

char	*join_strings(int argc, char **argv)
{
	int		index;
	char 	*str;
	
	index = 1;
	if (argv[1] == NULL || argv[1][0] == '\0')
		// TODO: error handling, raise_error("Error: empty input"); ((((exiting(NULL, NULL);))))
	str = ft_strdup(argv[1]);
	while (++index <= argc)
	{
		if (check_space(argv[index]))
			// TODO: error handling, raise_error("Error: invalid input"); ((((exiting(str, NULL);))))
		str = ft_strjoin(str, argv[index]);
	}
	return (str);
}
