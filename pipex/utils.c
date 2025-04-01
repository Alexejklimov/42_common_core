/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:48:57 by oklimov           #+#    #+#             */
/*   Updated: 2025/02/26 17:07:28 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_struct(t_pipex *pipex)
{
	if (pipex->cmd_paths[0])
		free(pipex->cmd_paths[0]);
	if (pipex->cmd_paths[1])
		free(pipex->cmd_paths[1]);
	if (pipex->cmd1)
		free_array(pipex->cmd1);
	if (pipex->cmd2)
		free_array(pipex->cmd2);
	free(pipex);
}

void	free_array(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
