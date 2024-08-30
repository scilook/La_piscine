/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 16:00:48 by hyeson            #+#    #+#             */
/*   Updated: 2024/08/30 18:30:48 by hyeson           ###   ########.fr       */
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

int	find_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strdup(char *src)
{
	char	*p;
	int		i;

	i = 0;
	p = (char *)malloc(ft_strlen(src) + 1);
	while (src[i] != '\0')
	{
		p[i] = src[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

unsigned int	word_counter(char *str, char *charset)
{
	int	i;
	int	cnt;
	int	inset;

	i = 0;
	cnt = 0;
	inset = 1;
	while (str[i] != '\0')
	{
		if (inset == 1 && find_in_base(str[i], charset) == -1)
		{
			cnt++;
			inset = 0;
		}
		if (inset == 0 && find_in_base(str[i], charset) != -1)
		{
			inset = 1;
		}
		i++;
	}
	return (cnt);
}

char	**ft_split(char *str, char *charset)
{
	char	**strs;
	char	*start;
	char	*end;
	int		i;
	int		j;

	i = 0;
	strs = (char **)malloc(sizeof(char *) * (word_counter(str, charset) + 1));
	start = ft_strdup(str);
	while (find_in_base(str[i], charset) != -1)
	{
		start++;
		i++;
	}
	j = 0;
	while (str[i] != 0)
	{
		end = start;
		while (find_in_base(str[i], charset) == -1)
		{
			end++;
			i++;
		}
		*end = 0;
		strs[j++] = ft_strdup(start);
		*end = charset[0];
		start = end;
		while (find_in_base(str[i], charset) != -1)
		{
			start++;
			i++;
		}
	}
	strs[j] = 0;
	return (strs);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	**ft_split(char *str, char *charset);

void do_test(char* str, char* charset)
{
	char	**array;
	int		i;

	array = ft_split(str, charset);
	i = 0;
	while (array[i])
	{
		printf("'%s' (len=%d)\n", array[i], (int)strlen(array[i]));
		i++;
	}
}

int main(void)
{
	do_test(",1,2,3", ",");
	do_test("Hello.,World,.!!KOKO!ZZZ.Hello.Good.World!KK!ZORO,Good", ",.!");
	do_test("abcakaabcaakaabce", "bck");
	do_test("|---AA-|GoogooGooGoo|aaaa-| Hello World Good| ^^|Nice Boat!", " |-");
	do_test("               ", "     ");
	do_test("  \t ", " \t");
	do_test("123,456,789 ,", ",l1");
	do_test("0tNue8", "0tNue8");
	do_test("80hzNIGZYoIa3ATwY8dRCFmBBYx0RA", "AKfwjE5l");
	return 0;
}