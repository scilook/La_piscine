/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:08:43 by hyeson            #+#    #+#             */
/*   Updated: 2024/08/24 10:27:26 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	cnt;

	cnt = 0;
	while (*(str + cnt) != '\0')
		cnt++;
	return (cnt);
}

void	*base_encoder(long long int n, char *base)
{
	int		radix;
	int		i;
	char	chnbr[32];

	i = 0;
	radix = ft_strlen(base);
	if (n == 0)
		write(1, &base[0], 1);
	if (n < 0)
	{
		n = -n;
		write(1, "-", 1);
	}
	while (n != 0)
	{
		chnbr[i++] = base[n % radix];
		n /= radix;
	}
	while (i != 0)
		write(1, &chnbr[--i], 1);
}

int	ft_error(char *base)
{
	int	i;
	int	j;

	i = -1;
	while (++i < ft_strlen(base))
	{
		j = i;
		while (j < ft_strlen(base))
			if (base[i] == base[++j])
				return (1);
		if (base[i] == '+' || base[i] == '-')
			return (1);
	}
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	if (ft_strlen(base) > 1 && ft_error(base) == 0)
		base_encoder(nbr, base);
}
