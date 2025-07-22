/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:56:02 by oklimov           #+#    #+#             */
/*   Updated: 2025/07/22 12:01:23 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	parse_map(char *file, t_map_info *map_info)
{
	const char	**buffer_map;

	buffer_map = separate_map(read_map(file), map_info);

}

int	is_symbols_valid_only(const char *map)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	flag = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != NULL)
		{
			if (!ft_strchr("NSEW10", (int)map[i][j]))
				return (perror("Error\n invalid symbol in map"), 0);
			if (ft_strchr("NSEW", map[i][j]))
				flag++;
			j++;
		}
		i++;
	}
	if (flag != 1)
		return (perror("Error\n to many start positions"), 0);
	return (1);
}

void	check_map_is_valid(const char **map, t_map_info *map_info)
{
	if (!is_symbols_valid_only(map))
	{
		free(map);
		clean_and_exit(map_info);
	}
	if (!verify_texture(map_info))
		perror ("Error\n texture data not valid");

	free(map);
}


