/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:09:47 by oklimov           #+#    #+#             */
/*   Updated: 2025/02/18 17:10:17 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	read_move(int key, t_play *play)
{
	if (key == ESC)
		mlx_loop_end(play->mlx);
	if (key == W)
		make_move(play, 0, -1);
	if (key == A)
		make_move(play, -1, 0);
	if (key == D)
		make_move(play, 1, 0);
	if (key == S)
		make_move(play, 0, 1);
	return (0);
}

void	make_move(t_play *play, int horis, int vert)
{
	if (play->map[play->start_pos[0] + vert][play->start_pos[1] + horis] != '1')
	{
		if (play->map[play->start_pos[0] + vert][play->start_pos[1] + horis]
			== 'E' && play->collect == play->collected)
		{
			mlx_loop_end(play->mlx);
			ft_printf("\n       YOU WIN!!!\n      Total ");
		}
		if (play->map[play->start_pos[0] + vert][play->start_pos[1] + horis]
			== 'C')
		{
			play->collected++;
		}
		if (play->collect == play->collected)
			play->map[play->exit_pos[0]][play->exit_pos[1]] = 'E';
		play->map[play->start_pos[0]][play->start_pos[1]] = '0';
		play->start_pos[0] += vert;
		play->start_pos[1] += horis;
		play->map[play->start_pos[0]][play->start_pos[1]] = 'P';
		play->steps++;
		ft_printf("Steps %d\n", play->steps);
	}
	fill_window(play, play->mlx, play->win_mlx);
}

void	fill_t_play(t_map *game, t_play *play)
{
	int	hei;
	int	wid;
	int	i;

	i = -1;
	while (++i <= IMG_COUNT)
		play->img[i] = NULL;
	play->img[0] = mlx_xpm_file_to_image(play->mlx, FLOOR, &wid, &hei);
	play->img[1] = mlx_xpm_file_to_image(play->mlx, PLAYER, &wid, &hei);
	play->img[2] = mlx_xpm_file_to_image(play->mlx, PIZZA0, &wid, &hei);
	play->img[3] = mlx_xpm_file_to_image(play->mlx, WALL, &wid, &hei);
	play->img[4] = mlx_xpm_file_to_image(play->mlx, EXIT0, &wid, &hei);
	play->steps = 0;
	play->collected = 0;
	play->collect = game->collect;
	play->x = game->x - 1;
	play->y = game->y;
	play->start_pos[0] = game->start_pos[0];
	play->start_pos[1] = game->start_pos[1];
	play->exit_pos[0] = game->exit_pos[0];
	play->exit_pos[1] = game->exit_pos[1];
}

void	fill_window(t_play	*play, void	*mlx, void *win)
{
	int	x;
	int	y;

	y = 0;
	while (play->map[y] != NULL)
	{
		x = 0;
		while (play->map[y][x] != '\0')
		{
			if (play->map[y][x] == '1')
				mlx_put_image_to_window(mlx, win, play->img[3], x * 64, y * 64);
			if (play->map[y][x] == '0' || (play->map[y][x] == 'E'
				&& play->collect != play->collected))
				mlx_put_image_to_window(mlx, win, play->img[0], x * 64, y * 64);
			if (play->map[y][x] == 'P')
				mlx_put_image_to_window(mlx, win, play->img[1], x * 64, y * 64);
			if (play->map[y][x] == 'C')
				mlx_put_image_to_window(mlx, win, play->img[2], x * 64, y * 64);
			if (play->map[y][x] == 'E' && play->collect == play->collected)
				mlx_put_image_to_window(mlx, win, play->img[4], x * 64, y * 64);
			x++;
		}
		y++;
	}
}
