/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checkers2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsonmez <dsonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 23:02:58 by dsonmez           #+#    #+#             */
/*   Updated: 2025/03/16 04:21:24 by dsonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_rectangular(t_gamecntrl *game)
{
	int		i;

	i = 0;
	while (i < game->heightmap - 1)
	{
		if ((int)(ft_strlen(game->map[i])) - 1 != game->widthmap)
		{
			ft_printf("Error: Not Rectangular\n");
			ft_exit(game);
		}
		i++;
	}
	if ((int)(ft_strlen(game->map[i])) - 1 != game->widthmap)
	{
		if (game->map[i][game->widthmap] != '\0')
		{
			ft_printf("Error: Not Rectangular\n");
			ft_exit(game);
		}
	}
}

void	fill_flood(char **map, t_gamecntrl *game, int i, int j)
{
	if (i >= game->heightmap || j >= game->widthmap)
		return ;
	if (map[i][j] == 'E')
		map[i][j] = '1';
	if (map[i][j] == '1')
		return ;
	if (map[i][j] == 'C' || map[i][j] == 'P' || map[i][j] == '0')
		map[i][j] = '1';
	fill_flood(map, game, i + 1, j);
	fill_flood(map, game, i - 1, j);
	fill_flood(map, game, i, j + 1);
	fill_flood(map, game, i, j - 1);
}

int	check_ff(char **map, t_gamecntrl *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->heightmap)
	{
		j = 0;
		while (j < game->widthmap)
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_path(char **map, t_gamecntrl *game, int p_i, int p_j)
{
	int		i;
	char	**map_copy;

	i = 0;
	map_copy = (char **)malloc(game->heightmap * sizeof(char *));
	while (i < game->heightmap)
	{
		map_copy[i] = ft_strdup(map[i]);
		i++;
	}
	fill_flood(map_copy, game, p_i, p_j);
	if (!check_ff(map_copy, game))
	{
		ft_printf("Error: There isn't a true path\n");
		i = 0;
		while (i < game->heightmap)
			free(map_copy[i++]);
		free(map_copy);
		return (0);
	}
	i = 0;
	while (i < game->heightmap)
		free(map_copy[i++]);
	free(map_copy);
	return (1);
}
