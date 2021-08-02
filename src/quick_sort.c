/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehwangbo <ehwangbo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:21:50 by ehwangbo          #+#    #+#             */
/*   Updated: 2021/06/19 11:03:54 by ehwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(t_dblst *a, t_dblst *b)
{
	int	temp;

	temp = a->value;
	a->value = b->value;
	b->value = temp;
}

t_dblst	*partition(t_dblst *low, t_dblst *high)
{
	int		pivot;
	t_dblst	*i;
	t_dblst	*j;

	pivot = high->value;
	i = low->prev;
	j = low;
	while (j != high)
	{
		if (j->value <= pivot)
		{
			if (i == NULL)
				i = low;
			else
				i = i->next;
			swap(i, j);
		}
		j = j->next;
	}
	if (i == NULL)
		i = low;
	else
		i = i->next;
	swap(i, j);
	return (i);
}

void	quick_sort(t_dblst *low, t_dblst *high)
{
	t_dblst	*pivot;

	if (high != NULL && low != high && low != high->next)
	{
		pivot = partition(low, high);
		quick_sort(low, pivot->prev);
		quick_sort(pivot->next, high);
	}
}

void	set_quick_arr(t_dblst *start)
{
	t_dblst	*end;

	if (start->prev != start->next)
		end = start->prev;
	if (start->prev != NULL)
	{
		end->next = NULL;
		start->prev = NULL;
	}
}

void	quick_sort_arr(t_dblst *a)
{
	t_dblst	*q;

	q = a->prev;
	set_quick_arr(a);
	quick_sort(a, q);
	if (a->next == a->prev)
		return ;
	if (a && q)
	{
		a->prev = q;
		q->next = a;
	}
}
