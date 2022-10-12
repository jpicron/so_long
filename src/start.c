/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpicron <jpicron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:32:50 by jpicron           #+#    #+#             */
/*   Updated: 2022/10/12 13:46:22 by jpicron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit(t_vars *vars)
{
	free(vars->map);
	mlx_destroy_window(vars->mlx, vars->win);
	ft_printf("Movements : %d\n", vars->move);
	write (1, "exit\n", 5);
	exit (0);
}

int	do_stuff_player2(int keycode, t_vars *vars)
{
	static t_wall	img2;

	if (!img2.path)
		img2.path = "./image/steve_droite.xpm";
	if (keycode == 126)
		go_up2(&img2, vars, &vars->player2x, &vars->player2y);
	else if (keycode == 123)
		go_right2(&img2, vars, &vars->player2x, &vars->player2y);
	else if (keycode == 125)
		go_down2(&img2, vars, &vars->player2x, &vars->player2y);
	else if (keycode == 124)
		go_left2(&img2, vars, &vars->player2x, &vars->player2y);
	else
		do_stuff_player1(keycode, vars);
	return (0);
}

int	do_stuff_player1(int keycode, t_vars *vars)
{
	static t_wall	img1;

	if (!img1.path)
		img1.path = "./image/mouton_droite.xpm";
	if (keycode == 53)
		ft_exit(vars);
	if (keycode == 13 || keycode == 126)
		go_up(&img1, vars, &vars->playerx, &vars->playery);
	if (keycode == 0 || keycode == 123)
		go_right(&img1, vars, &vars->playerx, &vars->playery);
	if (keycode == 1 || keycode == 125)
		go_down(&img1, vars, &vars->playerx, &vars->playery);
	if (keycode == 2 || keycode == 124)
		go_left(&img1, vars, &vars->playerx, &vars->playery);
	return (0);
}

char	*ft_unsplit(char **map)
{
	char	*line;
	int		i;

	i = 0;
	while (map[i])
	{
		line = ft_strjoin(line, map[i], 1);
		line = ft_strjoin(line, "\n", 1);
		i++;
	}
	return (line);
}

void	start(int x, int y, char **map, int player_nbr)
{
	t_vars	data;
	char	*unsplit_map;

	data.move = 0;
	data.map = map;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, x, y, "So_long");
	unsplit_map = ft_unsplit(map);
	make_map(unsplit_map, &data, 0, 0);
	free(unsplit_map);
	if (player_nbr == 2)
		data.collectible--;
	if (player_nbr == 1)
		mlx_key_hook(data.win, do_stuff_player1, &data);
	if (player_nbr == 2)
		mlx_key_hook(data.win, do_stuff_player2, &data);
	mlx_hook(data.win, 17, 1L << 17, ft_exit, &data);
	mlx_loop(data.mlx);
}
