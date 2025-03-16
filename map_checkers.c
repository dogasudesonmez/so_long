/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checkers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsonmez <dsonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 23:02:53 by dsonmez           #+#    #+#             */
/*   Updated: 2025/03/14 23:02:54 by dsonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_hwall(t_gamecntrl *game)
{
	int	height;
	int	width;

	height = game->heightmap;
	width = 0;
	while (width < game->widthmap)
	{
		if (!(game->map[0][width] == '1'
			&& game->map[height - 1][width] == '1'))
			return (0);
		width++;
	}
	return (1);
}

int	is_valid_vwall(t_gamecntrl *game)
{
	int	height;
	int	width;

	height = 0;
	width = game->widthmap;
	while (height < game->heightmap)
	{
		if (!(game->map[height][0] == '1'
			&& game->map[height][width - 1] == '1'))
			return (0);
		height++;
	}
	return (1);
}

void	count_checker(t_gamecntrl *game, int height, int width)
{
	if (game->map[height][width] != '1' &&
		game->map[height][width] != '0' &&
		game->map[height][width] != 'P' &&
		game->map[height][width] != 'E' &&
		game->map[height][width] != 'C' &&
		game->map[height][width] != '\n')
	{
		ft_printf("Error Here!%c\n", game->map[height][width]);
		ft_exit(game);
	}
	if (game->map[height][width] == 'C')
		game->c_counter++;
	if (game->map[height][width] == 'P')
		game->p_counter++;
	if (game->map[height][width] == 'E')
		game->e_counter++;
}

void	ft_charchecker(t_gamecntrl *game)
{
	int	height;
	int	width;

	height = 0;
	while (height < game->heightmap - 1)
	{
		width = 0;
		while (width <= game->widthmap)
		{
			count_checker(game, height, width);
			width++;
		}
		height++;
	}
	if (!(game->p_counter == 1 && game->c_counter >= 1
			&& game->e_counter == 1))
	{
		ft_printf("Error: Player, collectable or exit issue\n");
		ft_exit(game);
	}
}

void	ft_mapchecker(t_gamecntrl *game)
{
	int	i;
	int	j;

	if (!is_valid_vwall(game) || !is_valid_hwall(game))
	{
		ft_printf("Error: Missing wall\n");
		ft_exit(game);
	}
	ft_charchecker(game);
	i = 0;
	while (i < game->heightmap)
	{
		j = 0;
		while (j < game->widthmap)
		{
			if (game->map[i][j] == 'P')
			{
				if (!check_path(game->map, game, i, j))
					ft_exit(game);
				return ;
			}
			j++;
		}
		i++;
	}
}
