/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehwangbo <ehwangbo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:21:50 by ehwangbo          #+#    #+#             */
/*   Updated: 2021/06/19 11:03:54 by ehwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap_stack(t_stack *stack)
{
	int		temp;
	t_dblst	*p;

	if (dbsize(stack->head) <= 1)
		return ;
	if (stack->head)
	{
		p = stack->head;
		temp = p->value;
		p->value = (p->next)->value;
		(p->next)->value = temp;
	}
}

void	push_stack(t_stack *from, t_stack *to)
{
	if (dbsize(from->head) <= 0)
		return ;
	if (from->head)
		pop_push(from, to);
}

void	rotate_stack(t_stack *stack)
{
	if (dbsize(stack->head) >= 2)
		stack->head = stack->head->next;
}

void	reverse_rotate_stack(t_stack *stack)
{
	if (dbsize(stack->head) >= 2)
		stack->head = stack->head->prev;
}
