/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsonmez <dsonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 23:03:19 by dsonmez           #+#    #+#             */
/*   Updated: 2025/03/16 02:09:30 by dsonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include "ft_printf/ft_printf.h"
# include "get_next_line.h"
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"

typedef struct s_gamecntrl
{
	int		fd;
	int		heightmap;
	int		widthmap;
	int		p_counter;
	int		c_counter;
	int		e_counter;
	int		x_axis;
	int		y_axis;
	int		counter;
	int		collectables;

	char	**map;

	void	*f_image;
	void	*b_image;
	void	*p_image;
	void	*e_image;
	void	*c_image;
	void	*mlxpointer;
	void	*winpointer;

}	t_gamecntrl;

int		ft_exit(t_gamecntrl *game);

void	ft_pce_imagechecker(void);
void	ft_imagechecker(void);
void	ft_pathchecker(char *path);

int		width_of_map(char *string);
int		add_line(t_gamecntrl *game, char *line);
int		map_reading(t_gamecntrl *game, char **argv);

int		is_valid_hwall(t_gamecntrl *game);
int		is_valid_vwall(t_gamecntrl *game);
void	count_checker(t_gamecntrl *game, int height, int width);
void	ft_charchecker(t_gamecntrl *game);
void	ft_mapchecker(t_gamecntrl *game);

void	is_rectangular(t_gamecntrl *game);
void	fill_flood(char **map, t_gamecntrl *game, int i, int j);
int		check_ff(char **map, t_gamecntrl *game);
int		check_path(char **map, t_gamecntrl *game, int p_i, int p_j);

void	place_images_in_game(t_gamecntrl *game);
void	place_graphics(t_gamecntrl *game);
void	place_wall(t_gamecntrl *game, int height, int width);
void	place_player(t_gamecntrl *game, int height, int width);
void	place_collectable(t_gamecntrl *game, int height, int width);
void	place_exit(t_gamecntrl *game, int height, int width);
void	place_floor(t_gamecntrl *game, int height, int width);

int		right_move(t_gamecntrl *game, int i, int j);
int		key_w_s(t_gamecntrl *game, int movement);
int		key_a_d(t_gamecntrl *game, int movement);
int		controls_manager(int keycode, t_gamecntrl *game);

#endif