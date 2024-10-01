/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 21:54:09 by hyeson            #+#    #+#             */
/*   Updated: 2024/08/25 12:58:30 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	unsigned int	i;
	unsigned int	j;

	if (nb <= 1)
		return (0);
	i = 1;
	while (i * i <= (unsigned int)nb)
		i++;
	j = 2;
	while (j < i)
		if (nb % j++ == 0)
			return (0);
	return (1);
}
