/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 11:37:22 by ghaddad           #+#    #+#             */
/*   Updated: 2018/09/04 13:27:12 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include "../libft/includes/ft_printf.h"
# include <mlx.h>
# include <fcntl.h>

# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define ZOOM_IN 31
# define ZOOM_OUT 35
# define PLUS 69
# define MINUS 78
# define STEP .45
# define BLUE 0x000000FF
# define RED 0x00FF0000
# define YELLOW 0x00FFFF00
# define ORANGE 0x00ED7F10
# define DARK_RED 0x006D071A
# define WHITE 0x00FFFFFF
# define HAZEL 0x00955628
# define PARMA 0x00CFA0E9
# define PRASIN 0x004CA66B

typedef struct	s_grid
{
	int			width;
	int			height;
}				t_grid;

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_prog
{
	t_grid		*grid;
	t_point		*start;
	t_point		*point;
	char		*title;
	char		*map;
	int			**number_map;
	int			fd;
	int			win_w;
	int			win_h;
	void		*init;
	void		*window;
	void		*img;
	int			*array;
	int			bpp;
	int			s_l;
	int			endian;
	int			color;
	int			flag_s;
	int			a;
	int			b;
	int			x_step;
	int			y_step;
}				t_prog;

/*
** Gemeral functions
*/

void			usage(void);
int				invalid_chars(char *map);
void			clear_struct(t_prog *prog);
void			clear_lines(t_prog *prog);

/*
** Error functions
*/

void			error(t_prog *prog);
void			malloc_error(t_prog *prog);
void			no_map(t_prog *prog);
void			multi_maps(t_prog *prog);
void			invalid_map(t_prog *prog);
void			rectangle_map(t_prog *prog);
void			error_title(t_prog *prog);
void			size_error(t_prog *prog, int i);
void			map_too_big(t_prog *prog);
void			map_too_small(t_prog *prog);

/*
** Parsing functions
*/

void			fdf_parser(int argc, char **argv);
t_prog			*init_prog(t_prog *prog);
void			flag_h(t_prog *prog);
void			flag_s(t_prog *prog, char **argv, int i);
void			flag_t(t_prog *prog, char **argv, int i);
void			read_map(t_prog *prog);
void			convert_map(t_prog *prog);
int				count_lines(t_prog *prog);
int				count(t_prog *prog);

/*
**	Drawing functions
*/

void			fdf_draw(t_prog *p);
void			draw_img(t_prog *prog, int a, int b);
void			place_next_pixel(t_prog *prog, int i, int j);
void			special_events(t_prog *prog);
void			quit_program(t_prog *prog);
void			bresenham(t_prog *p, int x1, int y1);
void			put_pixel(t_prog *prog, int x, int y, int color);

#endif
