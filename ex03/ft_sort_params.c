/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 20:38:33 by hyeson            #+#    #+#             */
/*   Updated: 2024/08/26 21:48:54 by hyeson           ###   ########.fr       */
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

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_sort_int_tab(char **tab, int size)
{
	char	*tmp;
	int		i;
	int		j;

	j = 0;
	while (++j < size)
	{
		i = j;
		while (i > 0)
		{
			tmp = tab[i];
			if (ft_strcmp(tab[i], tab[i - 1]) < 0)
			{
				tab[i] = tab[i - 1];
				tab[i - 1] = tmp;
			}
			else
				break ;
			i--;
		}
	}
}

int	main(int argc, char **argv)
{
	int		i;

	ft_sort_int_tab(&argv[1], argc - 1);
	i = 0;
	while (++i < argc)
	{
		write(1, argv[i], ft_strlen(argv[i]));
		write(1, "\n", 1);
	}
	return (0);
}
