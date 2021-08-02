/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_case_3b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehwangbo <ehwangbo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:21:50 by ehwangbo          #+#    #+#             */
/*   Updated: 2021/06/19 11:03:54 by ehwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	case_b012(t_stack *a, t_stack *b, t_opcnt *opcnt)
{
	if (dbsize(b->head) == 3)
	{
		op_rb(b, opcnt);
		op_sb(b, opcnt);
		op_pa(a, b, opcnt);
		op_pa(a, b, opcnt);
		op_pa(a, b, opcnt);
	}
	else
	{
		op_rb(b, opcnt);
		op_sb(b, opcnt);
		op_pa(a, b, opcnt);
		op_pa(a, b, opcnt);
		op_rrb(b, opcnt);
		op_pa(a, b, opcnt);
	}
}

void	case_b021(t_stack *a, t_stack *b, t_opcnt *opcnt)
{
	if (dbsize(b->head) == 3)
	{
		op_rb(b, opcnt);
		op_pa(a, b, opcnt);
		op_pa(a, b, opcnt);
		op_pa(a, b, opcnt);
	}
	else
	{
		op_rb(b, opcnt);
		op_pa(a, b, opcnt);
		op_pa(a, b, opcnt);
		op_rrb(b, opcnt);
		op_pa(a, b, opcnt);
	}
}

void	case_b102(t_stack *a, t_stack *b, t_opcnt *opcnt)
{
	if (dbsize(b->head) == 3)
	{
		op_rrb(b, opcnt);
		op_pa(a, b, opcnt);
		op_pa(a, b, opcnt);
		op_pa(a, b, opcnt);
	}
	else
	{
		op_pa(a, b, opcnt);
		op_sb(b, opcnt);
		op_pa(a, b, opcnt);
		op_sa(a, opcnt);
		op_pa(a, b, opcnt);
	}
}

void	case_b120(t_stack *a, t_stack *b, t_opcnt *opcnt)
{
	op_pa(a, b, opcnt);
	op_sb(b, opcnt);
	op_pa(a, b, opcnt);
	op_pa(a, b, opcnt);
}

void	case_b201(t_stack *a, t_stack *b, t_opcnt *opcnt)
{
	op_sb(b, opcnt);
	op_pa(a, b, opcnt);
	op_pa(a, b, opcnt);
	op_pa(a, b, opcnt);
}
