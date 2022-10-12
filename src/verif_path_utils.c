/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_path_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpicron <jpicron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:49:06 by jpicron           #+#    #+#             */
/*   Updated: 2022/10/12 14:09:03 by jpicron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_path	verif_path_down(char **map, int x, int y, t_path path)
{
	if (y + 1 != path.lines)
	{
		if (map[y + 1][x] == 'E')
				path.exit -= 1;
		else if (map[y + 1][x] == '0' || map[y + 1][x] == 'C')
		{
			if (map[y + 1][x] == 'C')
				path.collectible -= 1;
			map[y + 1][x] = 'v';
			path = verif_path3(map, x, y + 1, path);
		}
	}
	return (path);
}

t_path	verif_path_up(char **map, int x, int y, t_path path)
{
	if (y - 1 != 0)
	{
		if (map[y - 1][x] == 'E')
			path.exit -= 1;
		else if (map[y - 1][x] == '0' || map[y - 1][x] == 'C')
		{
			if (map[y - 1][x] == 'C')
				path.collectible -= 1;
			map[y - 1][x] = 'v';
		path = verif_path3(map, x, y - 1, path);
			map[y - 1][x] = 'v';
		}
	}
	return (path);
}

t_path	verif_path_right(char **map, int x, int y, t_path path)
{
	if (x + 1 != path.colonnes)
	{
		if (map[y][x + 1] == 'E')
			path.exit -= 1;
		else if (map[y][x + 1] == '0' || map[y][x + 1] == 'C')
		{
			if (map[y][x + 1] == 'C')
				path.collectible -= 1;
			map[y][x + 1] = 'v';
			path = verif_path3(map, x + 1, y, path);
		}
	}
	return (path);
}

t_path	verif_path_left(char **map, int x, int y, t_path path)
{
	if (x - 1 != 0)
	{
		if (map[y][x - 1] == 'E')
			path.exit -= 1;
		else if (map[y][x - 1] == '0' || map[y][x - 1] == 'C')
		{
			if (map[y][x - 1] == 'C')
				path.collectible -= 1;
			map[y][x - 1] = 'v';
			path = verif_path3(map, x - 1, y, path);
			map[y][x - 1] = 'v';
		}
	}
	return (path);
}
