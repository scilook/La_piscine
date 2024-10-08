/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 08:55:51 by hyeson            #+#    #+#             */
/*   Updated: 2024/08/16 20:57:44 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//주소를 통한 역순 정렬은 불가능 << 배열은 주소의 오름차순 대로 조회하기 때문
#include <unistd.h>
#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < size / 2)
	{
		tmp = *(tab + i);
		*(tab + i) = *(tab + size - i - 1);
		*(tab + size - i - 1) = tmp;
		i++;
	}
}
int	main()
{
	int list[] = {99, 50, 10, 40, 50, 27, 11};
	ft_rev_int_tab(list, sizeof(list) / 4);
	for (int i = 0;i < (int) sizeof(list) / 4; i++)
		printf("%d, ", list[i]);
}
