/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:51:55 by hyeson            #+#    #+#             */
/*   Updated: 2024/08/24 20:03:31 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	int				i;
	char			digits_of_non_printable[3];
	char			*base;

	base = "0123456789abcdef";
	digits_of_non_printable[0] = '\\';
	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] >= 0x20 && str[i] <= 0x7E)
			write(1, &str[i], 1);
		else
		{
			digits_of_non_printable[1] = base[(unsigned char)str[i] / 0x10];
			digits_of_non_printable[2] = base[(unsigned char)str[i] % 0x10];
			write(1, digits_of_non_printable, 3);
		}
	}
}
