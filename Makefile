# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehwangbo <ehwangbo@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/10 12:04:42 by ehwangbo          #+#    #+#              #
#    Updated: 2021/05/10 18:24:13 by ehwangbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

NAME2		= checker

LIB_DIR	=	./lib/libft/

LIB_NAME	=	libft.a

SRCS	= ./src/a_to_b.c\
	./src/b_to_a.c\
	./src/bf_push_swap.c\
	./src/dblst.c\
	./src/error.c\
	./src/info_cnt.c\
	./src/main.c\
	./src/operation.c\
	./src/operation_rot.c\
	./src/operation_rrot.c\
	./src/pivot.c\
	./src/push_pop.c\
	./src/push_swap.c\
	./src/quick_sort.c\
	./src/set_stack.c\
	./src/size_case_3a.c\
	./src/size_case_3b.c\
	./src/size_range.c\
	./src/swap_op.c

SRCS2	= ./src/checker.c\
	./src/bf_push_swap.c\
	./src/dblst.c\
	./src/error.c\
	./src/info_cnt.c\
	./src/main.c\
	./src/operation_chk.c\
	./src/operation_rot_chk.c\
	./src/operation_rrot_chk.c\
	./src/pivot.c\
	./src/push_pop.c\
	./src/quick_sort.c\
	./src/set_stack.c\
	./src/swap_op.c

LIBS	= $(addprefix $(LIB_DIR), $(LIB_NAME))
OBJS	= $(SRCS:.c=.o)
OBJS2	= $(SRCS2:.c=.o)

CC		= gcc

CFLAGS		= -Wall -Werror -Wextra 

ARFLAGS		= rcs

RM		= rm -f

all : $(LIB_NAME) $(NAME) $(NAME2) 

$(LIB_NAME) :
	make -C $(LIB_DIR)

$(NAME) : $(SRCS) $(LIBS)
	$(CC) $(CFLAGS) $^ -o $@ 

$(NAME2) : $(SRCS2) $(LIBS)
	$(CC) $(CFLAGS) $^ -o $@

clean :
	make clean -C $(LIB_DIR)
	$(RM) $(OBJS) $(OBJS2) 

fclean : clean
	make fclean -C $(LIB_DIR)
	$(RM) $(NAME) $(NAME2)

re : fclean all

.PHONY : all clean fclean re
