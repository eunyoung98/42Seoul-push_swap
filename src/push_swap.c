/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehwangbo <ehwangbo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:21:50 by ehwangbo          #+#    #+#             */
/*   Updated: 2021/07/15 12:09:29 by ehwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	before_push_swap(int len, char **argv)
{
	int		i;
	t_stack	*a;
	t_stack	*b;
	t_opcnt	*opcnt;

	i = 0;
	a = malloc(sizeof(t_dblst));
	b = malloc(sizeof(t_dblst));
	opcnt = malloc(sizeof(t_opcnt));
	init_cnt(opcnt);
	pre_stack(a, b);
	while (i < len)
		push_argv(a, argv[i++]);
	a_to_b(a, b, dbsize(a->head), opcnt);
	clear_stack(a);
	clear_stack(b);
	free(opcnt);
}

int	main(int argc, char **argv)
{
	char	**arg;
	int		len;

	if (argc == 1)
		exit(1);
	len = parse(argc, argv);
	arg = malloc(sizeof(char *) * (len + 1));
	if (!arg)
	{
		ft_putstr_fd("Malloc Error\n", 2);
		exit(1);
	}
	insert_arg(argc, argv, arg);
	if (check_arr(arg, len) == 0)
		exit(1);
	before_push_swap(len, arg);
	last_free(argc, argv, arg);
	return (0);
}
