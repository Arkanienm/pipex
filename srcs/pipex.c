/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtas <amurtas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:40:05 by amurtas           #+#    #+#             */
/*   Updated: 2026/01/15 17:24:23 by amurtas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	extract_envp(char **envp, t_pip_struct *pipst)
{
	int	i;
	
	i = 0;
	while (envp[0][i])
	{
		pipst->envar[i] = ft_split(envp, ':');
		i++;
	}
	
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (argc != 5)
		return (1);
	if (pipe(fd) == -1)
	{
		perror("failed cloning");
	}
	
}
