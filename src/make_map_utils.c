/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpicron <jpicron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:13:04 by bvernimm          #+#    #+#             */
/*   Updated: 2022/10/06 12:05:29 by jpicron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_wall(t_vars *vars, int x, int y)
{
	t_wall	img1;

	img1.path = "./image/wall.xpm";
	img1.img = mlx_xpm_file_to_image(vars->mlx, img1.path, &img1.w, &img1.h);
	mlx_put_image_to_window(vars->mlx, vars->win, img1.img, x, y);
	mlx_destroy_image(vars->mlx, img1.img);
}

void	ft_put_floor(t_vars *vars, int x, int y)
{
	t_wall	img1;

	img1.path = "./image/grass.xpm";
	img1.img = mlx_xpm_file_to_image(vars->mlx, img1.path, &img1.w, &img1.h);
	mlx_put_image_to_window(vars->mlx, vars->win, img1.img, x, y);
	mlx_destroy_image(vars->mlx, img1.img);
}

void	ft_put_collectibles(t_vars *vars, int x, int y)
{
	t_wall	img1;

	vars->collectible++;
	img1.path = "./image/wheat.xpm";
	img1.img = mlx_xpm_file_to_image(vars->mlx, img1.path, &img1.w, &img1.h);
	mlx_put_image_to_window(vars->mlx, vars->win, img1.img, x, y);
	mlx_destroy_image(vars->mlx, img1.img);
}

void	ft_put_player(t_vars *vars, int x, int y, int *player)
{
	t_wall	img1;

	if (*player == 1)
	{
		img1.path = "./image/mouton_droite.xpm";
		vars->playerx = x;
		vars->playery = y;
		*player = 2;
	}
	else if (*player == 2)
	{
		img1.path = "./image/steve_droite.xpm";
		vars->player2x = x;
		vars->player2y = y;
	}
	img1.img = mlx_xpm_file_to_image(vars->mlx, img1.path, &img1.w, &img1.h);
	mlx_put_image_to_window(vars->mlx, vars->win, img1.img, x, y);
	mlx_destroy_image(vars->mlx, img1.img);
}

void	ft_put_exit(t_vars *vars, int x, int y)
{
	t_wall	img1;

	img1.path = "./image/exit.xpm";
	img1.img = mlx_xpm_file_to_image(vars->mlx, img1.path, &img1.w, &img1.h);
	mlx_put_image_to_window(vars->mlx, vars->win, img1.img, x, y);
	mlx_destroy_image(vars->mlx, img1.img);
}
