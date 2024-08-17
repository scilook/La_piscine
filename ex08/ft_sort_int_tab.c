/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 09:49:53 by hyeson            #+#    #+#             */
/*   Updated: 2024/08/16 21:00:25 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//오름차순 정렬 (insert sort algorithm)

#include <stdio.h>
void	ft_sort_int_tab(int *tab, int size)
{
	int	tmp;
	int	i;
	int	j;

	j = 0;
	while (++j < size)
	{
		i = j;
		while (i > 0)
		{
			tmp = tab[i];
			if (tmp < tab[i - 1])
			{
				tab[i] = tab[i - 1];
				tab[i - 1] = tmp;
			}
			i--;
		}
	}
}

int	main()
{
	int list[] = {99, 50, 10, 40, 50, 27, 11};
	ft_sort_int_tab(list, sizeof(list) / 4);
	for (int i = 0;i < (int) sizeof(list) / 4; i++)
		printf("%d, ", list[i]);
}