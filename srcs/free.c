/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cocheong <cocheong@student.42kl.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 22:25:00 by cocheong          #+#    #+#             */
/*   Updated: 2022/12/04 22:25:00 by cocheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	free_parent(t_pipex *pipex)
{
	int	i;

	i = 0;
	close(pipex->infilefd);
	close(pipex->outfilefd);
	while (pipex->all_cmd_path[i])
	{
		free(pipex->all_cmd_path[i]);
		i++;
	}
	free(pipex->all_cmd_path);
}

void	free_child(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->cmd_args[i])
	{
		free(pipex->cmd_args[i]);
		i++;
	}
	free(pipex->cmd_args);
	free(pipex->cmd_path);
}
