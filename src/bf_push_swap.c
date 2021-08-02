/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehwangbo <ehwangbo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:21:50 by ehwangbo          #+#    #+#             */
/*   Updated: 2021/06/19 11:03:54 by ehwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	list_init(t_dblst *head)
{
	head->prev = head;
	head->next = head;
}

void	pre_stack(t_stack *a, t_stack *b)
{
	if (!a || !b)
	{
		ft_putstr_fd("Malloc error\n", 2);
		exit(1);
	}
	init_stack(a);
	init_stack(b);
}
