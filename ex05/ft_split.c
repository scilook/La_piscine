/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 16:00:48 by hyeson            #+#    #+#             */
/*   Updated: 2024/08/29 17:52:16 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

int	ft_strlen(char *str)
{
	int	cnt;

	cnt = 0;
	while (*(str + cnt) != '\0')
		cnt++;
	return (cnt);
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = -1;
	if (ft_strlen(s1) > ft_strlen(s2))
	{
		while (s1[++i] != '\0' && i < n)
			if (s1[i] != s2[i])
				return (s1[i] - s2[i]);
	}
	else
	{
		while (s2[++i] != '\0' && i < n)
			if (s1[i] != s2[i])
				return (s1[i] - s2[i]);
	}
	return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;

	i = -1;
	if (to_find[0] == '\0')
		return (str);
	while (str[++i] != '\0')
		if (to_find[0] == str[i])
			if (ft_strncmp(to_find, str + i, ft_strlen(to_find)) == 0)
				return (str + i);
	return ("\0");
}

char	*ft_strdup(char *src)
{
	char	*p;
	int		i;

	i = 0;
	p = (char *)malloc(ft_strlen(src) + 1);
	while (src[i] != '\0')
	{
		p[i] = src[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
/* 해야할 일: strs 버퍼크기 구해주기. word count가 필요. */
char **ft_split(char *str, char *charset)
{
	char	**strs;
	char	*start;
	char	*end;
	int		i;

	start = ft_strdup(str);
	i = 0;
	while (end == '\0')
	{
		end = ft_strstr(start, charset);
		if (end == '\0')
		*end = '\0';
		if (ft_strlen(start) == 0)
			i--;
		else
			strs[i] = ft_strdup(start);
		start = end + ft_strlen(charset);
		i++;
	}
}
