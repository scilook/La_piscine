/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:21:01 by hyeson            #+#    #+#             */
/*   Updated: 2024/08/22 14:42:47 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' && i < n)
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return (s1[i] - s2[i]);
}

/* #include <stdio.h>
int	main(void)
{
	char	dst[] = "a";
	char	ch[] = {'a', '1'};
	printf("%d %s", ft_strncmp(dst, ch, 2), dst);
} */
