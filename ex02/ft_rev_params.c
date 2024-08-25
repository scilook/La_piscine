/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 20:35:51 by hyeson            #+#    #+#             */
/*   Updated: 2024/08/24 21:37:51 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	cnt;

	cnt = 0;
	while (*(str + cnt) != '\0')
		cnt++;
	return (cnt);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i + 1 < argc)
	{
		write(1, argv[argc - i], ft_strlen(argv[argc - i]));
		write(1, "\n", 1);
	}
}
