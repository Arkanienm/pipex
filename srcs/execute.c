/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtas <amurtas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 15:35:03 by amurtas           #+#    #+#             */
/*   Updated: 2026/01/30 17:25:03 by amurtas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	find_path(char **tab, char **envp)
{
	int	i;
	int	stop;

	i = 0;
	stop = 0;
	if (!tab || !tab[i])
	{
		ft_free_tab(tab);
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
		return (-1);
	return (i);
}

void	ft_pathing(char **tab, char **envp)
{
	if (access(tab[0], X_OK) == 0)
		execve(tab[0], tab, envp);
	ft_command_error(tab, NULL);
}

int	ft_execute(char *argv, char **envp)
{
	char	**tab;
	char	**path;
	char	*str_path;
	char	*tmp_path;
	int		i;

	path = NULL;
	i = 0;
	tab = ft_split(argv, ' ');
	i = find_path(tab, envp);
	if (i == -1)
		ft_pathing(tab, envp);
	path = ft_split(envp[i] + 5, ':');
	i = 0;
	while (path[i++])
	{
		tmp_path = ft_strjoin(path[i], "/");
		str_path = ft_strjoin(tmp_path, tab[0]);
		free(tmp_path);
		if (str_path && access(str_path, F_OK | X_OK) == 0)
			execve(str_path, tab, envp);
		free(str_path);
	}
	ft_command_error(tab, path);
	return (0);
}
