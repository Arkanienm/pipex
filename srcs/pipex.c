/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtas <amurtas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:40:05 by amurtas           #+#    #+#             */
/*   Updated: 2026/01/30 13:16:25 by amurtas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_and_wait_all(int fd[2], int wait, pid_t pid1, pid_t pid2)
{
	if (fd[0] != -1)
		close(fd[0]);
	if (fd[1] != -1)
		close(fd[1]);
	fd[0] = -1;
	fd[1] = -1;
	if (wait == 1)
	{
		waitpid(pid1, NULL, 0);
		waitpid(pid2, NULL, 0);
	}
}

void	first_child(int fd[2], char **argv, char **envp)
{
	int	infile;

	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
	{
		perror("open infile failed");
		ft_close_all(fd, infile);
		exit(1);
	}
	dup2(infile, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close_and_wait_all(fd, 0, 0, 0);
	if (infile != -1)
		ft_close_all(fd, infile);
	infile = -1;
	if (ft_execute(argv[2], envp) == 0)
		ft_close_all(fd, infile);
}

void	second_child(int fd[2], char **argv, char **envp)
{
	int	outfile;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile == -1)
	{
		perror("open outfile failed");
		ft_close_all(fd, outfile);
		exit(1);
	}
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close_and_wait_all(fd, 0, 0, 0);
	if (outfile != -1)
		close(outfile);
	outfile = -1;
	if (ft_execute(argv[3], envp) == 0)
		ft_close_all(fd, outfile);
}

void	check_pid(pid_t	pid)
{
	if (pid < 0)
	{
		perror("failed fork");
		exit(1);
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
		perror("failed pipe");
		ft_close_all(fd, -1);
		exit(1);
	}
	pid1 = fork();
	check_pid(pid1);
	if (pid1 == 0)
		first_child(fd, argv, envp);
	pid2 = fork();
	check_pid(pid2);
	if (pid2 == 0)
		second_child(fd, argv, envp);
	close_and_wait_all(fd, 1, pid1, pid2);
	return (0);
}
