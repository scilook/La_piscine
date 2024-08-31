/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 19:51:28 by hyeson            #+#    #+#             */
/*   Updated: 2024/08/29 17:02:33 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*p;
	int	i;
	int	mini;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	p = (int *)malloc(sizeof(int) * (max - min));
	if (p == 0)
		return (-1);
	*range = p;
	mini = min;
	i = 0;
	while (i < max - min)
	{
		p[i] = mini++;
		i++;
	}
	return (max - min);
}
