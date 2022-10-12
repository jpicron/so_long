/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpicron <jpicron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:32:21 by bvernimm          #+#    #+#             */
/*   Updated: 2022/10/12 14:05:56 by jpicron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <libc.h>
# include "libftprintf.h"

typedef struct s_path {
	int		x;
	int		y;
	int		k;
	int		collectible;
	int		exit;
	int		lines;
	int		colonnes;
}				t_path;
typedef struct s_vars {
	void	*mlx;
	void	*win;
	char	**map;
	int		playerx;
	int		playery;
	int		player2x;
	int		player2y;
	int		collectible;
	int		move;
}				t_vars;

typedef struct s_wall {
	void	*img;
	char	*path;
	int		w;
	int		h;
}				t_wall;

void	start(int x, int y, char **map, int player_nbr);
char	*ft_unsplit(char **map);
int		do_stuff_player1(int keycode, t_vars *vars);
int		ft_exit(t_vars *vars);
int		rm_img(t_wall *img1, t_vars *vars, int x, int y);
int		go_up(t_wall *img1, t_vars *vars, int *x, int *y);
int		go_right(t_wall *img1, t_vars *vars, int *x, int *y);
int		go_down(t_wall *img1, t_vars *vars, int *x, int *y);
int		go_left(t_wall *img1, t_vars *vars, int *x, int *y);
int		rm_img2(t_wall *img1, t_vars *vars, int x, int y);
int		go_up2(t_wall *img1, t_vars *vars, int *x, int *y);
int		go_right2(t_wall *img1, t_vars *vars, int *x, int *y);
int		go_down2(t_wall *img1, t_vars *vars, int *x, int *y);
int		go_left2(t_wall *img1, t_vars *vars, int *x, int *y);
void	ft_ennemi(t_vars *vars, int *x, int *y);
int		ft_put_move(t_vars *vars);
char	*ft_itoa(int nb);
char	*ft_rev_tab(char *tab, int len);
int		ft_nbr_len(int nb);
void	make_map(char *map, t_vars *vars, int x, int y);
void	ft_put_wall(t_vars *vars, int x, int y);
void	ft_put_floor(t_vars *vars, int x, int y);
void	ft_put_collectibles(t_vars *vars, int x, int y);
void	ft_put_exit(t_vars *vars, int x, int y);
void	ft_put_player(t_vars *vars, int x, int y, int *player);
char	*ft_strjoin(char *file, char *tmp, int indic);
int		ft_strlen(char *str);
char	**ft_split(char const *s, char c);
int		check_map(int *x, int *y, int fd, int check);
int		verif_map1(char *file, char **map, int *x, int *y);
int		check_middle_line(char *line, int len);
int		check_border_line(char *line, int len);
int		ft_counter_split(char *map);
int		verif_map2(int i, char *file);
char	*read_file(int fd);
char	**ft_arrdup(char **s, char	**dup);
int		verif_path(char **map);
t_path	verif_path2(char **map, int x, int y, t_path path);
t_path	verif_path3(char **map, int x, int y, t_path path);
t_path	verif_path4(char **map, int x, int y, t_path path);
t_path	verif_path_up(char **map, int x, int y, t_path path);
t_path	verif_path_down(char **map, int x, int y, t_path path);
t_path	verif_path_left(char **map, int x, int y, t_path path);
t_path	verif_path_right(char **map, int x, int y, t_path path);
void	ft_error(int error);
#endif
