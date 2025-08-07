/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:07:08 by oklimov           #+#    #+#             */
/*   Updated: 2025/07/15 16:54:24 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_arg(char *mapname, char *ber)
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
	t_map_info	*map;

	map = calloc(sizeof(t_map_info), 1);
	if (ac != 2 || ft_check_arg(av[1], ".cub") != 0)
		return (ft_printf("Error\n Map path/name isn`t valid\n"));

	parse_map(av[1], map);
	return (0);
}



// 		map rules

// 5. dont give a shit if palyer can reach all areas.
// 6. make map rectangular

