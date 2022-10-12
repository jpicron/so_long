/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpicron <jpicron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:57:59 by jpicron           #+#    #+#             */
/*   Updated: 2022/10/12 14:08:52 by jpicron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	verif_path(char **map)
{
	t_path	path;
	int		i;

	path.collectible = 0;
	path.exit = 0;
	path = verif_path2(map, 1, 1, path);
	i = path.exit;
	path = verif_path3(map, path.x, path.y, path);
	if (path.collectible != 0)
		return (2);
	if (path.exit >= i)
		return (3);
	return (0);
}

t_path	verif_path2(char **map, int x, int y, t_path path)
{
	path.k = 0;
	path.colonnes = 0;
	while (map[y + 1][0])
	{
		while (map [y + 1][x] != '\0')
		{
			path = verif_path4(map, x, y, path);
			x++;
		}
		if (path.colonnes == 0)
			path.colonnes = x;
		x = 1;
		if (map[y])
			y++;
	}
	path.lines = y;
	return (path);
}

t_path	verif_path4(char **map, int x, int y, t_path path)
{
	if (map[y][x] == 'P' && path.k == 0)
	{
		path.y = y;
		path.x = x;
		path.k = 1;
	}
	else if (map[y][x] == 'C')
		path.collectible += 1;
	else if (map[y][x] == 'E')
		path.exit += 1;
	return (path);
}

t_path	verif_path3(char **map, int x, int y, t_path path)
{
	path = verif_path_down(map, x, y, path);
	path = verif_path_up(map, x, y, path);
	path = verif_path_left(map, x, y, path);
	path = verif_path_right(map, x, y, path);
	return (path);
}
