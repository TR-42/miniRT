# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/03 18:44:27 by kfujita           #+#    #+#              #
#    Updated: 2023/08/02 00:55:12 by kfujita          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	miniRT

SRCS_MAIN	:= \
	main.c \

SRCS_CAMERA	:=\
	cam_get_ray.c\

SRCS_CANVAS	:= \
	dispose.c\
	init.c\
	set_color.c\
	to_png.c\

SRCS_INLINE_IMG	:= \
	print_inline_img.c \

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
	print_load_err.c\

SRCS_RAY	:=\
	at.c\
	hit_any.c\
	init_dst.c\
	to_rgb.c\

SRCS_SPHERE	:=\
	sphere_color.c\
	sphere_hit.c\
	sphere_init.c\

SRCS_UTILS	:=\
	arrlen2d.c\
	base64_encode.c\
	brend_rgb.c\
	error_exit.c\
	error_retint.c\
	free2darr.c\
	ft_strtod.c\
	powf.c\
	try_str_to_byte.c\
	try_strtod.c\

SRCS_VECT3D :=\
	vec3_.c\
	vec3_add.c\
	vec3_cross.c\
	vec3_div.c\
	vec3_dot.c\
	vec3_len.c\
	vec3_mul.c\
	vec3_normalize.c\
	vec3_sub.c\

SRCS_NOMAIN	:= \
	$(addprefix camera/, $(SRCS_CAMERA))\
	$(addprefix canvas/, $(SRCS_CANVAS))\
	$(addprefix inline_img/, $(SRCS_INLINE_IMG))\
	$(addprefix loader/, $(SRCS_LOADER))\
	$(addprefix ray/, $(SRCS_RAY))\
	$(addprefix sphere/, $(SRCS_SPHERE))\
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

ifneq (,$(findstring -DENABLE_PNG, $(CFLAGS)))
# os switch ref: https://qiita.com/y-vectorfield/items/5e117e090ed38422de6b
OS_TYPE	:= $(shell uname -s)
ifeq ($(OS_TYPE),Darwin)
	LIBPNG_DIR = $(shell brew --prefix libpng)
	INCLUDES += -I$(LIBPNG_DIR)/include
	LIB_LINK += -L$(LIBPNG_DIR)/lib
endif

	LIB_LINK	+=	-lpng
endif

CC		:=	cc

all:	$(NAME)
bonus:	$(NAME)

$(NAME):	$(OBJS_MAIN) $(LIBFT) $(MLX) $(LIB_NOMAIN)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $(OBJS_MAIN) $(LIB_LINK)
png:
	rm -f $(OBJ_DIR)/canvas/to_png.o
	make CFLAGS='-DENABLE_PNG'
	mv $(NAME) $@
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

.PHONY:	clean_local bonus norm png

# region tests

CXX := c++

T_STRTOD	:=	t_strtod
T_LOAD_RT	:=	t_load_rt
T_LOADER_AUTO	:=	t_loader_auto
T_INLINE_IMG	:=	t_inline_img

TESTS	:=\
	$(T_STRTOD)\
	$(T_LOAD_RT)\
	$(T_LOADER_AUTO)\
	$(T_INLINE_IMG)\

$(T_STRTOD):	.tests/$(T_STRTOD).c $(LIB_NOMAIN)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $< $(LIB_LINK)
$(T_LOAD_RT):	.tests/$(T_LOAD_RT).c $(LIB_NOMAIN)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $< $(LIB_LINK)
$(T_LOADER_AUTO):	.tests/$(T_LOADER_AUTO).cpp $(LIB_NOMAIN)
	$(CXX) $(CFLAGS) -g -fsanitize=address $(INCLUDES) -o $@ $< $(LIB_LINK)
$(T_INLINE_IMG):	.tests/$(T_INLINE_IMG).cpp $(LIB_NOMAIN)
	$(CXX) $(CFLAGS) $(INCLUDES) -o $@ $< $(LIB_LINK)

tclean:
	rm -f $(TESTS) $(addsuffix .d,$(TESTS))

.PHONY: tclean

# endregion tests
