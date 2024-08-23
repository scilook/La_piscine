/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:21:01 by hyeson            #+#    #+#             */
/*   Updated: 2024/08/23 16:42:00 by hyeson           ###   ########.fr       */
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

int	ft_strncmp(char *s1, char *s2, unsigned int n)
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
