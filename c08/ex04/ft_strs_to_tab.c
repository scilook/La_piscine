/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 02:09:37 by hyeson            #+#    #+#             */
/*   Updated: 2024/08/28 15:07:31 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	cnt;

	cnt = 0;
	while (*(str + cnt) != '\0')
		cnt++;
	return (cnt);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (*(src + i) != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*point;

	if (ac < 0 || av == 0)
		return (NULL);
	point = malloc((ac + 1) * sizeof(t_stock_str));
	i = 0;
	while (i < ac)
	{
		point[i].size = ft_strlen(av[i]);
		point[i].str = av[i];
		point[i].copy = (char *)malloc(sizeof(char) * (ft_strlen(av[i]) + 1));
		ft_strcpy(point[i].copy, av[i]);
		i++;
	}
	point[i].size = 0;
	point[i].str = 0;
	point[i].copy = 0;
	return (point);
}
