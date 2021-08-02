/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehwangbo <ehwangbo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:21:50 by ehwangbo          #+#    #+#             */
/*   Updated: 2021/07/15 12:06:09 by ehwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft/libft.h"
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

typedef struct s_opcnt
{
	int			sa;
	int			sb;
	int			ss;
	int			pa;
	int			pb;
	int			ra;
	int			rb;
	int			rr;
	int			rra;
	int			rrb;
	int			rrr;
}			t_opcnt;

typedef struct s_atob
{
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	pivot1;
	int	pivot2;
}			t_atob;

void	sub_atob(t_stack *a, t_stack *b, t_opcnt *opcnt, t_atob *atob);
void	init_atob(t_atob *atob);
void	a_to_b(t_stack *a, t_stack *b, int size, t_opcnt *opcnt);
void	case_raerb(t_stack *a, t_stack *b, t_atob *atob, t_opcnt *opcnt);
void	sub_ft(t_stack *a, t_stack *b, t_atob *atob, t_opcnt *opcnt);
void	sub_btoa(t_stack *a, t_stack *b, t_opcnt *opcnt, t_atob *btoa);
void	b_to_a(t_stack *a, t_stack *b, int size, t_opcnt *opcnt);

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

void	init_cnt(t_opcnt *opcnt);
int		sum_cnt(t_opcnt *opcnt);

int		parse(int argc, char **argv);
char	**r_arr(char const *s, char c, char **result, int res_idx);
char	**insert_arg(int argc, char **argv, char **arg);
void	last_free(int argc, char **argv, char **arg);
int		before_atoi(char *str);
int		main(int argc, char **argv);

void	op_sa(t_stack *a, t_opcnt *opcnt);
void	op_sb(t_stack *b, t_opcnt *opcnt);
void	op_ss(t_stack *a, t_stack *b, t_opcnt *opcnt);
void	op_pa(t_stack *a, t_stack *b, t_opcnt *opcnt);
void	op_pb(t_stack *a, t_stack *b, t_opcnt *opcnt);

void	op_ra(t_stack *a, t_opcnt *opcnt);
void	op_rb(t_stack *b, t_opcnt *opcnt);
void	op_rr(t_stack *a, t_stack *b, t_opcnt *opcnt);

void	op_rra(t_stack *a, t_opcnt *opcnt);
void	op_rrb(t_stack *b, t_opcnt *opcnt);
void	op_rrr(t_stack *a, t_stack *b, t_opcnt *opcnt);

t_dblst	*cpy_dblst(t_dblst *a, int n);
t_dblst	*dblst_nth(t_dblst *a, int n);
int		get_min_val(t_dblst *head, int count);
int		get_max_val(t_dblst *head, int count);

void	push_argv(t_stack *a, char *argv);
void	push(t_stack *a, t_dblst *new);
t_dblst	*stack_pop(t_dblst **lst);
void	pop_push(t_stack *from, t_stack *to);

void	list_init(t_dblst *head);
void	print(t_dblst *a);
void	pre_stack(t_stack *a, t_stack *b);
void	before_push_swap(int len, char **argv);

void	swap(t_dblst *a, t_dblst *b);
t_dblst	*partition(t_dblst *low, t_dblst *high);
void	quick_sort(t_dblst *low, t_dblst *high);
void	set_quick_arr(t_dblst *start);
void	quick_sort_arr(t_dblst *a);

void	init_stack(t_stack *stack);
void	clear_stack(t_stack *stack);

void	size_3_a(t_stack *a, t_opcnt *opcnt);
void	size_3_atob(t_stack *a, int size, t_opcnt *opcnt);
void	size_3_b(t_stack *a, t_stack *b, t_opcnt *opcnt);
void	size_3_btoa(t_stack *a, t_stack *b, int size, t_opcnt *opcnt);

void	case_a120(t_stack *a, t_opcnt *opcnt);
void	case_a201(t_stack *a, t_opcnt *opcnt);
void	case_a210(t_stack *a, t_opcnt *opcnt);

void	case_b012(t_stack *a, t_stack *b, t_opcnt *opcnt);
void	case_b021(t_stack *a, t_stack *b, t_opcnt *opcnt);
void	case_b102(t_stack *a, t_stack *b, t_opcnt *opcnt);
void	case_b120(t_stack *a, t_stack *b, t_opcnt *opcnt);
void	case_b201(t_stack *a, t_stack *b, t_opcnt *opcnt);

void	swap_stack(t_stack *stack);
void	push_stack(t_stack *from, t_stack *to);
void	rotate_stack(t_stack *stack);
void	reverse_rotate_stack(t_stack *stack);

#endif
