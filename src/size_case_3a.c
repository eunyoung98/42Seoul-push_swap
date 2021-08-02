/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_case_3a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehwangbo <ehwangbo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:21:50 by ehwangbo          #+#    #+#             */
/*   Updated: 2021/06/19 11:03:54 by ehwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	case_a120(t_stack *a, t_opcnt *opcnt)
{
	if (dbsize(a->head) == 3)
		op_ra(a, opcnt);
	else
	{
		op_sa(a, opcnt);
		op_ra(a, opcnt);
		op_sa(a, opcnt);
		op_rra(a, opcnt);
	}
}

void	case_a201(t_stack *a, t_opcnt *opcnt)
{
	if (dbsize(a->head) == 3)
		op_rra(a, opcnt);
	else
	{
		op_ra(a, opcnt);
		op_sa(a, opcnt);
		op_rra(a, opcnt);
		op_sa(a, opcnt);
	}
}

void	case_a210(t_stack *a, t_opcnt *opcnt)
{
	if (dbsize(a->head) == 3)
	{
		op_sa(a, opcnt);
		op_rra(a, opcnt);
	}
	else
	{
		op_sa(a, opcnt);
		op_ra(a, opcnt);
		op_sa(a, opcnt);
		op_rra(a, opcnt);
		op_sa(a, opcnt);
	}
}
