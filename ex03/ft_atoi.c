/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:02:20 by hyeson            #+#    #+#             */
/*   Updated: 2024/08/24 15:27:12 by hyeson           ###   ########.fr       */
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
#include <stdio.h>
int	ft_atoi(char* str);
int main(void)
{
	printf("%d\n", ft_atoi("1234"));
	printf("%d\n", ft_atoi("5678"));
	printf("%d\n", ft_atoi("-1234"));
	printf("%d\n", ft_atoi("-5678"));
	printf("%d\n", ft_atoi("-1"));
	printf("%d\n", ft_atoi("0"));
	printf("%d\n", ft_atoi("1"));
	printf("%d\n", ft_atoi("-2147483648"));
	printf("%d\n", ft_atoi("2147483647"));

	printf("%d\n", ft_atoi("    +----++-2147483648"));
	printf("%d\n", ft_atoi("+------+0"));
	printf("%d\n", ft_atoi("\t\v----------++5123145"));
	printf("%d\n", ft_atoi("\n\f----------+-+5123145"));
	printf("%d\n", ft_atoi("\r     \n\t\v\n\f---++-----++2123133345"));

	printf("%d\n", ft_atoi("    +----++-2147483asdas648"));
	printf("%d\n", ft_atoi("+------+10000001"));
	printf("%d\n", ft_atoi(" +-----------+00000000000000000000000\t\v\f\n 000000000000000000"));
	printf("%d\n", ft_atoi("\t\v----------++5123--145"));
	printf("%d\n", ft_atoi("\n\f----------+-+5123+145"));
	printf("%d\n", ft_atoi("\r     \n\t\v\n\f---++-----++212  3133345"));
	return 0;
}