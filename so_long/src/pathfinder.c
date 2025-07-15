/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:55:55 by oklimov           #+#    #+#             */
/*   Updated: 2025/02/18 15:50:20 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	map_pathfinder(char **map, t_map *game)
{
	char	**tmp;
	int		y;

	tmp = malloc(sizeof(char *) * (game->y + 1));
	if (!tmp)
		return (0);
	y = 0;
	while (map[y] != NULL)
	{
		tmp[y] = ft_strdup(map[y]);
		if (!tmp[y])
			return (free_map(tmp), 0);
		y++;
	}
	tmp[y] = NULL;
	check_path(tmp, game, game->start_pos[0], game->start_pos[1]);
	if (check_path_validity(tmp) == 0)
		return (free_map(tmp), 0);
	return (free_map(tmp), 1);
}

void	check_path(char **tmp, t_map *game, int y, int x)
{
	if (x < 0 || y < 0 || x >= (int)game->x || y >= (int)game->y
		|| tmp[y][x] == '1' || tmp[y][x] == '.')
		return ;
	tmp[y][x] = '.';
	check_path(tmp, game, y + 1, x);
	check_path(tmp, game, y - 1, x);
	check_path(tmp, game, y, x + 1);
	check_path(tmp, game, y, x - 1);
}

int	check_path_validity(char **tmp)
{
	int	y;
	int	x;

	y = 0;
	while (tmp[y] != NULL)
	{
		x = 0;
		while (tmp[y][x] != '\0')
		{
			if (tmp[y][x] == 'E' || tmp[y][x] == 'C')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

void	map_error(t_map *game, t_play *play, int err)
{
	if (err == 0)
		ft_printf("Error\nMap isn`t valid!!! Check the walls!\n");
	else if (err == 1)
		ft_printf("Error\nMap rules are invalid!!!\n");
	else if (err == 2)
		ft_printf("Error\nMap path isn`t valid!!! Imposible to win\n");
	clean_all_structs(game, play);
	exit(0);
}
