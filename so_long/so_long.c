/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:55:48 by oklimov           #+#    #+#             */
/*   Updated: 2025/02/18 15:03:12 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_check_arg(char *mapname, char *ber)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(mapname) - 4;
	while (mapname[j] != '\0' && ber[i] != '\0' && mapname[j] == ber[i])
	{
		i++;
		j++;
	}
	return (mapname[j] - ber[i]);
}

int	main(int ac, char **av)
{
	static t_map	*game;
	static t_play	*play;

	if (ac != 2 || ft_check_arg(av[1], ".ber") != 0)
		return (ft_printf(" Error\n Map path/name is not valid\n"));
	game = malloc(sizeof(t_map));
	play = malloc(sizeof(t_play));
	map_create(av[1], game, play);
	play->mlx = mlx_init();
	if (!play->mlx)
		return (1);
	fill_t_play(game, play);
	play->win_mlx = mlx_new_window(play->mlx, (play->x) * PXL,
			(play->y) * PXL, "so_long");
	if (!play->win_mlx)
		return (free(play->mlx), 1);
	fill_window(play, play->mlx, play->win_mlx);
	mlx_hook(play->win_mlx, 17, (1L << 17), &mlx_loop_end, play->mlx);
	mlx_hook(play->win_mlx, KeyPress, KeyPressMask, &read_move, play);
	mlx_loop(play->mlx);
	exit_game(game, play);
	return (0);
}
