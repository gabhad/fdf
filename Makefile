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
				place_next_pixel.c \
				special_events.c \
				quit_program.c
SRCS_PATH =		srcs/
SRCS = 			$(addprefix $(SRCS_PATH), $(SRC_FILES))

CC =			gcc
FLAGS =			-Wall -Wextra -Werror

MLX =			-lmlx -framework OpenGL -framework Appkit

LIBFT_PATH =	libft/
LIBFT_INCL =	$(addprefix $(LIBFT_PATH), includes)
LIBFT =			$(addprefix $(LIBFT_PATH), libft.a)

OBJS_PATH =		objects/
OBJS_NAME =		$(patsubst %.c, $(OBJS_PATH)%.o, $(SRC_FILES))

HEADER_FILES =	fdf.h
INCLUDES_PATH = includes/
INCL = $(addprefix $(INCLUDES_PATH),$(HEADER_FILES))

all: $(NAME)

libftcomp:
	@make -C $(LIBFT_PATH)

$(NAME): libftcomp $(OBJS_PATH) $(OBJS_NAME)
	@$(CC) -o $(NAME) $(OBJS_PATH)*.o $(LIBFT) $(MLX)
	@echo '\033[0;32m'***Compiled***'\033[0m'

$(OBJS_PATH):
	@mkdir $(OBJS_PATH) 2> /dev/null || true

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c $(INCL)
			@$(CC) $(FLAGS) -c $< -o $@ -I $(INCLUDES_PATH) -I $(LIBFT_INCL)

clean:
	@/bin/rm -rf $(OBJS_PATH)
	@make -C libft/ clean 2> /dev/null || true
	@echo '\033[0;31m'***Deleted objects***'\033[0m'

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C libft/ fclean 2> /dev/null || true
	@echo '\033[0;31m'***Deleted objects and library***'\033[0m' 

re: fclean all

.PHONY: all, clean, fclean, re
