/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:43:38 by hyeson            #+#    #+#             */
/*   Updated: 2024/08/22 13:28:32 by hyeson           ###   ########.fr       */
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

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	int				dstlen;

	i = -1;
	dstlen = ft_strlen(dest);
	while (src[++i] != '\0' && i < nb)
		dest[dstlen + i] = src[i];
	dest[dstlen + i] = '\0';
	return (dest);
}

/* #include <stdio.h>
int	main(void)
{
	char ch[] = "1234567890";
	char dst[50] = "alaisalive";
	printf("%s", ft_strncat(dst, ch, 11));
} */