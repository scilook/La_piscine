/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:30:48 by hyeson            #+#    #+#             */
/*   Updated: 2024/08/23 16:42:01 by hyeson           ###   ########.fr       */
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

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	dstlen;

	i = -1;
	dstlen = ft_strlen(dest);
	while (src[++i] != '\0')
		dest[dstlen + i] = src[i];
	dest[dstlen + i] = '\0';
	return (dest);
}
