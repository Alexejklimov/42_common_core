/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:56:02 by oklimov           #+#    #+#             */
/*   Updated: 2025/08/07 17:19:49 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	parse_map(char *file, t_map_info *map_info)
{
	const char	**buffer_map;

	buffer_map = separate_map(read_map(file), map_info);
	check_map_is_valid(buffer_map, map_info);
}

// int	check_walls_is_valid(const char **map)
// {
// 	int	x;
// 	int	y;

// 	x = 0;
// 	while (map[x] != NULL)
// 	{
// 		y = 0;
// 		while (map[x][y] != '\0')
// 		{
// 			if (map[x][y] == '0')
// 			{
// 				if (!((map[x][y + 1] && map[x][y + 1] != ' ')
// 				&& (y > 0 && map[x][y - 1] != ' ')
// 				&& (map[x + 1] && map[x + 1][y] != ' ')
// 				&& (x > 0 && map[x - 1][y] != ' ')))
// 					return (0);
// 			}
// 			y++;
// 		}
// 		x++;
// 	}
// 	return (1);
// }

int	check_walls_is_valid(const char **map)
{
	int	x;
	int	y;

	x = 0;
	while (map[x] != NULL)
	{
		y = 0;
		while (map[x][y] != '\0')
		{
			if (ft_strchr("NSEW0", (int)map[x][y]))
			{
				if (x == 0 || map[x + 1] == NULL || y == 0
					|| y >= ft_strlen(map[x - 1]) || y >= ft_strlen(map[x + 1])
					|| map[x][y + 1] == '\0')
					return (0);
				if (ft_strchr("\n ", (int)map[x][y + 1])
					|| ft_strchr("\n ", (int)map[x][y - 1])
					|| ft_strchr("\n ", (int)map[x + 1][y])
					|| ft_strchr("\n ", (int)map[x - 1][y]))
					return (0);
			}
			y++;
		}
		x++;
	}
	return (1);
}

int	is_symbols_valid_only(const char **map)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	flag = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\n' && map[i][j] != '\0')
		{
			if (!ft_strchr("NSEW 10", (int)map[i][j]))
				return (printf("Error\ninvalid symbol in map"), 0);
			if (ft_strchr("NSEW", map[i][j]))
				flag++;
			j++;
		}
		i++;
	}
	if (flag != 1)
		return (perror("Error\nto many start positions"), 0);
	return (1);
}

void	check_map_is_valid(const char **map, t_map_info *map_info)
{
	if (!is_symbols_valid_only(map))
	{
		free(map);
		//clean_and_exit(map_info);
	}
	if (!verify_texture(map_info))
		printf("Error\nTexture data not valid\n"); /////
	if (!check_walls_is_valid(map))
		printf("Error\nWalls is invalid\n"); //////

	free(map);
}


