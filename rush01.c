/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 09:55:08 by haeyekim          #+#    #+#             */
/*   Updated: 2024/08/13 20:10:44 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	rush_print(int x, int y, int i, int j)
{
	if (i == 0)
	{
		if (j == 0)
			ft_putchar('/');
		else if (j == x - 1)
			ft_putchar('\\');
		else
			ft_putchar('*');
	}
	else if (i == (y - 1))
	{
		if (j == 0)
			ft_putchar('\\');
		else if (j == x - 1)
			ft_putchar('/');
		else
			ft_putchar('*');
	}
	else
	{
		if (j == 0 || j == (x - 1))
			ft_putchar('*');
		else
			ft_putchar(' ');
	}
}

void	rush(int x, int y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < y)
	{
		while (j < x)
		{
			rush_print(x, y, i, j);
			j++;
		}
		ft_putchar('\n');
		i++;
		j = 0;
	}
}
