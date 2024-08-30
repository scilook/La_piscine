/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 16:00:48 by hyeson            #+#    #+#             */
/*   Updated: 2024/08/30 14:00:05 by hyeson           ###   ########.fr       */
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

int	find_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
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

unsigned int	word_counter(char *str, char *charset)
{
	int	i;
	int	cnt;
	int	inset;

	i = 0;
	cnt = 0;
	inset = 1;
	while (str[i] != '\0')
	{
		if (inset == 1 && find_in_base(str[i], charset) == -1)
		{
			cnt++;
			inset = 0;
		}
		if (inset == 0 && find_in_base(str[i], charset) != -1)
		{
			inset = 1;
		}
		i++;
	}
	return (cnt);
}

char	**ft_split(char *str, char *charset)
{
	char	**strs;
	char	*start;
	char	*end;
	int		i;

	strs = (char **)malloc(sizeof(char *) * (word_counter(str, charset) + 1));
	start = ft_strdup(str);
	i = 0;
	while (*start != '\0')
	{
		while (find_in_base(start[i], charset) > -1)
			i++;
		end = start + i;
		*end = 0;
		if (ft_strlen(start) == 0)
			i--;
		else
			strs[i] = ft_strdup(start);
		while (find_in_base(start[i], charset) != -1)
			i++;
		start = end + i;
		i++;
	}
	strs[i] = 0;
	return (strs);
}
