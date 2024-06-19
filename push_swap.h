/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 03:57:11 by mbabayan          #+#    #+#             */
/*   Updated: 2024/06/18 18:40:28 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "LIBFT/libft.h"
# include "PRINTF/ft_printf.h"
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}	t_list;

typedef struct s_input
{
	int		index;
	int		total_values;
	char	*value_string;
	int		*array;
	char	**split_values;
}	t_input;

t_input process_input(int argc, char **argv);
int		check_space(char *str);
int		count_values(char **split_values);
int		check_digit(char *str);
char	**free_darray(char **split_values);
int		*parse_array(char **split_values, int total_values, t_input *p_values);
int		add_to_array(int *array, char **split_values, int index);
void	exiting(void *str, char **split, char *error_m);
long	ft_atoi(const char *sp_inp_i, int *intarr, char **sp_inp);


#endif