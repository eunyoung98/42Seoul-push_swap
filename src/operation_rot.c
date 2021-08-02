/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehwangbo <ehwangbo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:21:50 by ehwangbo          #+#    #+#             */
/*   Updated: 2021/07/14 10:42:23 by ehwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	op_ra(t_stack *a, t_opcnt *opcnt)
{
	rotate_stack(a);
	opcnt->ra++;
	ft_putstr_fd("ra\n", 1);
}

void	op_rb(t_stack *b, t_opcnt *opcnt)
{
	rotate_stack(b);
	opcnt->rb++;
	ft_putstr_fd("rb\n", 1);
}

void	op_rr(t_stack *a, t_stack *b, t_opcnt *opcnt)
{
	rotate_stack(a);
	rotate_stack(b);
	opcnt->rr++;
	ft_putstr_fd("rr\n", 1);
}
