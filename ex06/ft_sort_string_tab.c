/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 16:18:09 by hyeson            #+#    #+#             */
/*   Updated: 2024/09/01 16:25:58 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	cnt;

	cnt = 0;
	while (*(str + cnt) != '\0')
		cnt++;
	return (cnt);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_sort_string_tab(char **tab)
{
	char	*tmp;
	int		i;
	int		j;

	j = 0;
	while (tab[++j] != 0)
	{
		i = j;
		while (i > 0)
		{
			tmp = tab[i];
			if (ft_strcmp(tab[i], tab[i - 1]) < 0)
			{
				tab[i] = tab[i - 1];
				tab[i - 1] = tmp;
			}
			else
				break ;
			i--;
		}
	}
}
