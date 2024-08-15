/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn copy.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 19:05:19 by hyeson            #+#    #+#             */
/*   Updated: 2024/08/15 15:54:42 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_combn_lines(int *n, int *i, char *chnbr)
{
	*i = *n - 1;
	while (chnbr[*i] < 0x3A)
	{
		write(1, chnbr, *n);
		write(1, ", ", 2);
		chnbr[*n - 1]++;
	}
}

void	ft_print_combn(int n)
{
	char	chnbr[10];
	int		i;
	int		j;

	i = 0;
	chnbr[0] = 0x30;
	while (chnbr[0] < 0x3A - n)
	{
		j = i;
		while (j > 0)
		{
			if (chnbr[j--] >= 0x3A)
			{
				chnbr[j]++;
				i--;
			}
		}
		while (chnbr[i] < 0x39)
		{
			chnbr[i + 1] = chnbr[i] + 1;
			i ++;
		}
		ft_print_combn_lines(&n, &i, chnbr);
	}
	write(1, "\b\b", 2);
}
