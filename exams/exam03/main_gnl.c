/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:43:29 by oklimov           #+#    #+#             */
/*   Updated: 2025/03/24 13:51:50 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnl/get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char	*name;
	int		fd;
	char	*line;

	name = "../../mains/1char.txt";
	fd = open(name, O_RDONLY);
	line = "0";
	while (line)
	{
		line = get_next_line(fd);
		printf("--> %s", line);
		free(line);
	}
	return (0);
}
