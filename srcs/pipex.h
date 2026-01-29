/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtas <amurtas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:19:26 by amurtas           #+#    #+#             */
/*   Updated: 2026/01/29 16:15:25 by amurtas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "ft_printf/ft_printf.h"
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_pip_struct
{
	char	**envar;
}	t_pip_struct;

char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_putstr_fd(char *s, int fd);
void	ft_command_error(char **tab, char **path);
void	ft_free_tab(char **tab);
char	*ft_strchr(const char *s, int c);
void	ft_execute(char *argv, char **envp, int fd[2]);
void	close_and_wait_all(int fd[2], int wait, pid_t pid1, pid_t pid2);

#endif