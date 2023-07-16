# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/03 18:44:27 by kfujita           #+#    #+#              #
#    Updated: 2023/07/08 19:51:41 by kfujita          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	miniRT

SRCS_MAIN	:= \
	main.c \

SRCS_LOADER	:=\
	_errors.c\
	_load_amb_light.c\
	_parse_rgb.c\
	_parse_vec3.c\
	loader.c\

SRCS_UTILS	:=\
	arrlen2d.c\
	error_exit.c\
	free2darr.c\
	ft_strtod.c\
	try_str_to_byte.c\
	try_strtod.c\

SRCS_NOMAIN	:= \
	$(addprefix loader/, $(SRCS_LOADER))\
	$(addprefix utils/, $(SRCS_UTILS))\

HEADERS_DIR		:=	./headers

SRCS_BASE_DIR	:=	./srcs

OBJ_DIR	:=	./objs
OBJS_NOMAIN	:=	$(addprefix $(OBJ_DIR)/, $(SRCS_NOMAIN:.c=.o))
OBJS	:=	$(OBJS_NOMAIN) $(addprefix $(OBJ_DIR)/, $(SRCS_MAIN:.c=.o))
DEPS	:=	$(addprefix $(OBJ_DIR)/, $(OBJS:.o=.d))

TEST_DIR	:=	.tests

LIBFT_DIR	:=	./libft
LIBFT	:=	$(LIBFT_DIR)/libft.a
LIBFT_MAKE	:=	make -C $(LIBFT_DIR)

override CFLAGS	+=	-Wall -Wextra -Werror -MMD -MP
INCLUDES	:=	-I $(HEADERS_DIR) -I $(LIBFT_DIR)
LIB_LINK	:=	-lm

CC		:=	cc

all:	$(NAME)
bonus:	$(NAME)

$(NAME):	$(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^ $(LIB_LINK)
debug: clean_local_obj
	make CFLAGS='-DDEBUG -g'
faddr: clean_local_obj
	make CFLAGS='-g -fsanitize=address'
fleak: clean_local_obj
	make CFLAGS='-g -fsanitize=leak'

$(OBJ_DIR)/%.o:	$(SRCS_BASE_DIR)/%.c
	@test -d '$(dir $@)' || mkdir -p '$(dir $@)'
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

$(LIBFT):
	$(LIBFT_MAKE)

bonus:	$(NAME)

clean_local_obj:
	rm -f $(OBJS)

clean_local:
	rm -rf $(OBJ_DIR)

fclean_local: clean_local
	rm -f $(NAME)

clean: clean_local
	$(LIBFT_MAKE) clean

fclean:	fclean_local
	$(LIBFT_MAKE) fclean

re:	fclean all

norm:
	norminette $(HEADERS_DIR) $(SRCS_BASE_DIR)

-include $(DEPS)

.PHONY:	clean_local bonus norm

# region tests

T_STRTOD	:=	t_strtod

TESTS	:=\
	$(T_STRTOD)\

$(T_STRTOD):	.tests/$(T_STRTOD).c $(OBJS_NOMAIN) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^ $(LIB_LINK)

tclean:
	rm -f $(TESTS) $(addsuffix .d,$(TESTS))

.PHONY: tclean

# endregion tests
