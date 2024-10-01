/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 16:27:44 by hyeson            #+#    #+#             */
/*   Updated: 2024/08/25 11:08:59 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	cnt;
	int	factorial;

	if (nb < 0)
		return (0);
	cnt = 1;
	factorial = 1;
	while (cnt < nb)
		factorial *= ++cnt;
	return (factorial);
}
