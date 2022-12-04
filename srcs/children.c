/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cocheong <cocheong@student.42kl.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 22:16:05 by cocheong          #+#    #+#             */
/*   Updated: 2022/12/04 22:16:05 by cocheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	first_child_process(char **av, char **envp, t_pipex *pipex)
{
	dup2(pipex->infilefd, STDIN);
	dup2(pipex->pipefd[1], STDOUT);
	close_pipe(pipex);
	pipex->cmd_args = split_cmd(av[2]);
	pipex->cmd_path = get_cmd_path(pipex->all_cmd_path, pipex->cmd_args[0]);
	if (pipex->cmd_path == 0)
	{
		free_child(pipex);
		perror("command not found");
		exit(EXIT_FAILURE);
	}
	execve(pipex->cmd_path, pipex->cmd_args, envp);
}

void	second_child_process(char **av, char **envp, t_pipex *pipex)
{
	dup2(pipex->pipefd[0], STDIN);
	dup2(pipex->outfilefd, STDOUT);
	close_pipe(pipex);
	pipex->cmd_args = split_cmd(av[3]);
	pipex->cmd_path = get_cmd_path(pipex->all_cmd_path, pipex->cmd_args[0]);
	if (pipex->cmd_path == 0)
	{
		free_child(pipex);
		perror("command not found");
		exit(EXIT_FAILURE);
	}
	execve(pipex->cmd_path, pipex->cmd_args, envp);
}
