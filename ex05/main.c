/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 14:54:59 by hyeson            #+#    #+#             */
/*   Updated: 2024/09/01 16:26:17 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	cnt;

	cnt = 0;
	while (*(str + cnt) != '\0')
		cnt++;
	return (cnt);
}

void	ft_putnbr(int nb)
{
	char	chnbr[10];
	int		i;

	i = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb == 0)
		write(1, "0", 1);
	if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
	}
	while (nb != 0)
	{
		chnbr[i++] = nb % 10 + '0';
		nb /= 10;
	}
	while (i != 0)
		write(1, &chnbr[--i], 1);
}

int	ft_atoi(char *str)
{
	int	i;
	int	value;
	int	flag;

	value = 0;
	flag = 1;
	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] >= 0x30 && str[i] <= 0x39)
		{
			value = 10 * value + str[i] - 0x30;
			if ((str[i + 1] >= 0x30 && str[i + 1] <= 0x39) == 0)
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

int	error_check(int ac, char *av)
{
	if (ac != 4)
		return (-1);
	if (ft_strlen(av) != 1)
	{
		write(1, "0\n", 2);
		return (-1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	if (error_check(ac, av[2]) == -1)
		return (-1);
	if (av[2][0] == '+')
		ft_putnbr(ft_atoi(av[1]) + ft_atoi(av[3]));
	else if (av[2][0] == '-')
		ft_putnbr(ft_atoi(av[1]) - ft_atoi(av[3]));
	else if (av[2][0] == '*')
		ft_putnbr(ft_atoi(av[1]) * ft_atoi(av[3]));
	else if (av[2][0] == '/')
	{
		if (ft_atoi(av[3]) != 0)
			ft_putnbr(ft_atoi(av[1]) / ft_atoi(av[3]));
		else
			write(1, "Stop : division by zero", 23);
	}
	else if (av[2][0] == '%')
	{
		if (ft_atoi(av[3]) != 0)
			ft_putnbr(ft_atoi(av[1]) % ft_atoi(av[3]));
		else
			write(1, "Stop : modulo by zero", 21);
	}
	else
		write(1, "0\n", 2);
	return (0);
}
