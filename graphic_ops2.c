/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_ops2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsonmez <dsonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 23:02:39 by dsonmez           #+#    #+#             */
/*   Updated: 2025/03/16 02:10:50 by dsonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	place_wall(t_gamecntrl *game, int height, int width)
{
	mlx_put_image_to_window(game->mlxpointer,
		game->winpointer, game->b_image, width * 64, height * 64);
}

void	place_player(t_gamecntrl *game, int height, int width)
{
	mlx_put_image_to_window(game->mlxpointer,
		game->winpointer, game->p_image, width * 64, height * 64);
	game->y_axis = height;
	game->x_axis = width;
}

void	place_collectable(t_gamecntrl *game, int height, int width)
{
	mlx_put_image_to_window(game->mlxpointer,
		game->winpointer, game->c_image, width * 64, height * 64);
	game->collectables++;
}

void	place_exit(t_gamecntrl *game, int height, int width)
{
	mlx_put_image_to_window(game->mlxpointer,
		game->winpointer, game->e_image, width * 64, height * 64);
}

void	place_floor(t_gamecntrl *game, int height, int width)
{
	mlx_put_image_to_window(game->mlxpointer,
		game->winpointer, game->f_image, width * 64, height * 64);
}
