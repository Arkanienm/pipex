/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtas <amurtas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:42:06 by amurtas           #+#    #+#             */
/*   Updated: 2026/01/27 15:42:17 by amurtas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strdup(const char *s)
{
	char	*cpy;
	int		i;

	i = ft_strlen(s);
	cpy = malloc (sizeof(char) * (i + 1));
	if (!cpy)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		cpy[i] = s[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*sc1;
	unsigned char	*sc2;

	sc1 = (unsigned char *)s1;
	sc2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (sc1[i] && sc2[i] && i < n - 1 && sc1[i] == sc2[i])
		i++;
	return (sc1[i] - sc2[i]);
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_command_error(char **tab, char **path)
{
	ft_putstr_fd("command not found :", 2);
	ft_putstr_fd(tab[0], 2);
	ft_putstr_fd("\n", 2);
	ft_free_tab(tab);
	ft_free_tab(path);
	exit(127);
}
