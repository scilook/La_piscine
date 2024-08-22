/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 09:30:53 by hyeson            #+#    #+#             */
/*   Updated: 2024/08/22 13:29:27 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return (s1[i] - s2[i]);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
		if (to_find[0] == str[i])
			if (ft_strcmp(to_find, str + i) == 0)
				break ;
	return (str + i);
}

/*#include <stdio.h>
int	main(void)
{
	char ch[] = "1234567890";
	char dst[50] = "567890123456789";
	printf("%s %s", ft_strstr(dst, ch), dst);
}*/