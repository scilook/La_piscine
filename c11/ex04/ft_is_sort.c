/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 14:29:30 by hyeson            #+#    #+#             */
/*   Updated: 2024/09/01 16:27:17 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_ascend(int *tab, int length)
{
	int	i;

	i = 1;
	while (i < length)
	{
		if (tab[i - 1] > tab[i])
			return (0);
		i++;
	}
	return (1);
}

int	is_descend(int *tab, int length)
{
	int	i;

	i = 1;
	while (i < length)
	{
		if (tab[i - 1] < tab[i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	f(length, length);
	if (is_ascend(tab, length) || is_descend(tab, length))
		return (1);
	else
		return (0);
}
