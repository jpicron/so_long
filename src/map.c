/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpicron <jpicron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:53:51 by jpicron           #+#    #+#             */
/*   Updated: 2022/10/12 13:44:28 by jpicron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map(int *x, int *y, int fd, int check)
{
	char	**map;
	char	**map_for_verif;
	char	*file;
	int		error;

	map_for_verif = NULL;
	file = read_file(fd);
	if (ft_counter_split(file) == -1)
		return (1);
	map = ft_split(file, '\n');
	free(map_for_verif);
	check = verif_map1(file, map, x, y);
	free(file);
	if (check == -1)
		return (1);
	map_for_verif = ft_arrdup(map, map_for_verif);
	if (!map_for_verif)
		return (1);
	error = verif_path(map_for_verif);
	if (error != 0)
		return (error);
	start(*x, *y, map, check);
	free(map);
	return (0);
}

int	verif_map1(char *file, char **map, int *x, int *y)
{
	int	i;
	int	len;
	int	check;

	len = ft_strlen(map[0]);
	i = 1;
	if (check_border_line(map[0], len) == 0)
		return (-1);
	while (map[i + 1])
	{
		if (check_middle_line(map[i], len) == 0)
			return (-1);
		else
			i++;
	}
	if (check_border_line(map[i], len) == 0)
		return (-1);
	check = verif_map2(0, file);
	if (check == 0)
		return (-1);
	*x = len * 80;
	*y = (i + 1) * 80;
	return (check);
}

int	verif_map2(int i, char *file)
{
	int	e;
	int	c;
	int	p;

	e = 0;
	c = 0;
	p = 0;
	while (file[i])
	{
		if (file[i] != '1' && file[i] != '0' && file[i] != 'E'
			&& file[i] != 'C' && file[i] != 'P' && file[i] != '\n')
			return (0);
		if (file[i] == 'E')
			e++;
		if (file[i] == 'C')
			c++;
		if (file[i] == 'P')
			p++;
		i++;
	}
	if (e != 1 || c <= 0 || (p != 1 && p != 2))
		return (0);
	if (p == 2)
		return (2);
	return (1);
}

void	make_map(char *map, t_vars *vars, int x, int y)
{
	int	i;
	int	player;

	i = 0;
	player = 1;
	vars->collectible = 0;
	while (map[i])
	{
		ft_put_floor(vars, x, y);
		if (map[i] == '1')
			ft_put_wall(vars, x, y);
		if (map[i] == 'P')
			ft_put_player(vars, x, y, &player);
		if (map[i] == 'C')
			ft_put_collectibles(vars, x, y);
		if (map[i] == 'E')
			ft_put_exit(vars, x, y);
		x += 80;
		if (map[i] == '\n')
		{
			x = 0;
			y += 80;
		}
		i++;
	}
}
