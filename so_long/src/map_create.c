/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:16:50 by oklimov           #+#    #+#             */
/*   Updated: 2025/02/18 15:48:17 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**read_map(char *map_file)
{
	int		fd;
	int		i;
	char	*line;
	char	**map;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return (perror("open map file - Error\n"), NULL);
	map = malloc(sizeof(char *) * 100);
	if (!map)
		return (perror("map memory allocate - Error\n"), NULL);
	line = "1";
	i = 0;
	while (line != NULL)
	{
		line = get_next_line(fd);
		map[i] = line;
		i++;
	}
	close(fd);
	map[i] = NULL;
	return (map);
}

int	is_wall(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		if (str[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	map_walls_is_valid(char **map, t_map *game)
{
	unsigned long	y;

	y = 0;
	while (map[y] != NULL)
		y++;
	game->y = y;
	y = 0;
	while (map[y] != NULL)
	{
		if (y == 0 || y == game->y - 1)
		{
			if (is_wall(map[y]) != 0)
				return (0);
		}
		if (map[y][0] != '1' || map[y][ft_strlen(map[y]) - 2] != '1')
			return (0);
		y++;
	}
	while (--y != 0)
	{
		if (ft_strlen(map[y]) != ft_strlen(map[0]))
			return (0);
	}
	return (1);
}

// items[0] - exit
// items[1] - player
int	map_rules_is_valid(char **map, t_map *game, int x, int y)
{
	int	items[2];

	items[0] = 0;
	items[1] = 0;
	game->collect = 0;
	while (map[++y] != NULL)
	{
		x = -1;
		while (map[y][++x] != '\0')
		{
			if (map[y][x] == 'C')
				game->collect += 1;
			if (map[y][x] == 'E')
				items[1]++;
			if (map[y][x] == 'P')
				items[0]++;
			if (map[y][x] != '0' && map[y][x] != '1' && map[y][x] != 'C'
				&& map[y][x] != 'E' && map[y][x] != 'P' && map[y][x] != '\n')
				return (0);
		}
	}
	if (game->collect < 1 || items[1] != 1 || items[0] != 1)
		return (0);
	return (1);
}

void	map_create(char *map_file, t_map *game, t_play *play)
{
	int		flag;

	play->map = read_map(map_file);
	game->x = ft_strlen(play->map[0]);
	position_filler(play->map, game);
	flag = map_walls_is_valid(play->map, game);
	if (flag == 0)
		map_error(game, play, 0);
	flag = map_rules_is_valid(play->map, game, 0, -1);
	if (flag == 0)
		map_error(game, play, 1);
	flag = map_pathfinder(play->map, game);
	if (flag == 0)
		map_error(game, play, 2);
}
