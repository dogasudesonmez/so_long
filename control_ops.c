/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsonmez <dsonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 23:02:11 by dsonmez           #+#    #+#             */
/*   Updated: 2025/03/15 22:43:38 by dsonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	right_move(t_gamecntrl *game, int i, int j)
{
	if (game->map[j][i] == 'E')
	{
		if (game->collectables != 0)
			return (0);
		game->counter++;
		ft_printf("Steps Taken: %i\n", game->counter);
		ft_printf("\nYou Have Won, Congrats!\n");
		ft_exit(game);
	}
	if (game->map[j][i] == '0')
	{
		game->map[j][i] = 'P';
		game->x_axis = i;
		game->y_axis = j;
		game->counter++;
	}
	if (game->map[j][i] == 'C')
	{
		game->map[j][i] = 'P';
		game->x_axis = i;
		game->y_axis = j;
		game->collectables--;
		game->counter++;
	}
	return (1);
}

int	key_w_s(t_gamecntrl *game, int movement)
{
	int	i;
	int	j;

	i = game->x_axis;
	j = game->y_axis;
	if (movement == 119)
	{
		j--;
		if (game->map[j][i] == '1')
			return (0);
		if (!right_move(game, i, j))
			return (0);
		game->map[j + 1][i] = '0';
	}
	else if (movement == 115)
	{
		j++;
		if (game->map[j][i] == '1')
			return (0);
		if (!right_move(game, i, j))
			return (0);
		game->map[j - 1][i] = '0';
	}
	ft_printf("Steps Taken: %i\n", game->counter);
	return (1);
}

int	key_a_d(t_gamecntrl *game, int movement)
{
	int	i;
	int	j;

	i = game->x_axis;
	j = game->y_axis;
	if (movement == 97)
	{
		i--;
		if (game->map[j][i] == '1')
			return (0);
		if (!right_move(game, i, j))
			return (0);
		game->map[j][i + 1] = '0';
	}
	else if (movement == 100)
	{
		i++;
		if (game->map[j][i] == '1')
			return (0);
		if (!right_move(game, i, j))
			return (0);
		game->map[j][i - 1] = '0';
	}
	ft_printf("Steps Taken: %i\n", game->counter);
	return (1);
}

int	controls_manager(int keycode, t_gamecntrl *game)
{
	int	works;

	works = 0;
	if (keycode == 65307)
		ft_exit(game);
	else if (keycode == 115 || keycode == 119)
		works = key_w_s(game, keycode);
	else if (keycode == 97 || keycode == 100)
		works = key_a_d(game, keycode);
	if (works)
		place_graphics(game);
	return (1);
}
