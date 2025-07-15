#include "../../cub3d.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)

{
	size_t	i;

	i = 0;
	while (i < n && s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++ ;
	}
	if (i < n)
	{
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

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

void    rgb_parse(char *line, int *dest)
{
    int i;
    int j;
    int texture_index;
    char *buffer;

    buffer = NULL;
    i = 0;
    texture_index = 0;
    while (line[i] != NULL)
    {
        j = 0;
        while (ft_isdigit(line[i]))
        {
            buffer[j] = line[i];
            i++;
            j++;
        }
        if (buffer)
        {
            dest[texture_index] = ft_atoi(buffer);
            texture_index++;
        }
        buffer = NULL;
        i++;
    }
}

int parse_texture(char **file, t_map *map)
{
    int i;

    i = 0;
    while(file[i][0] != '1' || ' ')
    {
        if (file[i][j] == '\0')
            i++;
        if (!ft_strncmp(file[i]), "NO", 2)
            map->textures[0] = ft_strdup(file[i] + 3);
       else  if (!ft_strncmp(file[i]), "SO", 2)
            map->textures[1] = ft_strdup(file[i] + 3);
        else if (!ft_strncmp(file[i]), "WE", 2)
            map->textures[2] = ft_strdup(file[i] + 3);
        else if (!ft_strncmp(file[i]), "EA", 2)
            map->textures[3] = ft_strdup(file[i] + 3);
        else if (!ft_strncmp(file[i]), "F", 1)
            rgb_parse(file[i], map->floor_rgb);
        else if (!ft_strncmp(file[i]), "F", 1)
            rgb_parse(file[i], map->ceil_rgb);
        i++;
    }
    return (i);
}

void    separate_map(char **file)
{
    int i;
    char    **map;
    int j;

    i = parse_texture(file, map);
    j = 0;
    while (file[i] != NULL)
        map[j++] = ft_strdup(file[i++]);
    return (map);
}

