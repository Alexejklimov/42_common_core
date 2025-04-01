/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:11:39 by oklimov           #+#    #+#             */
/*   Updated: 2025/02/18 15:01:43 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	position_filler(char **map, t_map *game)
{
	int	x;
	int	y;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'E')
			{
				game->exit_pos[0] = y;
				game->exit_pos[1] = x;
			}
			if (map[y][x] == 'P')
			{
				game->start_pos[0] = y;
				game->start_pos[1] = x;
			}
			x++;
		}
		y++;
	}
}

char	*ft_strcpy(char	*dest, char	*src)

{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++ ;
	}
	dest[i] = '\0';
	return (dest);
}
