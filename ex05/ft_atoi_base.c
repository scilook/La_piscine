/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 09:15:54 by hyeson            #+#    #+#             */
/*   Updated: 2024/08/24 13:57:18 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	cnt;

	cnt = 0;
	while (*(str + cnt) != '\0')
		cnt++;
	return (cnt);
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
		if (base[i] == '+' || base[i] == '-' || base[i] == ' ')
			return (1);
	}
	return (0);
}


// int	flag_counter(char *str, char *base)
// {
// 	int flag;
// 	int i;

// 	int i = 0;
// 	flag = 1;
// 	while(i < ft_strlen(base))
// 		if (str[i] == '-')
// 			flag = -flag;
// 		if (str)

// }

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	j;
	int	k;
	int	value;
	int	flag;

	value = 0;
	flag = 1;
	if (ft_error(base) == 1 || ft_strlen(base) < 2)
		return (0);
	i = -1;
	while (str[++i] != '\0')
	{
		j = -1;
		A:
		while (++j < ft_strlen(base))
			if (str[i] == base[j])
			{
				value = ft_strlen(base) * value + j;
				k = -1;
				while (k < ft_strlen(base))
					if (str[i + 1] == base[++k])
						goto A;
				return ((flag * value));
			}
		if (str[i] == '-')
			flag = -flag;
	}
	return (flag * value);
}

#include <stdio.h>

int main()
{
	printf("%d", ft_atoi_base("-+937-3747", "937"));
}