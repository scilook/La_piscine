/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 19:16:30 by hyeson            #+#    #+#             */
/*   Updated: 2024/08/30 11:44:43 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

int	ft_strlen(char *str)
{
	int	cnt;

	cnt = 0;
	while (*(str + cnt) != '\0')
		cnt++;
	return (cnt);
}

char	*ft_strdup(char *src)
{
	char	*p;
	int		i;

	i = 0;
	p = (char *)malloc(ft_strlen(src) + 1);
	while (src[i] != '\0')
	{
		p[i] = src[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
