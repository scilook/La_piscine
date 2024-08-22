/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:19:26 by hyeson            #+#    #+#             */
/*   Updated: 2024/08/22 14:44:50 by hyeson           ###   ########.fr       */
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

/* size < strlen(dest)이면 dest 버퍼의 크기를 size로 축소시켜야 한다.*/
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

#include <stdio.h>
int	main(void)
{
	char ch[] = "1234567890";
	char dst[50] = "alaisalive";
	printf("%d %s", ft_strlcat(dst, ch, 5), dst);
}
