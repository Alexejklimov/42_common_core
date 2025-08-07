/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:31:28 by oklimov           #+#    #+#             */
/*   Updated: 2025/07/15 15:06:52 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libraries/minilibx-linux/mlx.h"
# include "libraries/printf/ft_printf.h"
# include "libraries/libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100

typedef struct s_map_info
{
	size_t		x;
	size_t		y;
	char		**map;
	int			start_pos[2];
	char		start_orient;
	char	*texture[4];
	int			floor_rgb[3];
	int			ceil_rgb[3];
}	t_map_info;

typedef struct s_game
{
	void	*mlx;
	void	*win_mlx;
	char	**map;

}	t_game;

typedef enum e_texture
{
	NORD,
	SOUTH,
	WEST,
	EAST,
	FLOOR,
	CEIL
}	t_texture;

//parsing of map

const char		**read_map(char *map_file);
void			rgb_parse(const char *line, int *dest);
int				parse_texture(const char **file, t_map_info *map_info);
const char		**separate_map(const char **file, t_map_info *map_info);
void			parse_map(char *file, t_map_info *map_info);
int				verify_texture(t_map_info *map);
void			check_map_is_valid(const char **map, t_map_info *map_info);
int				is_symbols_valid_only(const char **map);
int				check_walls_is_valid(const char **map);
#endif