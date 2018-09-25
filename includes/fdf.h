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
# include "../libft/includes/libft.h"
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
# define STEP .3
# define BLUE 0x000000FF
# define RED 0x00FF0000
# define YELLOW 0x00FFFF00
# define ORANGE 0x00ED7F10
# define DARK_RED 0x006D071A
# define WHITE 0x00FFFFFF
# define HAZEL 0x00955628
# define PARMA 0x00CFA0E9
# define PRASIN 0x004CA66B

typedef struct		s_grid
{
	int				width;
	int				height;
}					t_grid;

typedef struct		t_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_prog
{
	t_grid			*grid;
	t_point			*point;
	char			*title;
	char			*map;
	int				**number_map;
	int				fd;
	int				win_w;
	int				win_h;
	void			*init;
	void			*window;
	void			*img;
	int				*array;
	int				bpp;
	int				s_l;
	int				endian;
	int				color;
	int				flag_s;
	int				a;
	int				b;
	int				start;
	int				x_step;
	int				y_step;
}					t_prog;

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

/*
** MiniLibx functions
*/

void			*mlx_init();

void			*mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);
void			*mlx_clear_widow(void *mlx_ptr, void *win_ptr);
int				mlx_destroy_window(void *mlx_ptr, void *win_ptr);

int				mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color);

void			*mlx_new_image(void *mlx_ptr, int width, int height);
int				mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y);
char			*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel, int *size_line, int *endian);
int				mlx_destroy_image(void *mlx_ptr, void *img_ptr);
unsigned int	mlx_get_color_value(void *mlx_ptr, int color);
void			*mlx_xpm_to_image(void *mlx_ptr, char **xpm_data, int *width, int *height);
void			*mlx_xpm_file_to_image(void *mlx_ptr, char *filename, int *width, int *height);

int				mlx_loop(void *mlx_ptr);
int				mlx_key_hook(void *win_ptr, int (*funct_ptr)(), void *param);
int				mlx_mouse_hook(void *win_ptr, int (*funct_ptr)(), void *param);
int				mlx_expose_hook(void *win_ptr, int (*funct_ptr)(), void *param);
int				mlx_loop_hook(void *mlx_ptr, int (*funct_ptr)(), void *param);

#endif
