/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 21:05:13 by hyeson            #+#    #+#             */
/*   Updated: 2024/08/24 22:23:36 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	cnt;

	cnt = 1;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (++cnt < power)
		nb *= nb;
	return (nb);
}
