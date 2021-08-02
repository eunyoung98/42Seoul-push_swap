/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehwangbo <ehwangbo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:21:50 by ehwangbo          #+#    #+#             */
/*   Updated: 2021/07/15 12:10:02 by ehwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	chk_res(t_dblst *a, t_dblst *b, t_dblst *order)
{
	int	i;

	i = 0;
	if (b != NULL)
		write(1, "KO\n", 3);
	else
	{
		while (i++ < dbsize(order))
		{
			if (a->value > order->value)
			{
				write(1, "KO\n", 3);
				return ;
			}
			a = a->next;
			order = order->next;
		}
		write(1, "OK\n", 3);
	}
}

int	operate_op(char **line, t_stack *a, t_stack *b)
{
	if (ft_strlen(*line) == 2 && ft_strnstr(*line, "sa", 2))
		op_sa_chk(a);
	else if (ft_strlen(*line) == 2 && ft_strnstr(*line, "sb", 2))
		op_sb_chk(b);
	else if (ft_strlen(*line) == 2 && ft_strnstr(*line, "ss", 2))
		op_ss_chk(a, b);
	else if (ft_strlen(*line) == 2 && ft_strnstr(*line, "pa", 2))
		op_pa_chk(a, b);
	else if (ft_strlen(*line) == 2 && ft_strnstr(*line, "pb", 2))
		op_pb_chk(a, b);
	else if (ft_strlen(*line) == 2 && ft_strnstr(*line, "ra", 2))
		op_ra_chk(a);
	else if (ft_strlen(*line) == 2 && ft_strnstr(*line, "rb", 2))
		op_rb_chk(b);
	else if (ft_strlen(*line) == 2 && ft_strnstr(*line, "rr", 2))
		op_rr_chk(a, b);
	else if (ft_strlen(*line) == 3 && ft_strnstr(*line, "rra", 3))
		op_rra_chk(a);
	else if (ft_strlen(*line) == 3 && ft_strnstr(*line, "rrb", 3))
		op_rrb_chk(b);
	else if (ft_strlen(*line) == 3 && ft_strnstr(*line, "rrr", 3))
		op_rrr_chk(a, b);
	else
		return (0);
	return (1);
}

void	checker_push_swap(int len, char **argv)
{
	int		i;
	t_stack	*cp_a;
	t_stack	*cp_b;
	t_stack	*cp_order;

	i = 0;
	cp_a = malloc(sizeof(t_dblst));
	cp_b = malloc(sizeof(t_dblst));
	cp_order = malloc(sizeof(t_dblst));
	pre_stack(cp_a, cp_b);
	if (!cp_order)
	{
		ft_putstr_fd("Malloc error\n", 2);
		exit(1);
	}
	init_stack(cp_order);
	while (i < len)
	{
		push_argv(cp_a, argv[i]);
		push_argv(cp_order, argv[i++]);
	}
	gnl(cp_a, cp_b, cp_order);
	clear_stack(cp_a);
	clear_stack(cp_b);
	clear_stack(cp_order);
}

void	gnl(t_stack *a, t_stack *b, t_stack *order)
{
	char	*line;
	int		ret;

	line = NULL;
	if (dbsize(order->head) == 2)
	{
		if (order->head->value > order->head->next->value)
			swap(order->head, order->head->next);
	}
	else if (dbsize(order->head) > 2 )
		quick_sort_arr(order->head);
	ret = get_next_line(0, &line);
	while (ret > 0)
	{
		if (operate_op(&line, a, b) == 0)
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		free(line);
		line = NULL;
		ret = get_next_line(0, &line);
	}
	free(line);
	chk_res(a->head, b->head, order->head);
}

int	main(int argc, char **argv)
{
	int		len;
	char	**arg;

	if (argc == 1)
		exit(1);
	len = parse(argc, argv);
	arg = malloc(sizeof(char *) * (len + 1));
	if (!arg)
	{
		ft_putstr_fd("Malloc Error\n", 2);
		exit(1);
	}
	arg = insert_arg(argc, argv, arg);
	if (check_arr(arg, len) == 0 || check_arr(arg, len) == 1)
		checker_push_swap(len, arg);
	last_free(argc, argv, arg);
	return (0);
}
