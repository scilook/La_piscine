/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 19:32:41 by hyeson            #+#    #+#             */
/*   Updated: 2024/08/25 19:50:00 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

int	*ft_range(int min, int max)
{
	int	*p;
	int	i;
	int	mini;

	if (min >= max)
		return (NULL);
	p = (int *)malloc(sizeof(int) * (max - min));
	mini = min;
	i = 0;
	while (i < max - min)
	{
		p[i] = mini++;
		i++;
	}
	return (p);
}
