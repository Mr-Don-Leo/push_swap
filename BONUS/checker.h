/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:58:26 by mbabayan          #+#    #+#             */
/*   Updated: 2024/07/05 14:53:39 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../push_swap.h"
# include "../LIBFT/libft.h"
# include "./get_next_line/get_next_line.h"

int		check_move(char *s1, char *s2);
int		count_int_array(int *array);
void	checker_push(t_list **stack_a, t_list **stack_b, char *move);
void	checker_swap(t_list **stack_a, t_list **stack_b, char *move);
void	checker_rotate(t_list **stack_a, t_list **stack_b, char *move);
void	checker_rev_rotate(t_list **stack_a, t_list **stack_b, char *move);

#endif
