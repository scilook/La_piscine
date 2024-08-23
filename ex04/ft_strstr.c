/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 09:30:53 by hyeson            #+#    #+#             */
/*   Updated: 2024/08/23 16:42:03 by hyeson           ###   ########.fr       */
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

int	ft_strcmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = -1;
	if (ft_strlen(s1) > ft_strlen(s2))
	{
		while (s1[++i] != '\0' && i < n)
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	else
	{
		while (s2[++i] != '\0' && i < n)
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;

	i = -1;
	while (str[++i] != '\0' && to_find[0] != '\0')
		if (to_find[0] == str[i])
			if (ft_strcmp(to_find, str + i, ft_strlen(to_find)) == 0)
				break ;
	return (str + i);
}
