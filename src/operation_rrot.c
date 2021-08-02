/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rrot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehwangbo <ehwangbo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:21:50 by ehwangbo          #+#    #+#             */
/*   Updated: 2021/06/19 11:03:54 by ehwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	op_rra(t_stack *a, t_opcnt *opcnt)
{
	reverse_rotate_stack(a);
	opcnt->rra++;
	ft_putstr_fd("rra\n", 1);
}

void	op_rrb(t_stack *b, t_opcnt *opcnt)
{
	reverse_rotate_stack(b);
	opcnt->rrb++;
	ft_putstr_fd("rrb\n", 1);
}

void	op_rrr(t_stack *a, t_stack *b, t_opcnt *opcnt)
{
	reverse_rotate_stack(a);
	reverse_rotate_stack(b);
	opcnt->rrr++;
	ft_putstr_fd("rrr\n", 1);
}
