/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehwangbo <ehwangbo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:21:50 by ehwangbo          #+#    #+#             */
/*   Updated: 2021/07/15 12:06:33 by ehwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../lib/libft/libft.h"
# include "../lib/libft/get_next_line.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_dblst
{
	int				value;
	struct s_dblst	*prev;
	struct s_dblst	*next;
}			t_dblst;

typedef struct s_stack
{
	t_dblst		*head;
}			t_stack;

void	gnl(t_stack *a, t_stack *b, t_stack *order);
int		operate_op(char **line, t_stack *a, t_stack *b);
void	last_free(int argc, char **argv, char **arg);

t_dblst	*dblst_new(int value);
void	dblst_add_front(t_dblst **lst, t_dblst *new);
void	dblst_add_back(t_dblst **lst, t_dblst *new);
void	dbclear(t_dblst *head);
int		dbsize(t_dblst *a);

int		emptystr(int i, char **argv);
int		is_zero(char **argv, int i);
int		chk_dup(char **argv, int i);
int		chk_asc(int len, char **argv);
int		check_arr(char **argv, int len);
void	chk_res(t_dblst *a, t_dblst *b, t_dblst *order);
int		before_atoi(char *str);

int		parse(int argc, char **argv);
char	**r_arr(char const *s, char c, char **result, int res_idx);
char	**insert_arg(int argc, char **argv, char **arg);
void	checker_push_swap(int len, char **argv);
int		main(int argc, char **argv);

void	op_sa_chk(t_stack *a);
void	op_sb_chk(t_stack *b);
void	op_ss_chk(t_stack *a, t_stack *b);
void	op_pa_chk(t_stack *a, t_stack *b);
void	op_pb_chk(t_stack *a, t_stack *b);

void	op_ra_chk(t_stack *a);
void	op_rb_chk(t_stack *b);
void	op_rr_chk(t_stack *a, t_stack *b);

void	op_rra_chk(t_stack *a);
void	op_rrb_chk(t_stack *b);
void	op_rrr_chk(t_stack *a, t_stack *b);

t_dblst	*cpy_dblst(t_dblst *a, int n);

void	push_argv(t_stack *a, char *argv);
void	push(t_stack *a, t_dblst *new);
t_dblst	*stack_pop(t_dblst **lst);
void	pop_push(t_stack *from, t_stack *to);

void	list_init(t_dblst *head);
void	pre_stack(t_stack *a, t_stack *b);

void	swap(t_dblst *a, t_dblst *b);
t_dblst	*partition(t_dblst *low, t_dblst *high);
void	quick_sort(t_dblst *low, t_dblst *high);
void	set_quick_arr(t_dblst *start);
void	quick_sort_arr(t_dblst *a);

void	init_stack(t_stack *stack);
void	clear_stack(t_stack *stack);

void	swap_stack(t_stack *stack);
void	push_stack(t_stack *from, t_stack *to);
void	rotate_stack(t_stack *stack);
void	reverse_rotate_stack(t_stack *stack);

#endif
