/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtas <amurtas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:42:06 by amurtas           #+#    #+#             */
/*   Updated: 2026/02/03 16:47:05 by amurtas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_close_all(int fd[2], int file)
{
	if (fd[0] != -1)
		close(fd[0]);
	if (fd[1] != -1)
		close(fd[1]);
	if (file != -1)
		close(file);
}

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	cs;

	cs = (unsigned char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == cs)
			return ((char *)s + i);
		i++;
	}
	if (cs == 0 && !s[i])
		return ((char *)s + i);
	return (NULL);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*s_cpy;

	s_cpy = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		s_cpy[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*var;

	if (nmemb == 0 || size == 0)
	{
		var = malloc(0);
		if (!var)
			return (NULL);
		return (var);
	}
	if (nmemb > (size_t)-1 / size)
		return (NULL);
	var = malloc(size * nmemb);
	if (!var)
		return (NULL);
	ft_bzero(var, size * nmemb);
	return (var);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*cs;

	if (!s1 || !s2)
		return (NULL);
	cs = ft_calloc(sizeof(char), (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!cs)
		return (NULL);
	i = 0;
	while ((s1)[i] != '\0')
	{
		cs[i] = (s1)[i];
		i++;
	}
	i = 0;
	while ((s2)[i] != '\0')
	{
		cs[ft_strlen(s1) + i] = (s2)[i];
		i++;
	}
	cs[ft_strlen(s1) + i] = '\0';
	return (cs);
}
