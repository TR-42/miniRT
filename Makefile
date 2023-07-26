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
	_load_amb_light.c\
	_load_camera.c\
	_load_cylinder.c\
	_load_light.c\
	_load_plane.c\
	_load_sphere.c\
	_parse_rgb.c\
	_parse_vec3.c\
	load_rt.c\
	loader.c\

SRCS_UTILS	:=\
	arrlen2d.c\
	error_exit.c\
	error_retint.c\
	free2darr.c\
	ft_strtod.c\
	try_str_to_byte.c\
	try_strtod.c\

SRCS_VECT3D :=\
	vec3_.c\
	vec3_add.c\
	vec3_mul.c\
	vec3_sub.c\

SRCS_NOMAIN	:= \
	$(addprefix loader/, $(SRCS_LOADER))\
	$(addprefix utils/, $(SRCS_UTILS))\
	$(addprefix vect3d/, $(SRCS_VECT3D))\

HEADERS_DIR		:=	./headers

SRCS_BASE_DIR	:=	./srcs

OBJ_DIR	:=	./objs
OBJS_NOMAIN	:=	$(addprefix $(OBJ_DIR)/, $(SRCS_NOMAIN:.c=.o))
OBJS_MAIN	:=	$(addprefix $(OBJ_DIR)/, $(SRCS_MAIN:.c=.o))
OBJS	:=	$(OBJS_NOMAIN) $(OBJS_MAIN)
DEPS	:=	$(addprefix $(OBJ_DIR)/, $(OBJS:.o=.d))

TEST_DIR	:=	.tests

LIBFT_DIR	:=	./libft
LIBFT	:=	$(LIBFT_DIR)/libft.a
LIBFT_MAKE	:=	make -C $(LIBFT_DIR)

MLX_DIR	:=	./minilibx
MLX	:=	$(MLX_DIR)/libmlx.a
MLX_MAKE	:=	make -C $(MLX_DIR)

LIB_NOMAIN	:=	lib_nomain.a

override CFLAGS	+=	-Wall -Wextra -Werror -MMD -MP
INCLUDES	:=	-I $(HEADERS_DIR) -I $(LIBFT_DIR) -I $(MLX_DIR)
LIB_LINK	:=	-lm -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -L. -l_nomain

CC		:=	cc

all:	$(NAME)
bonus:	$(NAME)

$(NAME):	$(OBJS_MAIN) $(LIBFT) $(MLX) $(LIB_NOMAIN)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $(OBJS_MAIN) $(LIB_LINK)
debug: clean_local_obj
	make CFLAGS='-DDEBUG -g'
faddr: clean_local_obj
	make CFLAGS='-g -fsanitize=address'
fleak: clean_local_obj
	make CFLAGS='-g -fsanitize=leak'

$(OBJ_DIR)/%.o:	$(SRCS_BASE_DIR)/%.c
	@test -d '$(dir $@)' || mkdir -p '$(dir $@)'
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

$(LIB_NOMAIN): $(OBJS_NOMAIN)
	ar rcs $@ $^

$(LIBFT):
	$(LIBFT_MAKE)
$(MLX):
	$(MLX_MAKE) 2> mlx_error.log

bonus:	$(NAME)

clean_local_obj:
	rm -f $(OBJS)

clean_local:
	rm -rf $(OBJ_DIR)

fclean_local: clean_local
	rm -f $(NAME) $(LIB_NOMAIN)

clean: clean_local
	$(LIBFT_MAKE) clean

fclean:	fclean_local
	$(LIBFT_MAKE) fclean
	$(MLX_MAKE) clean

re:	fclean all

norm:
	norminette $(HEADERS_DIR) $(SRCS_BASE_DIR)

-include $(DEPS)

.PHONY:	clean_local bonus norm

# region tests

CXX := c++

T_STRTOD	:=	t_strtod
T_LOAD_RT	:=	t_load_rt
T_LOADER_AUTO	:=	t_loader_auto

TESTS	:=\
	$(T_STRTOD)\
	$(T_LOAD_RT)\
	$(T_LOADER_AUTO)\

$(T_STRTOD):	.tests/$(T_STRTOD).c $(LIB_NOMAIN)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $< $(LIB_LINK)
$(T_LOAD_RT):	.tests/$(T_LOAD_RT).c $(LIB_NOMAIN)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $< $(LIB_LINK)
$(T_LOADER_AUTO):	.tests/$(T_LOADER_AUTO).cpp $(LIB_NOMAIN)
	$(CXX) $(CFLAGS) -g -fsanitize=address $(INCLUDES) -o $@ $< $(LIB_LINK)

tclean:
	rm -f $(TESTS) $(addsuffix .d,$(TESTS))

.PHONY: tclean

# endregion tests
