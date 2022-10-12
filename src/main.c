/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpicron <jpicron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:29:31 by jpicron           #+#    #+#             */
/*   Updated: 2022/10/12 13:45:19 by jpicron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	char	*file_path;
	int		x;
	int		y;
	int		fd;
	int		error;

	x = 0;
	y = 0;
	if (argc != 2)
	{
		write(2, "error\n", 6);
		exit (0);
	}
	file_path = ft_strjoin("./map/", argv[1], 0);
	fd = open(file_path, O_RDONLY);
	free(file_path);
	if (fd < 0)
	{
		write(2, "Error,\nCould not open the map\n", 30);
		exit (0);
	}
	error = check_map(&x, &y, fd, 0);
	ft_error(error);
	close (fd);
}

void	ft_error(int error)
{
	if (error == 1)
		write(2, "Error,\n map invalid\n", 20);
	else if (error == 2)
		write(2, "Error,\nno access to collectibles\n", 33);
	else if (error == 3)
		write(2, "Error,\nno access to exit\n", 25);
}
