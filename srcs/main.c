/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cocheong <cocheong@student.42kl.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 23:54:16 by cocheong          #+#    #+#             */
/*   Updated: 2022/12/04 23:54:16 by cocheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	create_pipe(t_pipex *pipex)
{
	int	status;

	status = pipe(pipex->pipefd);
	if (status == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
}

void	run_child_process(char **av, char **envp, t_pipex *pipex)
{
	pipex->pid1 = fork();
	if (pipex->pid1 != 0)
		first_child_process(av, envp, pipex);
	pipex->pid2 = fork();
	if (pipex->pid2 != 0)
		second_child_process(av, envp, pipex);
}

void	close_pipe(t_pipex	*pipex)
{
	close(pipex->pipefd[0]);
	close(pipex->pipefd[1]);
}

void	waitpid_childs(t_pipex *pipex)
{
	waitpid(pipex->pid1, NULL, 0);
	waitpid(pipex->pid2, NULL, 0);
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	pipex;

	if (ac != 5)
		ft_putstr_fd("Error: Invalid no. of arguments\n", STDERR);
	else
	{
		init(ac, av, envp, &pipex);
		create_pipe(&pipex);
		run_child_process(av, envp, &pipex);
		close_pipe(&pipex);
		waitpid_childs(&pipex);
		free_parent(&pipex);
	}
	return (0);
}
