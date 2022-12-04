/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cocheong <cocheong@student.42kl.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 21:50:22 by cocheong          #+#    #+#             */
/*   Updated: 2022/12/04 21:50:22 by cocheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*find_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

char	**find_cmd_path(char *envp_path)
{
	char	**cmd_path;

	cmd_path = ft_split(envp_path, ':');
	return (cmd_path);
}

char	*get_cmd_path(char **cmd_paths, char *cmd)
{
	char	*usable_path;
	char	*command_path;

	while (*cmd_paths != 0)
	{
		usable_path = ft_strjoin(*cmd_paths, "/");
		command_path = ft_strjoin(usable_path, cmd);
		free(usable_path);
		if (access(command_path, F_OK | X_OK) == 0)
			return (command_path);
		free(command_path);
		cmd_paths++;
	}
	return (NULL);
}

char	**split_cmd(char *cmd)
{
	char	**cmd_split;

	cmd_split = ft_split(cmd, ' ');
	return (cmd_split);
}
