/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehwangbo <ehwangbo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:21:50 by ehwangbo          #+#    #+#             */
/*   Updated: 2021/06/19 11:03:54 by ehwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	op_sa(t_stack *a, t_opcnt *opcnt)
{
	swap_stack(a);
	opcnt->sa++;
	ft_putstr_fd("sa\n", 1);
}

void	op_sb(t_stack *b, t_opcnt *opcnt)
{
	swap_stack(b);
	opcnt->sb++;
	ft_putstr_fd("sb\n", 1);
}

void	op_ss(t_stack *a, t_stack *b, t_opcnt *opcnt)
{
	swap_stack(a);
	swap_stack(b);
	opcnt->ss++;
	ft_putstr_fd("ss\n", 1);
}

void	op_pa(t_stack *a, t_stack *b, t_opcnt *opcnt)
{
	push_stack(b, a);
	opcnt->pa++;
	ft_putstr_fd("pa\n", 1);
}

void	op_pb(t_stack *a, t_stack *b, t_opcnt *opcnt)
{
	push_stack(a, b);
	opcnt->pb++;
	ft_putstr_fd("pb\n", 1);
}
