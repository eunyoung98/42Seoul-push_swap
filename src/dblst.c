/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dblst.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehwangbo <ehwangbo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:21:50 by ehwangbo          #+#    #+#             */
/*   Updated: 2021/06/19 11:03:54 by ehwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_dblst	*dblst_new(int value)
{
	t_dblst	*new;

	new = (t_dblst *)malloc(sizeof(t_dblst));
	if (new == NULL)
	{
		ft_putstr_fd("malloc error\n", 2);
		return (NULL);
	}
	new->value = value;
	new->prev = new;
	new->next = new;
	return (new);
}

void	dblst_add_front(t_dblst **lst, t_dblst *new)
{
	if (!new)
		return ;
	if (*lst)
	{
		new->prev = (*lst)->prev;
		(*lst)->prev->next = new;
		new->next = *lst;
		(*lst)->prev = new;
	}
	*lst = new;
}

void	dblst_add_back(t_dblst **lst, t_dblst *new)
{
	if (!new)
		return ;
	if (*lst)
	{
		new->prev = (*lst)->prev;
		(*lst)->prev->next = new;
		new->next = *lst;
		(*lst)->prev = new;
	}
	else
		*lst = new;
}

void	dbclear(t_dblst *head)
{
	t_dblst	*curr;
	t_dblst	*next;

	curr = head;
	if (curr)
	{
		while (curr)
		{
			next = curr->next;
			free(curr);
			curr = next;
			if (curr == head)
				break ;
		}
	}
}

int	dbsize(t_dblst *a)
{
	t_dblst	*p;
	int		len;

	len = 0;
	p = a;
	while (a)
	{
		len++;
		a = a->next;
		if (p == a)
			break ;
	}
	return (len);
}
