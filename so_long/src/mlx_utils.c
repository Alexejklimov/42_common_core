/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:38:11 by oklimov           #+#    #+#             */
/*   Updated: 2025/02/18 15:02:22 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	exit_game(t_map *game, t_play *play)
{
	int	i;

	i = 0;
	while (play->img[i] != NULL)
	{
		mlx_destroy_image(play->mlx, play->img[i]);
		play->img[i] = NULL;
		i++;
	}
	if (play->mlx && play->win_mlx)
	{
		mlx_clear_window(play->mlx, play->win_mlx);
		mlx_destroy_window(play->mlx, play->win_mlx);
	}
	if (play->mlx)
	{
		mlx_destroy_display(play->mlx);
		free(play->mlx);
	}
	play->win_mlx = NULL;
	clean_all_structs(game, play);
}

void	clean_map(t_map *game)
{
	game->x = 0;
	game->y = 0;
	game->collect = 0;
	game->start_pos[0] = 0;
	game->start_pos[1] = 0;
	game->exit_pos[0] = 0;
	game->exit_pos[1] = 0;
	free(game);
}

void	clean_all_structs(t_map *game, t_play *play)
{
	play->x = 0;
	play->y = 0;
	play->collect = 0;
	play->collected = 0;
	play->steps = 0;
	play->start_pos[0] = 0;
	play->start_pos[1] = 0;
	play->exit_pos[0] = 0;
	play->exit_pos[1] = 0;
	free_map(play->map);
	free(play);
	clean_map(game);
	play = NULL;
	game = NULL;
}

void	free_map(char **map)
{
	int	y;

	if (map == NULL)
		return ;
	y = 0;
	while (map[y] != NULL)
	{
		free(map[y]);
		y++;
	}
	free(map);
	map = NULL;
}
