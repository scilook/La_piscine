/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 13:37:15 by hyeson            #+#    #+#             */
/*   Updated: 2024/08/15 18:06:00 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void)
{
	int	i;
	int	j;
	int	digits_of_i[2];
	int	digits_of_j[2];

	i = 0;
	while (i < 100)
	{
		j = i + 1;
		digits_of_i[0] = i / 10 + 0x30;
		digits_of_i[1] = i % 10 + 0x30;
		while (j < 100)
		{
			digits_of_j[0] = j / 10 + 0x30;
			digits_of_j[1] = j % 10 + 0x30;
			write(1, digits_of_i, 8);
			write(1, " ", 1);
			write(1, digits_of_j, 8);
			if (i * j != 98 * 99)
				write(1, ", ", 2);
			j++;
		}
		i++;
	}
}
