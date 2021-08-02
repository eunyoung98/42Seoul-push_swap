/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_chk.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehwangbo <ehwangbo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:21:50 by ehwangbo          #+#    #+#             */
/*   Updated: 2021/07/14 10:41:46 by ehwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	op_sa_chk(t_stack *a)
{
	swap_stack(a);
}

void	op_sb_chk(t_stack *b)
{
	swap_stack(b);
}

void	op_ss_chk(t_stack *a, t_stack *b)
{
	swap_stack(a);
	swap_stack(b);
}

void	op_pa_chk(t_stack *a, t_stack *b)
{
	push_stack(b, a);
}

void	op_pb_chk(t_stack *a, t_stack *b)
{
	push_stack(a, b);
}
