/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtas <amurtas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 09:45:46 by amurtas           #+#    #+#             */
/*   Updated: 2026/01/26 14:12:46 by amurtas          ###   ########.fr       */
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sbstr;

	i = 0;
	if (!s)
		return (NULL);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
	{
		sbstr = ft_strdup("");
		return (sbstr);
	}
	sbstr = malloc(sizeof(char) * len + 1);
	if (!sbstr)
		return (NULL);
	while (s[start + i] && i < len)
	{
		sbstr[i] = s[start + i];
		i++;
	}
	sbstr[i] = '\0';
	return (sbstr);
}

static int	ft_count_word(char const *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			word++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (word);
}

static void	*ft_free_all(char **str, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (str[i] == NULL)
		{
			while (n > 0)
			{
				n--;
				free(str[n]);
			}
			free(str);
			return (NULL);
		}
		i++;
	}
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		len;

	len = 0;
	i = 0;
	if (!s)
		return (NULL);
	str = malloc(sizeof (char *) * (ft_count_word(s, c) + 1));
	if (!str)
		return (NULL);
	while (*s)
	{
		len = 0;
		while (s[len] != c && s[len])
			len++;
		if (len)
			str[i++] = ft_substr(s, 0, len);
		while (s[len] == c && s[len])
			len++;
		s += len;
	}
	str[i] = NULL;
	str = ft_free_all(str, i);
	return (str);
}
