/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 09:06:47 by hyeson            #+#    #+#             */
/*   Updated: 2024/08/29 17:41:39 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

char	*ft_strndup(char *src, int size);
char	*base_encoder(long long int n, char *base, int flag);
char	*ft_rev_int_tab(char *tab, int size);
int		ft_strlen(char *str);

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

void	whitespace_skip(int *i, char *str)
{
	*i = -1;
	while (find_in_base(str[++(*i)], " \x09\x0a\x0b\x0c\x0d") != -1)
		continue ;
	(*i)--;
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
		if (find_in_base(base[i], "+- \x09\x0a\x0b\x0c\x0d") != -1)
			return (1);
	}
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	value;
	int	flag;

	value = 0;
	flag = 1;
	whitespace_skip(&i, str);
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
		else if (str[i] == '+')
			continue ;
		else
			break ;
	}
	return (flag * value);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*point;
	int		value;
	int		flag;

	if (ft_strlen(base_from) < 2 || ft_error(base_from) == 1)
		return (0);
	if (ft_strlen(base_to) < 2 || ft_error(base_to) == 1)
		return (0);
	flag = 1;
	value = ft_atoi_base(nbr, base_from);
	if (value < 0)
	{
		value = -value;
		flag *= -1;
	}
	point = base_encoder(value, base_to, flag);
	return (ft_rev_int_tab(point, ft_strlen(point)));
}
