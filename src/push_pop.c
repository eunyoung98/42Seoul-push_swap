/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_pop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehwangbo <ehwangbo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:21:50 by ehwangbo          #+#    #+#             */
/*   Updated: 2021/06/19 11:03:54 by ehwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_argv(t_stack *a, char *argv)
{
	dblst_add_back(&a->head, dblst_new(ft_atoi(argv)));
}

void	push(t_stack *a, t_dblst *new)
{
	dblst_add_front(&a->head, new);
}

t_dblst	*stack_pop(t_dblst **lst)
{
	t_dblst	*temp;

	if (!lst)
		return (NULL);
	temp = *lst;
	if ((*lst)->next == (*lst) && (*lst)->prev == (*lst))
		*lst = NULL;
	else
	{
		*lst = temp->next;
		temp->next = temp;
		(*lst)->prev = temp->prev;
		temp->prev = temp;
		((*lst)->prev)->next = *lst;
	}
	return (temp);
}

void	pop_push(t_stack *from, t_stack *to)
{
	if (dbsize(from->head) == 0)
		return ;
	dblst_add_front(&to->head, stack_pop(&from->head));
}
