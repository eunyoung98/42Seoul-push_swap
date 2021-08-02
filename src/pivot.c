/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehwangbo <ehwangbo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:21:50 by ehwangbo          #+#    #+#             */
/*   Updated: 2021/06/19 11:03:54 by ehwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_dblst	*cpy_dblst(t_dblst *a, int n)
{
	t_dblst	*curr;
	t_dblst	*cpy;
	int		i;

	cpy = NULL;
	curr = a;
	i = 0;
	while (i++ < n - 1 && curr->next != a)
	{
		dblst_add_back(&cpy, dblst_new(curr->value));
		curr = curr->next;
	}
	dblst_add_back(&cpy, dblst_new(curr->value));
	return (cpy);
}

t_dblst	*dblst_nth(t_dblst *a, int n)
{
	t_dblst	*curr;
	int		i;

	i = 0;
	if (a == NULL || dbsize(a) < n)
		return (0);
	curr = a;
	while (i < n)
	{
		curr = curr->next;
		i++;
	}
	return (curr);
}

int	get_min_val(t_dblst *head, int count)
{
	int	value;

	quick_sort_arr(head);
	if (count <= 7)
		value = (dblst_nth(head, count / 2 - 1))->value;
	else
		value = (dblst_nth(head, count / 3 + 1))->value;
	dbclear(head);
	return (value);
}

int	get_max_val(t_dblst *head, int count)
{
	int	value;

	quick_sort_arr(head);
	if (count <= 7)
		value = (dblst_nth(head, count / 2))->value;
	else
		value = (dblst_nth(head, 2 * count / 3 + 1))->value;
	dbclear(head);
	return (value);
}
