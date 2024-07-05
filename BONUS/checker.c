/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:58:01 by mbabayan          #+#    #+#             */
/*   Updated: 2024/07/05 16:20:19 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_move(char *s1, char *s2)
{
	int	index;

	index = 0;
	while (s1[index] && s2[index] && s1[index] == s2[index])
		index++;
	if ((s1[index] - s2[index]) == 0)
		return (1);
	return (0);
}

void	do_move(t_list **stack_a, t_list **stack_b, char *line)
{
	if (check_move(line, "rra\n") || check_move(line, "rrb\n")
		|| check_move(line, "rrr\n"))
		checker_rev_rotate(stack_a, stack_b, line);
	else if (check_move(line, "ra\n") || check_move(line, "rb\n")
		|| check_move(line, "rr\n"))
		checker_rotate(stack_a, stack_b, line);
	else if (check_move(line, "sa\n") || check_move(line, "sb\n")
		|| check_move(line, "ss\n"))
		checker_swap(stack_a, stack_b, line);
	else if (check_move(line, "pb\n") || check_move(line, "pa\n"))
		checker_push(stack_a, stack_b, line);
	else
	{
		free(line);
		ft_lstclear(stack_a, free);
		if (*stack_b)
			ft_lstclear(stack_b, free);
		ft_printf("Error\n");
		exit(1);
	}
}

void	follow_moves(t_list **stack_a, t_list **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line != NULL)
	{
		do_move(stack_a, stack_b, line);
		free(line);
		line = get_next_line(0);
	}
}

int	*checker_parse(int argc, char **argv, int *size)
{
	char	**split;
	char	*string;
	int		*array;

	string = join_strings(--argc, argv);
	split = ft_split(string, ' ');
	if (!split)
		exiting(string, NULL, "Error");
	*size = count_values(split);
	free(string);
	if (split[0] == 0 || split[0] == NULL)
		exiting(NULL, split, "Error");
	array = parse_array(split, *size);
	if (!array)
		exiting(NULL, NULL, "Error");
	return (array);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		*array;
	int		size;

	size = 0;
	if (ac < 2)
		exit(0);
	stack_a = NULL;
	stack_b = NULL;
	array = checker_parse(ac, av, &size);
	init_stack(&stack_a, size, array);
	follow_moves(&stack_a, &stack_b);
	if (check_if_sorted(stack_a) && ft_lstsize(stack_b) == 0)
		ft_printf("OK\n");
	else if (!check_if_sorted(stack_a) || ft_lstsize(stack_b) != 0)
		ft_printf("KO\n");
	ft_lstclear(&stack_a, free);
	if (stack_b)
		ft_lstclear(&stack_b, free);
	return (0);
}
