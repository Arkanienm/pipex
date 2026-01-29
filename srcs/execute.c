/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtas <amurtas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 15:35:03 by amurtas           #+#    #+#             */
/*   Updated: 2026/01/29 16:16:33 by amurtas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	find_path(char **tab, char **envp, char **path, int fd[2])
{
	int	i;
	int	stop;

	i = 0;
	stop = 0;
	if (!tab || !tab[i])
	{
		ft_free_tab(tab);
		close_and_wait_all(fd, 0, 0, 0);
		exit(127);
	}
	if (ft_strchr(tab[0], '/') && access(tab[0], X_OK) == 0)
		execve(tab[0], tab, envp);
	while (envp[i] && stop == 0)
	{
		if (ft_strncmp(envp[i], "PATH", 4) == 0)
			stop = 1;
		else
			i++;
	}
	if (stop == 0)
		ft_command_error(tab, path);
	return (i);
}

void	ft_execute(char *argv, char **envp, int fd[2])
{
	char	**tab;
	char	**path;
	char	*str_path;
	char	*tmp_path;
	int		i;

	path = NULL;
	i = 0;
	tab = ft_split(argv, ' ');
	i = find_path(tab, envp, path, fd);
	path = ft_split(envp[i] + 5, ':');
	i = 0;
	while (path[i])
	{
		tmp_path = ft_strjoin(path[i], "/");
		str_path = ft_strjoin(tmp_path, tab[0]);
		free(tmp_path);
		if (access(str_path, F_OK | X_OK) == 0)
			execve(str_path, tab, envp);
		free(str_path);
		i++;
	}
	ft_command_error(tab, path);
}
