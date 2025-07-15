/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:01:28 by oklimov           #+#    #+#             */
/*   Updated: 2025/03/04 11:51:50 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <string.h>
# include <stdio.h>
# include <errno.h>

# include "libft/libft.h"
# include "printf/ft_printf.h"

# define SUCCESS "\e[1;42m SUCCESS \e[0m \n"
# define ERR_INFILE "\e[1;41m ERROR infile \e[0m"
# define ERR_OUTFILE "\e[1;41m ERROR outfile \e[0m"
# define ERR_INPUT "\e[1;41m ./pipex infile cmd1 cmd2 outfile \e[0m \n"
# define ERR_PIPE "\e[1;41m ERROR pipe \e[0m"
# define ERR_FORK "\e[1;41m ERROR fork \e[0m"
# define ERR_1CMD "\e[1;41m ERROR first command invalid \e[0m \n"
# define ERR_2CMD "\e[1;41m ERROR second command invalid \e[0m \n"
# define ERR_CMD "\e[1;41m ERROR Command not found \e[0m \n"

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	int		fd[2];
	int		dup1[2];
	int		dup2[2];
	int		infile;
	int		outfile;
	int		status1;
	int		status2;
	int		flag;
	char	*tmp;
	char	**tmp_arr;
	char	*command;
	char	*cmd_paths[2];
	char	**cmd1;
	char	**cmd2;
}	t_pipex;

void	free_struct(t_pipex *pipex);
void	free_array(char **arr);
int		cmd_verify(char *cmd, char **envp, t_pipex *pipex, int flag);
int		check_access(char *path, char *cmd, t_pipex *pipex, int flag);
int		args_verify(int ac, char **av, char **envp, t_pipex *pip);
int		cmds_exist(const char *cmd1, const char *cmd2);
int		files_exist(const char *infile);
void	first_child(t_pipex *pip, char **envp);
void	second_child(t_pipex *pip, char **envp);

#endif
