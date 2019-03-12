# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabouce <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/29 17:41:33 by mabouce           #+#    #+#              #
#    Updated: 2019/03/10 15:24:23 by mabouce          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1				=	checker
NAME2				=	push_swap

SANITIZE			=	no
WEVERYTHING			=	no

ifeq ($(SANITIZE),yes)
	CC				=	gcc -Wall -Wextra -Werror -fsanitize=address \
						-Wall -Wextra -Werror
else ifeq ($(WEVERYTHING),yes)
	CC				=	gcc -Wall -Wextra -Weverything \
else
	CC				=	gcc -Wall -Wextra -Werror
endif

SRCS_CHECK_NAME		=	checker.c				\
						ft_check_input.c		\
						ft_apply_instru.c		\

SRCS_COMMON_NAME	=	ft_check_double.c	\
						ft_struct.c			\
						ft_error.c			\
						ft_print_piles.c	\
						ft_sa_sb_ss_pa_pb.c	\
						ft_ra_rb_rr.c		\
						ft_rra_rrb_rrr.c	\

SRCS_PUSH_NAME		=	push_swap.c					\
						ft_check_input_push_swap.c 	\
						ft_sort.c 					\
						ft_quick_sort.c				\
						ft_quick_sort_size_a.c		\
						ft_quick_sort_size_b.c		\
						ft_sort_pile_three.c 		\
						ft_sort_pile_two.c 			\
						ft_list_value.c				\
						ft_sa_sb_pa_pb_print.c		\
						ft_rrb_rra_rb_ra_print.c	\
						ft_ss_rr_rrr_print.c		\

INCLUDES_NAME		=	push_swap.h

SRCS_CHECK_PATH		=	./srcs/checkerdir/
SRCS_COMMON_PATH	=	./srcs/common/
SRCS_PUSH_PATH		=	./srcs/pushswapdir/
INCLUDES_PATH		=	./includes/

OBJS_CHECK_PATH 	=	./objs/objs_check/
OBJS_COMMON_PATH 	=	./objs/objs_common/
OBJS_PUSH_PATH 		=	./objs/objs_push/

MINIPRINTF			=	./miniprintf/
LIBFTINCLUDES		=	./libft/includes/
MINIPRINTFINCLUDES	=	./miniprintf/includes/
INCLUDES  			=	$(addprefix $(INCLUDES_PATH), $(INCLUDES_NAME))

SRCS_CHECK			=	$(addprefix $(SRCS_CHECK_PATH), $(SRCS_CHECK_NAME))
SRCS_COMMON			=	$(addprefix $(SRCS_COMMON_PATH), $(SRCS_COMMON_NAME))
SRCS_PUSH			=	$(addprefix $(SRCS_PUSH_PATH), $(SRCS_PUSH_NAME))

OBJS_CHECK			=	$(patsubst $(SRCS_CHECK_PATH)%.c, \
						$(OBJS_CHECK_PATH)%.o, $(SRCS_CHECK))
OBJS_COMMON			=	$(patsubst $(SRCS_COMMON_PATH)%.c, \
						$(OBJS_COMMON_PATH)%.o, $(SRCS_COMMON))
OBJS_PUSH			=	$(patsubst $(SRCS_PUSH_PATH)%.c,	\
						$(OBJS_PUSH_PATH)%.o, $(SRCS_PUSH))


.PHONY				=	all $(NAME1) $(NAME2) clean fclean re

_UNDER=$'\x1b[4m$'
_GREEN=$'\x1b[32m$'
_YELLOW=$'\x1b[33m$'
_WHITE=$'\x1b[37m$'
_END=$'\x1b[0m$'
_BOLD=$'\x1b[1m$'

all: $(NAME1) $(NAME2)


