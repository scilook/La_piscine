/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 09:15:54 by hyeson            #+#    #+#             */
/*   Updated: 2024/08/24 15:26:44 by hyeson           ###   ########.fr       */
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

int	find_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	value;
	int	flag;

	value = 0;
	flag = 1;
	if (ft_error(base) == 1 || ft_strlen(base) < 2)
		return (0);
	i = -1;
	while (str[++i] != '\0')
	{
		if (find_in_base(str[i], base) != -1)
		{
			value = ft_strlen(base) * value + find_in_base(str[i], base);
			if (find_in_base(str[i + 1], base) == -1)
				break ;
		}
		else if (str[i] == '-')
			flag = -flag;
	}
	return (flag * value);
}
