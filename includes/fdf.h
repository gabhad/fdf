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

typedef struct		s_grid
{
	int				width;
	int				height;
}					t_grid;

typedef struct		s_prog
{
	t_grid			*grid;
	char			*map;
	int				**number_map;
	int				fd;
	int				win_w;
	int				win_h;
	void			*init;
	void			*window;
	void			*img;
	int				bpp;
	int				s_l;
	int				endian;
	int				color;
}					t_prog;

/*
** Gemeral functions
*/

void			usage(void);
void			error(t_prog *prog);
void			malloc_error(t_prog *prog);
void			no_map(t_prog *prog);
void			multi_maps(t_prog *prog);
void			invalid_map(t_prog *prog);
int				invalid_chars(char *map);
void			rectangle_map(t_prog *prog);
void			clear_struct(t_prog *prog);
void			clear_lines(t_prog *prog);

/*
** Parsing functions
*/

void			fdf_parser(int argc, char **argv);
t_prog			*init_prog(t_prog *prog);
void			flag_s(t_prog *prog, char **argv, int i);
void			read_map(t_prog *prog);
void			convert_map(t_prog *prog);
int				count_lines(t_prog *prog);
int				count(t_prog *prog);

/*
**	Drawing functions
*/

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