$(NAME1): $(OBJS_CHECK) $(OBJS_COMMON)
	@echo "\n\n"
	@echo "$(_WHITE)====================================================$(_END)"
	@echo "$(_YELLOW)		COMPILING MINIPRINTF$(_END)"
	@echo "$(_WHITE)====================================================$(_END)"
	@echo "\n\n"
	@make -C $(MINIPRINTF) -j
	@cp $(MINIPRINTF)/libftminiprintf.a .
	@echo "$(_WHITE)====================================================$(_END)"
	@echo "$(_YELLOW)		COMPILING CHECKER$(_END)"
	@echo "$(_WHITE)====================================================$(_END)"
	@$(CC) -o $(NAME1) $(OBJS_CHECK) $(OBJS_COMMON) libftminiprintf.a
	@echo "\n$(_WHITE)$(_BOLD)$@\t$(_END)$(_GREEN)[OK]\n$(_END)"
ifeq ($(SANITIZE),yes)
	@echo "Génération en mode sanitize"
else ifeq ($(WEVERYTHING),yes)
	@echo "Génération en mode weverything"
else
	@echo "Génération en mode release"
endif

$(NAME2): $(OBJS_PUSH) $(OBJS_COMMON)
	@echo "\n\n"
	@echo "$(_WHITE)====================================================$(_END)"
	@echo "$(_YELLOW)		COMPILING MINIPRINTF$(_END)"
	@echo "$(_WHITE)====================================================$(_END)"
	@echo "\n\n"
	@make -C $(MINIPRINTF) -j
	@cp $(MINIPRINTF)/libftminiprintf.a .
	@echo "$(_WHITE)====================================================$(_END)"
	@echo "$(_YELLOW)		COMPILING PUSH_SWAP$(_END)"
	@echo "$(_WHITE)====================================================$(_END)"
	@$(CC) -o $(NAME2) $(OBJS_PUSH) $(OBJS_COMMON) libftminiprintf.a
	@echo "\n$(_WHITE)$(_BOLD)$@\t$(_END)$(_GREEN)[OK]\n$(_END)"
ifeq ($(SANITIZE),yes)
	@echo "Génération en mode sanitize"
else ifeq ($(WEVERYTHING),yes)
	@echo "Génération en mode weverything"
else
	@echo "Génération en mode release"
endif

clean:
	@echo "$(_RED)"
	rm -rf $(OBJS_CHECK) $(OBJS_COMMON) $(OBJS_PUSH)
	make clean -C $(MINIPRINTF)
	rm -rf ./objs

fclean:	clean
	@echo "$(_YELLOW)"
	rm -f $(NAME1) $(NAME2)
	rm -f libftminiprintf.a
	make fclean -C $(MINIPRINTF)

re:	fclean all

$(OBJS_CHECK_PATH)%.o: $(SRCS_CHECK_PATH)%.c $(INCLUDES)
	@mkdir -p ./objs/objs_check
	@$(CC) -I $(MINIPRINTFINCLUDES) -I $(LIBFTINCLUDES) \
		-I $(INCLUDES_PATH) -c $< -o $@
	@echo "$(_END)$(_GREEN)[OK]\t$(_UNDER)$(_YELLOW)	\
		COMPILE :$(_END)$(_BOLD)$(_WHITE)\t$<"

$(OBJS_COMMON_PATH)%.o: $(SRCS_COMMON_PATH)%.c $(INCLUDES)
	@mkdir -p ./objs/objs_common
	@$(CC) -I $(MINIPRINTFINCLUDES) -I $(LIBFTINCLUDES) \
		-I $(INCLUDES_PATH) -c $< -o $@
	@echo "$(_END)$(_GREEN)[OK]\t$(_UNDER)$(_YELLOW)	\
		COMPILE :$(_END)$(_BOLD)$(_WHITE)\t$<"

$(OBJS_PUSH_PATH)%.o: $(SRCS_PUSH_PATH)%.c $(INCLUDES)
	@mkdir -p ./objs/objs_push
	@$(CC) -I $(MINIPRINTFINCLUDES) -I $(LIBFTINCLUDES)	\
		-I $(INCLUDES_PATH) -c $< -o $@
	@echo "$(_END)$(_GREEN)[OK]\t$(_UNDER)$(_YELLOW)	\
		COMPILE :$(_END)$(_BOLD)$(_WHITE)\t$<"
