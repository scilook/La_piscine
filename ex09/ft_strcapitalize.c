/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 14:12:32 by hyeson            #+#    #+#             */
/*   Updated: 2024/08/20 12:46:28 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	is_alnum(char str)
{
	if (str >= 'A' && str <= 'Z')
		return (1);
	else if (str >= 'a' && str <= 'z')
		return (1);
	else if (str >= '0' && str <= '9')
		return (1);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (is_alnum(str[i]) == 1)
			if (str[i] >= 'A' && str[i] <= 'Z')
				str[i] += 0x20;
		i++;
	}
	i = 0;
	while (str[i] != '\0')
	{
		if (is_alnum(str[i]) == 0)
			if (str[i + 1] >= 'a' && str[i + 1] <= 'z')
				str[i + 1] -= 0x20;
		i++;
	}
	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] -= 0x20;
	return (str);
}
