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
	while (src[i] != '\0')
		i++;
	p = (char *)malloc(i + 1);
	i = 0;
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
	int		j;

	i = 0;
	strs = (char **)malloc(sizeof(char *) * (word_counter(str, charset) + 1));
	start = ft_strdup(str);
	while (find_in_base(str[i], charset) != -1 && str[i] != 0)
	{
		start++;
		i++;
	}
	j = 0;
	while (str[i] != 0)
	{
		end = start;
		while (find_in_base(str[i], charset) == -1 && str[i] != 0)
		{
			end++;
			i++;
		}
		*end = 0;
		strs[j++] = ft_strdup(start);
		*end = charset[0];
		start = end;
		while (find_in_base(str[i], charset) != -1 && str[i] != 0)
		{
			start++;
			i++;
		}
	}
	strs[j] = 0;
	return (strs);
}
