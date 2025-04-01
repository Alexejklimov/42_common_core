/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:01:22 by oklimov           #+#    #+#             */
/*   Updated: 2025/03/04 12:17:38 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_child(t_pipex *pip, char **envp)
{
	pip->pid1 = fork();
	if (pip->pid1 == -1)
	{
		ft_printf(ERR_FORK);
		free_struct(pip);
		exit (1);
	}
	if (pip->pid1 == 0)
	{
		close(pip->fd[0]);
		dup2(pip->infile, STDIN_FILENO);
		dup2(pip->fd[1], STDOUT_FILENO);
		close(pip->fd[1]);
		if (execve(pip->cmd_paths[0], pip->cmd1, envp) == -1)
		{
			ft_printf(ERR_1CMD);
			free_struct(pip);
			exit(1);
		}
	}
}

void	second_child(t_pipex *pip, char **envp)
{
	pip->pid2 = fork();
	if (pip->pid2 == -1)
	{
		perror(ERR_FORK);
		free_struct(pip);
		exit (1);
	}
	if (pip->pid2 == 0)
	{
		close(pip->fd[1]);
		dup2(pip->fd[0], STDIN_FILENO);
		dup2(pip->outfile, STDOUT_FILENO);
		close(pip->fd[0]);
		if (execve(pip->cmd_paths[1], pip->cmd2, envp) == -1)
		{
			perror(ERR_2CMD);
			free_struct(pip);
			exit(1);
		}
	}
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	*pip;
	int		flag;

	if (ac != 5 || files_exist(av[1]) != 0 || cmds_exist(av[2], av[3]) != 0)
		return (ft_printf(ERR_INPUT), 0);
	pip = malloc(sizeof(t_pipex));
	flag = args_verify(ac, av, envp, pip);
	if (flag != 0)
		return (free_struct(pip), flag);
	if (pipe(pip->fd) == -1)
		return (perror(ERR_PIPE), 1);
	first_child(pip, envp);
	second_child(pip, envp);
	close(pip->fd[0]);
	close(pip->fd[1]);
	waitpid(pip->pid1, &pip->status1, 0);
	waitpid(pip->pid2, &pip->status2, 0);
	if (WIFEXITED(pip->status1) && WIFEXITED(pip->status2))
	{
		if (WEXITSTATUS(pip->status1) >= 0 && WEXITSTATUS(pip->status2) == 0)
			return (free_struct(pip), 0);
		else
			return (free_struct(pip), 1);
	}
	return (free_struct(pip), 0);
}
