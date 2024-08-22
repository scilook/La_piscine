/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:51:55 by hyeson            #+#    #+#             */
/*   Updated: 2024/08/20 13:05:30 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	int				i;
	char			digits_of_non_printable[3];
	unsigned char	*unsignedstr;

	digits_of_non_printable[0] = '\\';
	unsignedstr = str;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 0x20 && str[i] <= 0x7E)
			write(1, &str[i], 1);
		else
		{
			if (str[i] / 0x10 < 0x0A)
				digits_of_non_printable[1] = unsignedstr[i] / 0x10 + 0x30;
			else
				digits_of_non_printable[1] = unsignedstr[i] / 0x10 - 0x0A + 'a';
			if (str[i] % 0x10 < 0x0A)
				digits_of_non_printable[2] = unsignedstr[i] % 0x10 + 0x30;
			else
				digits_of_non_printable[2] = unsignedstr[i] % 0x10 - 0x0A + 'a';
			write(1, digits_of_non_printable, 3);
		}
	}
}
