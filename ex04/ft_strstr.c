/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 09:30:53 by hyeson            #+#    #+#             */
/*   Updated: 2024/08/30 10:40:51 by hyeson           ###   ########.fr       */
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

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int result;

	i = -1;
	j = -1;
	if (to_find[0] == '\0')
		return (str);
	while (str[++i] != '\0')
		if (to_find[0] == str[i])
		{
			while (to_find[++j] != '\0' || (str + i)[j] != '\0')
				if (j < ft_strlen(to_find))
					if (to_find[j] != (str + i)[j])
						result = (to_find[j] - (str + i)[j]);
			result = (0);
			if (result == 0)
				return (str + i);
		}
	return (0);
}
