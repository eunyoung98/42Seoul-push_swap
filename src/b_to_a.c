/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehwangbo <ehwangbo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:21:50 by ehwangbo          #+#    #+#             */
/*   Updated: 2021/06/19 11:03:54 by ehwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	case_raerb(t_stack *a, t_stack *b, t_atob *atob, t_opcnt *opcnt)
{
	int	ra_cnt;
	int	rb_cnt;

	ra_cnt = atob->ra;
	rb_cnt = atob->rb;
	if (atob->ra == dbsize(a->head))
	{
		while (rb_cnt-- > 0)
			op_rrb(b, opcnt);
	}
	if (atob->rb == dbsize(b->head))
	{
		while (ra_cnt-- > 0)
			op_rra(a, opcnt);
	}
}

void	sub_ft(t_stack *a, t_stack *b, t_atob *atob, t_opcnt *opcnt)
{
	int	cnt;
	int	temp;

	if (atob->ra == dbsize(a->head) || atob->rb == dbsize(b->head))
		case_raerb(a, b, atob, opcnt);
	else if (atob->ra < atob->rb)
	{
		cnt = atob->ra;
		temp = atob->rb - atob->ra;
		while (cnt-- > 0)
			op_rrr(a, b, opcnt);
		while (temp-- > 0)
			op_rrb(b, opcnt);
	}
	else
	{
		cnt = atob->rb;
		temp = atob->ra - atob->rb;
		while (cnt-- > 0)
			op_rrr(a, b, opcnt);
		while (temp-- > 0)
			op_rra(a, opcnt);
	}
}

void	sub_btoa(t_stack *a, t_stack *b, t_opcnt *opcnt, t_atob *btoa)
{
	if (b->head->value < btoa->pivot1)
	{
		op_rb(b, opcnt);
		btoa->rb++;
	}
	else
	{
		op_pa(a, b, opcnt);
		btoa->pa++;
		if (a->head->value < btoa->pivot2)
		{
			op_ra(a, opcnt);
			btoa->ra++;
		}
	}
}

void	b_to_a(t_stack *a, t_stack *b, int size, t_opcnt *opcnt)
{
	t_atob	*btoa;

	if (size <= 3)
	{
		size_3_btoa(a, b, size, opcnt);
		return ;
	}
	btoa = malloc(sizeof(t_atob));
	init_atob(btoa);
	btoa->pivot1 = get_min_val(cpy_dblst(b->head, size), size);
	btoa->pivot2 = get_max_val(cpy_dblst(b->head, size), size);
	while (size-- > 0)
		sub_btoa(a, b, opcnt, btoa);
	a_to_b(a, b, btoa->pa - btoa->ra, opcnt);
	sub_ft(a, b, btoa, opcnt);
	a_to_b(a, b, btoa->ra, opcnt);
	b_to_a(a, b, btoa->rb, opcnt);
	free(btoa);
}
