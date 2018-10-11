# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/06 08:50:17 by ghaddad           #+#    #+#              #
#    Updated: 2018/09/06 08:50:20 by ghaddad          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			fdf

SRC_FILES =		fdf.c \
				bresenham.c \
				clear_struct.c \
				convert_map.c \
				error.c \
				error2.c \
				fdf_draw.c \
				fdf_parser.c \
				flag_h.c \
				flag_s.c \
				flag_t.c \
				init_prog.c \
				map_checker.c \
				read_map.c \
				print_map.c \
				place_next_pixel.c \
				special_events.c \
				quit_program.c
SRCS_PATH =		srcs/
SRCS = 			$(addprefix $(SRCS_PATH), $(SRC_FILES))

CC =			gcc
FLAGS =			-Wall -Wextra -Werror

MLX_PATH =		minilibx/
MLX =			-L$(MLX_PATH) -lmlx -framework OpenGL -framework Appkit

LIBFT_PATH =	libft/
LDLIBS =		-lft
LIBFT_INCL =	$(addprefix $(LIBFT_PATH), includes)
LIBFT =			$(addprefix $(LIBFT_PATH), libft.a)

OBJS_PATH =		objects/
OBJS_NAME =		$(patsubst %.c, $(OBJS_PATH)%.o, $(SRC_FILES))

HEADER_FILES =	fdf.h
INCLUDES_PATH = includes/
INCL = $(addprefix $(INCLUDES_PATH),$(HEADER_FILES))

all: $(NAME)

$(NAME): $(OBJS_PATH) $(OBJS_NAME) 
	make -C $(LIBFT_PATH)
	make -C $(MLX_PATH)
	$(CC) $(OBJS_PATH)*.o -L$(LIBFT_PATH) $(LDLIBS) $(MLX) -o $(NAME)

$(OBJS_PATH):
	@mkdir $(OBJS_PATH) 2> /dev/null || true

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c $(INCL)
	$(CC) $(FLAGS) -c $< -o $@ -I $(INCLUDES_PATH) -I $(LIBFT_INCL)

clean:
	make clean -C $(LIBFT_PATH)
	make clean -C $(MLX_PATH)
	rm -fv $(OBJS_NAME)
	@rmdir $(OBJS_PATH) 2> /dev/null || true

fclean: clean
	make fclean -C libft/
	rm -fv $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
