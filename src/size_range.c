/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_range.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehwangbo <ehwangbo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:21:50 by ehwangbo          #+#    #+#             */
/*   Updated: 2021/06/19 11:03:54 by ehwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	size_3_a(t_stack *a, t_opcnt *opcnt)
{
	int	arr[3];

	arr[0] = a->head->value;
	arr[1] = a->head->next->value;
	arr[2] = a->head->next->next->value;
	if (arr[0] < arr[2] && arr[2] < arr[1])
	{
		op_ra(a, opcnt);
		op_sa(a, opcnt);
		op_rra(a, opcnt);
	}
	else if (arr[1] < arr[0] && arr[0] < arr[2])
		op_sa(a, opcnt);
	else if (arr[1] < arr[2] && arr[2] < arr[0])
		case_a120(a, opcnt);
	else if (arr[2] < arr[0] && arr[0] < arr[1])
		case_a201(a, opcnt);
	else if (arr[2] < arr[1] && arr[1] < arr[0])
		case_a210(a, opcnt);
}

void	size_3_atob(t_stack *a, int size, t_opcnt *opcnt)
{
	if (size <= 1)
		return ;
	else if (size == 2)
	{
		if (a->head->value > a->head->next->value)
			op_sa(a, opcnt);
	}
	else if (size == 3)
		size_3_a(a, opcnt);
}

void	size_3_b(t_stack *a, t_stack *b, t_opcnt *opcnt)
{
	int	arr[3];

	arr[0] = b->head->value;
	arr[1] = b->head->next->value;
	arr[2] = b->head->next->next->value;
	if (arr[0] < arr[1] && arr[1] < arr[2])
		case_b012(a, b, opcnt);
	else if (arr[0] < arr[2] && arr[2] < arr[1])
		case_b021(a, b, opcnt);
	else if (arr[1] < arr[0] && arr[0] < arr[2])
		case_b102(a, b, opcnt);
	else if (arr[1] < arr[2] && arr[2] < arr[0])
		case_b120(a, b, opcnt);
	else if (arr[2] < arr[0] && arr[0] < arr[1])
		case_b201(a, b, opcnt);
	else if (arr[2] < arr[1] && arr[1] < arr[0])
	{
		op_pa(a, b, opcnt);
		op_pa(a, b, opcnt);
		op_pa(a, b, opcnt);
	}
}

void	size_3_btoa(t_stack *a, t_stack *b, int size, t_opcnt *opcnt)
{
	if (size == 1)
		op_pa(a, b, opcnt);
	else if (size == 2)
	{
		if (b->head->value < b->head->next->value)
			op_sb(b, opcnt);
		op_pa(a, b, opcnt);
		op_pa(a, b, opcnt);
	}
	else if (size == 3)
		size_3_b(a, b, opcnt);
}
