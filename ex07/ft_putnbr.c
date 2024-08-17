/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:00:36 by hyeson            #+#    #+#             */
/*   Updated: 2024/08/17 16:35:47 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	chnbr[10];
	int		i;

	i = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb == 0)
		write(1, "0", 1);
	if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
	}
	while (nb != 0)
	{
		chnbr[i++] = nb % 10 + 0x30;
		nb /= 10;
	}
	while (i != 0)
		write(1, &chnbr[--i], 1);
}

int	main()
{
	ft_putnbr(0x77777777);
	return (0);
}
