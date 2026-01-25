/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtas <amurtas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:42:06 by amurtas           #+#    #+#             */
/*   Updated: 2026/01/25 18:22:37 by amurtas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s[i] == '\0')
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

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