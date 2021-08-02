/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_cnt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehwangbo <ehwangbo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:21:50 by ehwangbo          #+#    #+#             */
/*   Updated: 2021/07/14 10:41:05 by ehwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	init_cnt(t_opcnt *opcnt)
{
	opcnt->sa = 0;
	opcnt->sb = 0;
	opcnt->ss = 0;
	opcnt->pa = 0;
	opcnt->pb = 0;
	opcnt->ra = 0;
	opcnt->rb = 0;
	opcnt->rr = 0;
	opcnt->rra = 0;
	opcnt->rrb = 0;
	opcnt->rrr = 0;
}

int	sum_cnt(t_opcnt *opcnt)
{
	int	sum;

	sum = 0;
	sum += opcnt->sa;
	sum += opcnt->sb;
	sum += opcnt->ss;
	sum += opcnt->pa;
	sum += opcnt->pb;
	sum += opcnt->ra;
	sum += opcnt->rb;
	sum += opcnt->rr;
	sum += opcnt->rra;
	sum += opcnt->rrb;
	sum += opcnt->rrr;
	return (sum);
}
