/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtas <amurtas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:40:05 by amurtas           #+#    #+#             */
/*   Updated: 2026/01/25 18:30:42 by amurtas          ###   ########.fr       */
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

void	ft_execute(char **argv, char **envp)
{
	char **tab;
	char **path;
	int i;
	int stop;

	stop = 0;
	i = 0;
	tab = ft_split(argv[2], ' ');
	while (envp[i] && stop == 0)
	{
		if (ft_strncmp(envp[i], "PATH", 4) == 0);
			stop = 1;
	}
	path = ft_split(envp[i], ':');
	
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	int		infile;
	pid_t	pid1;
	pid_t	pid2;

	if (argc != 5)
		return (1);
	if (pipe(fd) == -1)
		perror("failed pipe");
	pid1 = fork();
	if (pid1 < 0)
	{
		perror("failed fork");
		return (1);
	}
	if (pid1 == 0)
	{
		infile = open(argv[1], O_RDONLY);
		if (infile == -1)
		{
			perror("open failed");
			return (1);
		}
		dup2(infile, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		close (infile);
	}
}
