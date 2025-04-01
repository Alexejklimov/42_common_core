/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argc_parcing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:01:23 by oklimov           #+#    #+#             */
/*   Updated: 2025/03/04 11:50:23 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_access(char *path, char *cmd, t_pipex *pipex, int flag)
{
	char	*full_path;
	char	*cmd_path;
	int		result;

	full_path = ft_strjoin(path, "/");
	cmd_path = ft_strjoin(full_path, cmd);
	result = access(cmd_path, X_OK);
	if (result == 0)
		pipex->cmd_paths[flag] = ft_strdup(cmd_path);
	free(full_path);
	free(cmd_path);
	return (result == 0);
}

int	cmd_verify(char *cmd, char **envp, t_pipex *pipex, int flag)
{
	int		i;

	while (*envp)
	{
		if (ft_strnstr(*envp, "PATH=", 5))
		{
			pipex->tmp_arr = ft_split(*envp + 5, ':');
			i = 0;
			while (pipex->tmp_arr[i])
			{
				if (check_access(pipex->tmp_arr[i], cmd, pipex, flag))
				{
					return (free_array(pipex->tmp_arr), 0);
				}
				i++;
			}
			free_array(pipex->tmp_arr);
		}
		envp++;
	}
	write(STDERR_FILENO, cmd, ft_strlen(cmd));
	write(STDERR_FILENO, ": Command not found\n", 20);
	return (1);
}

int	args_verify(int ac, char **av, char **envp, t_pipex *pip)
{
	pip->cmd_paths[0] = NULL;
	pip->cmd_paths[1] = NULL;
	pip->cmd1 = ft_split(av[2], ' ');
	pip->cmd2 = ft_split(av[3], ' ');
	pip->infile = open(av[1], O_RDONLY);
	if (pip->infile == -1)
		return (ft_printf(ERR_INFILE), 1);
	pip->outfile = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pip->outfile == -1)
		return (close(pip->infile), ft_printf(ERR_OUTFILE), 1);
	if (cmd_verify(pip->cmd1[0], envp, pip, 0) != 0)
		return (close(pip->infile), close(pip->outfile), 127);
	if (cmd_verify(pip->cmd2[0], envp, pip, 1) != 0)
		return (close(pip->infile), close(pip->outfile), 127);
	return (0);
}

int	files_exist(const char *infile)
{
	if (access(infile, F_OK) == -1)
	{
		ft_printf(ERR_INFILE);
		return (1);
	}
	return (0);
}

int	cmds_exist(const char *cmd1, const char *cmd2)
{
	if (ft_strlen(cmd1) == 0)
	{
		ft_printf(ERR_1CMD);
		return (127);
	}
	if (ft_strlen(cmd2) == 0)
	{
		ft_printf(ERR_2CMD);
		return (127);
	}
	return (0);
}
