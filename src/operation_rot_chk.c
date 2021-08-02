/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rot_chk.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehwangbo <ehwangbo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:21:50 by ehwangbo          #+#    #+#             */
/*   Updated: 2021/06/19 11:03:54 by ehwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	op_ra_chk(t_stack *a)
{
	rotate_stack(a);
}

void	op_rb_chk(t_stack *b)
{
	rotate_stack(b);
}

void	op_rr_chk(t_stack *a, t_stack *b)
{
	rotate_stack(a);
	rotate_stack(b);
}
