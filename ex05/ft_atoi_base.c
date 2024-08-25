/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 09:15:54 by hyeson            #+#    #+#             */
/*   Updated: 2024/08/25 16:42:05 by hyeson           ###   ########.fr       */
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

int	ft_error(char *base, char *str, int *k)
{
	int	i;
	int	j;

	while (find_in_base(str[++(*k)], " \x09\x0a\x0b\x0c\x0d") != -1)
		continue ;
	(*k)--;
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
	i = -1;
	if (ft_error(base, str, &i) == 1 || ft_strlen(base) < 2)
		return (0);
	while (str[++i] != '\0')
	{
		if (find_in_base(str[i], base) != -1)
		{
			value = ft_strlen(base) * value + find_in_base(str[i], base);
			if (find_in_base(str[i + 1], base) == -1)
				return (flag * value);
		}
		else if (str[i] == '-')
			flag = -flag;
		else if (str[i] == '+')
			flag = flag;
		else
			return (flag * value);
	}
}

#include <stdio.h>
int	ft_atoi_base(char *str, char *base);
int main(void)
{
	printf("%d\n", ft_atoi_base("1234567890", "0123456789"));
	printf("%d\n", ft_atoi_base("10000000000000000", "01"));
	printf("%d\n", ft_atoi_base("5F5E100", "0123456789ABCDEF"));
	printf("%d\n", ft_atoi_base("104133633034", "0123456"));
	printf("%d\n", ft_atoi_base("-13344221014043", "01234"));
	printf("%d\n\n", ft_atoi_base("5EHL50J", "0123456789ABCDEFGHIJKLMNOPQ"));

	printf("%d\n", ft_atoi_base("!@#$%^&*()", ")!@#$%^&*("));
	printf("%d\n", ft_atoi_base("IOOOOOOOOOOOOOOOO", "OI"));
	printf("%d\n", ft_atoi_base("<C<B\"\'\'", "\'\"\?>.<,QWERT ABC"));
	printf("%d\n", ft_atoi_base("Qa QRRtRRaR ", "aQqR Tt"));
	printf("%d\n", ft_atoi_base("-_{{}}||_=_}=}{", "=_|{}"));
	printf("%d\n", ft_atoi_base("D'wyDZr", "ZXCS DF12345;:'\"qwertyas@#$"));
	printf("%d\n", ft_atoi_base("^$G$M", "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!@#$%^&*()_= "));
	printf("%d\n\n", ft_atoi_base("!", "!@#$"));

	printf("T1: %d\n", ft_atoi_base("123456", "1234563"));
	printf("T2: %d\n", ft_atoi_base("1234", "12345-64"));
	printf("T3: %d\n", ft_atoi_base("1234", "12345678+"));
	printf("T4: %d\n", ft_atoi_base("", "1"));
	printf("T5: %d\n", ft_atoi_base("12345", ""));
	printf("T6: %d\n", ft_atoi_base("12345", "a12356a7"));
	printf("T7: %d\n", ft_atoi_base("     \t\v\f     +---------++-1235aaa776644", "a123567"));
	printf("T7: %d\n", ft_atoi_base("     \n\r\t     +---------++-1235aaa7766"  , "a123567"));
	printf("T8: %d\n", ft_atoi_base("            +----8----++-1235aaa7766", "a123567"));
	return 0;
}