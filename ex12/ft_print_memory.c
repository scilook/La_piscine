/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 20:07:01 by hyeson            #+#    #+#             */
/*   Updated: 2024/08/20 13:17:39 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*first_column(void *addr, char *digits)
{
	int	i;

	i = 0;
	while (i < 8)
	{
	digits[14 - 2 * i] = *(char*)(addr + i) / 0x10 + '0';
	if (*(char*)(addr + i) % 0x10 < 0x0A)
		digits[15 - 2 * i] = *(char*)(addr + i) % 0x10 + '0';
	else
		digits[15 - 2 * i] = *(char*)(addr + i) % 0x10 - 0x0A + 'a';
	i++;
	}
	return (digits);
}

char	*second_column(void *addr, unsigned int *size, char *digits) /* size가 홀수면 쓰레기 값을 불러옴 */
{
	int	i;
	int	j;

	j = 0;
	while (j < 8)
	{
		i = 0;
		while (i < 2 && *size > 0) /* *addr는 stack?mem? */
		{
			digits[5 * j + 2 - 2 * i] = *(char*)(addr + i * j) / 0x10 + '0';
			if (*(char*)addr % 0x10 < 0x0A)
				digits[5 * j + 3 - 2 * i] = *(char*)(addr + i * j) % 0x10 + '0';
			else
				digits[5 * j + 3 - 2 * i] = *(char*)(addr + i * j) % 0x10 - 0x0A + 'a';
			i++;
		}
		digits[5 * i - 1] = ' ';
		*size = *size - 2;
		j++;
	}
	return (digits);
}

char	*third_column(void *addr, unsigned int size)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (*(char*)(addr + i) >= 0x20 && *(char*)(addr + i) <= 0x7E)
			write(1, addr + i, 1);
		else
			write(1, ".", 1);
		i++;

	}
}


void	*ft_print_memory(void *addr, unsigned int size)
{
	char	*digits;

	while (size > 0)
	{
		write(1, first_column(addr, digits), 16);
		write(1, ": ", 2);
		write(1, second_column(addr, &size, digits), 40); /* 몇너야됨? */
		third_column(addr, size);
		write(1, "\n", 1);
		addr = addr + 16;
	}
	return addr;
}
