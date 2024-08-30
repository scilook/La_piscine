/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 20:04:52 by hyeson            #+#    #+#             */
/*   Updated: 2024/08/29 15:16:00 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

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

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*dst;
	int		i;
	int		bufsize;

	i = -1;
	bufsize = 0;
	while (++i < size)
	{
		bufsize += ft_strlen(strs[i]);
		if (i < size - 1)
			bufsize += ft_strlen(sep);
	}
	dst = (char *)malloc(sizeof(char) * (bufsize + 1));
	if (bufsize == 0)
		dst = 0;
	i = -1;
	dst[0] = '\0';
	while (++i < size)
	{
		ft_strcat(dst, strs[i]);
		if (i < size - 1)
			ft_strcat(dst, sep);
	}
	dst[bufsize] = '\0';
	return (dst);
}
