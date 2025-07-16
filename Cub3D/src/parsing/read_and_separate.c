/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_&_separate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:04:18 by oklimov           #+#    #+#             */
/*   Updated: 2025/07/16 14:04:18 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

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
	line = "Labubu";
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

void	rgb_parse(char *line, int *dest)
{
	int			i;
	int			texture_index;
	int			buffer;

	buffer = 0;
	i = 0;
	texture_index = 0;
	printf("start-> %s\n", line);
	while (line[i] && texture_index < 3)
	{
		buffer = 0;
		while (ft_isdigit(line[i]))
			buffer = (buffer * 10) + (line[i++] - '0');
		if (buffer)
			dest[texture_index++] = buffer;
		i++;
	}
}

int	parse_texture(char **file, t_map *map)
{
	int	i;

	i = 0;
	while (file[i][0] != '1' || file[i][0] != ' ')
	{
		if (file[i][0] == '\0')
			i++;
		else if (!ft_strncmp(file[i], "NO", 2))
			map->texture[0] = ft_strdup(file[i] + 3);
		else if (!ft_strncmp(file[i], "SO", 2))
			map->texture[1] = ft_strdup(file[i] + 3);
		else if (!ft_strncmp(file[i], "WE", 2))
			map->texture[2] = ft_strdup(file[i] + 3);
		else if (!ft_strncmp(file[i], "EA", 2))
			map->texture[3] = ft_strdup(file[i] + 3);
		else if (!ft_strncmp(file[i], "F", 1))
			rgb_parse(file[i] + 2, map->floor_rgb);
		else if (!ft_strncmp(file[i], "C", 1))
			rgb_parse(file[i] + 2, map->ceil_rgb);
		i++;
	}
	return (i);
}

char	**separate_map(char **file, t_map *map)
{
	int		i;
	int		j;
	char	**separated_map;

	separated_map = NULL;
	i = parse_texture(file, map);
	j = 0;
	while (file[i] != NULL)
		separated_map[j++] = ft_strdup(file[i++]);
	return (separated_map);
}

void    parse_map(char *file, t_map *map)
{
    map->map = separate_map(read_map(file), map);
}
