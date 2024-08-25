/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:02:20 by hyeson            #+#    #+#             */
/*   Updated: 2024/08/25 16:51:11 by hyeson           ###   ########.fr       */
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

int	find_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi(char *str)
{
	int	i;
	int	value;
	int	flag;

	value = 0;
	flag = 1;
	i = -1;
	while (find_in_base(str[++i], " \x09\x0a\x0b\x0c\x0d") != -1)
		continue ;
	i--;
	while (str[++i] != '\0')
	{
		if (str[i] >= 0x30 && str[i] <= 0x39)
		{
			value = 10 * value + str[i] - 0x30;
			if ((str[i + 1] >= 0x30 && str[i + 1] <= 0x39) == 0)
				return (flag * value);
		}
		else if (str[i] == '-')
			flag = -flag;
		else if (str[i] == '+')
			continue ;
		else
			return (flag * value);
	}
}
