/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:02:20 by hyeson            #+#    #+#             */
/*   Updated: 2024/08/24 10:30:21 by hyeson           ###   ########.fr       */
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

int	ft_atoi(char *str)
{
	int	i;
	int	value;
	int	flag;

	i = -1;
	value = 0;
	flag = 1;
	while (str[++i] != 0)
	{
		if (str[i] >= 0x30 && str[i] <= 0x39)
		{
			value = 10 * value + str[i] - 0x30;
			if ((str[i + 1] >= 0x30 && str[i + 1] <= 0x39) == 0)
				break ;
		}
		else if (str[i] == '-')
			flag = -flag;
	}
	return (flag * value);
}
