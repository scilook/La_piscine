/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 09:10:45 by hyeson            #+#    #+#             */
/*   Updated: 2024/08/29 17:03:17 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

int	find_in_base(char c, char *base);

int	ft_strlen(char *str)
{
	int	cnt;

	cnt = 0;
	while (*(str + cnt) != '\0')
		cnt++;
	return (cnt);
}

char	*ft_strndup(char *src, int size)
{
	char	*p;
	int		i;

	i = 0;
	p = (char *)malloc(ft_strlen(src) + 1);
	while (src[i] != '\0' && i < size)
	{
		p[i] = src[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*base_encoder(long long int n, char *base, int flag)
{
	int		i;
	int		cp;
	char	*chnbr_rev;

	if (n == 0)
		return (ft_strndup(base, 1));
	i = -1;
	cp = n;
	while (cp != 0 && ++i > -1)
		cp /= ft_strlen(base);
	chnbr_rev = (char *)malloc(sizeof(char) * (i + (int)(flag < 0)));
	i = 0;
	while (n != 0)
	{
		chnbr_rev[i++] = base[n % ft_strlen(base)];
		n /= ft_strlen(base);
	}
	if (flag == -1)
		chnbr_rev[i] = '-';
	return (chnbr_rev);
}

char	*ft_rev_int_tab(char *tab, int size)
{
	int		i;
	char	tmp;

	i = 0;
	while (i < size / 2)
	{
		tmp = *(tab + i);
		*(tab + i) = *(tab + size - i - 1);
		*(tab + size - i - 1) = tmp;
		i++;
	}
	return (tab);
}
