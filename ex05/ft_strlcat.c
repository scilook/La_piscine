/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:19:26 by hyeson            #+#    #+#             */
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

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	dstlen;

	dstlen = ft_strlen(dest);
	if (dstlen > size)
		return (size + ft_strlen(src));
	i = -1;
	while (src[++i] != '\0' && (i + dstlen + 1) < size)
		dest[dstlen + i] = src[i];
	dest[dstlen + i] = '\0';
	return (ft_strlen(src) + dstlen);
}
