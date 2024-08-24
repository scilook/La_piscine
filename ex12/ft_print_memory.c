/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 20:07:01 by hyeson            #+#    #+#             */
/*   Updated: 2024/08/24 16:58:16 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (*(src + i) != '\0')
		dest[i++] = src[i];
	dest[i] = src[i];
	return (dest);
}

void	*first_column(unsigned long long *addr)
{
	int	i;
	char base[17];
	char digits[16];
	unsigned long long address = (unsigned long long) addr;

	ft_strcpy(base, "0123456789abcdef");
	i = 0;
	while (i < 16)
	{
		digits[15 - i] = base[address % 0x10];
		address /= 0x10;
		i++;
	}
	write(1, digits, 16);
}

char	*second_column(char *addr, int size)
{
	int	i;
	char digits[2];
	char base[17];
	char *address;

	ft_strcpy(base, "0123456789abcdef");
	address = addr;
	i = -1;
	{
		if (i % 3 != 2)
		{
			if (size-- > 0)
			{
				digits[0] = base[*addr / 0x10];
				digits[1] = base[*(addr++) % 0x10];
				write(1, digits, 2);
			}
			else
				write(1, "  ", 2);
		}
		else
			write(1 , " ", 1);
	}

}

char	*third_column(char *addr, unsigned int size)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if ((addr + i) >= 0x20 && (addr + i) <= 0x7E)
			write(1, addr + i, 1);
		else
			write(1, ".", 1);
		i++;

	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned long long *address;

/* 	while (size > 0)
	{ */
		first_column(addr);
		write(1, ": ", 2);
		second_column(addr, (int) size);
/* 		third_column(addr, size);
 */		write(1, "\n", 1);
		size = size - 0x10;
/* 	}
 */}
컴파일 오류 ㅋㅋ