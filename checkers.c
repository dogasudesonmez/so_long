/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsonmez <dsonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 22:12:06 by dsonmez           #+#    #+#             */
/*   Updated: 2025/03/16 04:40:58 by dsonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_pce_imagechecker(void)
{
	int	fd_player;
	int	fd_collectable;
	int	fd_exit;

	fd_player = open("images/player.xpm", O_RDWR);
	fd_collectable = open("images/collectable.xpm", O_RDWR);
	fd_exit = open("images/exit.xpm", O_RDWR);
	if (fd_player < 0 || fd_collectable < 0 || fd_exit < 0)
	{
		ft_printf("Error: Missing Image File\n");
		close(fd_player);
		close(fd_collectable);
		close(fd_exit);
		exit(1);
	}
	close(fd_player);
	close(fd_collectable);
	close(fd_exit);
}

void	ft_imagechecker(void)
{
	int	fd_floor;
	int	fd_wall;

	fd_floor = open("images/floor.xpm", O_RDWR);
	fd_wall = open("images/wall.xpm", O_RDWR);
	if (fd_floor < 0 || fd_wall < 0)
	{
		ft_printf("Error: Missing Image File\n");
		close(fd_floor);
		close(fd_wall);
		exit(1);
	}
	close(fd_floor);
	close(fd_wall);
	ft_pce_imagechecker();
}

void	ft_pathchecker(char *path)
{
	int	fd;
	int	len;

	fd = open(path, O_RDWR);
	len = ft_strlen(path);
	if (fd < 0)
	{
		ft_printf("Error: Missing Map File\n");
		close(fd);
		exit(1);
	}
	close(fd);
	if (path[len - 1] != 'r' || path[len - 2] != 'e'
		|| path[len - 3] != 'b' || path[len - 4] != '.')
	{
		ft_printf("Error: Wrong File Extension\n");
		exit(1);
	}
}
