/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cocheong <cocheong@student.42kl.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 21:27:40 by cocheong          #+#    #+#             */
/*   Updated: 2022/11/29 21:27:40 by cocheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../../42_Libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>

# define STDIN 0
# define STDOUT 1
# define STDERR 2

typedef struct pipex
{
	pid_t	pid1;
	pid_t	pid2;
	int		pipefd[2];
	int		infilefd;
	int		outfilefd;
	char	*envp_path;
	char	**all_cmd_path;
	char	**cmd_args;
	char	*cmd_path;
}t_pipex;

void	close_pipe(t_pipex *pipex);
void	init(int ac, char **av, char**envp, t_pipex *pipex);
char	*find_path(char **envp);
char	**find_cmd_path(char *envp_path);
char	*get_cmd_path(char **cmd_paths, char *cmd);
char	**split_cmd(char *cmd);
void	first_child_process(char **av, char **envp, t_pipex *pipex);
void	second_child_process(char **av, char **envp, t_pipex *pipex);
void	free_parent(t_pipex *pipex);
void	free_child(t_pipex *pipex);

#endif