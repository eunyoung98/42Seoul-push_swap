/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehwangbo <ehwangbo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:21:50 by ehwangbo          #+#    #+#             */
/*   Updated: 2021/06/19 11:03:54 by ehwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sub_atob(t_stack *a, t_stack *b, t_opcnt *opcnt, t_atob *atob)
{
	if (a->head->value >= atob->pivot2)
	{
		op_ra(a, opcnt);
		atob->ra++;
	}
	else
	{
		op_pb(a, b, opcnt);
		atob->pb++;
		if (b->head->value >= atob->pivot1)
		{
			op_rb(b, opcnt);
			atob->rb++;
		}
	}
}

void	init_atob(t_atob *atob)
{
	atob->ra = 0;
	atob->rb = 0;
	atob->pa = 0;
	atob->pb = 0;
	atob->pivot1 = 0;
	atob->pivot2 = 0;
}

void	a_to_b(t_stack *a, t_stack *b, int size, t_opcnt *opcnt)
{
	t_atob	*atob;

	if (size <= 3)
	{
		size_3_atob(a, size, opcnt);
		return ;
	}
	atob = malloc(sizeof(t_atob));
	init_atob(atob);
	atob->pivot1 = get_min_val(cpy_dblst(a->head, size), size);
	atob->pivot2 = get_max_val(cpy_dblst(a->head, size), size);
	while (size-- > 0)
		sub_atob(a, b, opcnt, atob);
	sub_ft(a, b, atob, opcnt);
	a_to_b(a, b, atob->ra, opcnt);
	b_to_a(a, b, atob->rb, opcnt);
	b_to_a(a, b, atob->pb - atob->rb, opcnt);
	free(atob);
}
