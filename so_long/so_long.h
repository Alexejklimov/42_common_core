/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:55:23 by oklimov           #+#    #+#             */
/*   Updated: 2025/02/18 15:16:15 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "gnl/get_next_line.h"
# include "printf/ft_printf.h"

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100

# define PXL 64
# define IMG_COUNT 6
# define FLOOR "img/floor.xpm"
# define PLAYER "img/peppa1.xpm"
# define WALL "img/wall.xpm"
# define EXIT0 "img/exit0.xpm"
# define PIZZA0 "img/pizzac.xpm"

typedef struct s_map
{
	size_t	x;
	size_t	y;
	int		collect;
	int		start_pos[2];
	int		exit_pos[2];
}	t_map;

typedef struct s_play
{
	void	*mlx;
	void	*win_mlx;
	char	**map;
	void	*img[6];
	size_t	x;
	size_t	y;
	int		collect;
	int		collected;
	int		steps;
	int		start_pos[2];
	int		exit_pos[2];
}	t_play;

char	*ft_strcpy(char	*dest, char	*src);
char	*get_next_line(int fd);
char	**read_map(char *map_file);
int		map_walls_is_valid(char **map, t_map *game);
int		map_rules_is_valid(char **map, t_map *game, int x, int y);
void	map_create(char *map_file, t_map *game, t_play *play);
void	clean_map(t_map *game);
void	position_filler(char **map, t_map *game);
void	free_map(char **map);
int		map_pathfinder(char **map, t_map *game);
void	check_path(char **tmp, t_map *game, int y, int x);
int		check_path_validity(char **tmp);
void	fill_t_play(t_map *game, t_play *play);
void	fill_window(t_play	*play, void	*mlx, void *win);
int		read_move(int key, t_play *play);
void	make_move(t_play *play, int horis, int vert);
void	clean_all_structs(t_map *game, t_play *play);
void	exit_game(t_map *game, t_play *play);
void	map_error(t_map *game, t_play *play, int err);

#endif
