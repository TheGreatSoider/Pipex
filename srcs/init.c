/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cocheong <cocheong@student.42kl.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 20:19:40 by cocheong          #+#    #+#             */
/*   Updated: 2022/12/04 20:19:40 by cocheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	init(int ac, char **av, char **envp, t_pipex *pipex)
{
	char	*infile;
	char	*outfile;

	infile = av[1];
	outfile = av[ac - 1];
	pipex->infilefd = open(infile, O_RDONLY);
	if (pipex->infilefd == -1)
	{
		perror(infile);
		exit(EXIT_FAILURE);
	}
	pipex->outfilefd = open(outfile, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (pipex->outfilefd == -1)
	{
		perror(infile);
		exit(EXIT_FAILURE);
	}
	pipex->envp_path = find_path(envp);
	pipex->all_cmd_path = find_cmd_path(pipex->envp_path);
}
