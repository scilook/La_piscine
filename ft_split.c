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
	while (src[i] != '\0')
		i++;
	p = (char *)malloc(i + 1);
	i = 0;
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
	while (find_in_base(str[i], charset) != -1 && str[i] != 0)
	{
		start++;
		i++;
	}
	j = 0;
	while (str[i] != 0)
	{
		end = start;
		while (find_in_base(str[i], charset) == -1 && str[i] != 0)
		{
			end++;
			i++;
		}
		*end = 0;
		strs[j++] = ft_strdup(start);
		*end = charset[0];
		start = end;
		while (find_in_base(str[i], charset) != -1 && str[i] != 0)
		{
			start++;
			i++;
		}
	}
	strs[j] = 0;
	return (strs);
}

#define GREEN "\033[38;5;84m"
#define RED "\033[38;5;197m"
#define GREY "\033[38;5;8m"
#define DEFAULT "\033[0m"
#define CHECKMARK "\xE2\x9C\x93"
#define putchar custom_putchar

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_test
{
    char *desc;
    char *str;
    char *charset;
    char **expected;
} t_test;

int run_tests(t_test *tests, int count);

int main(void)
{
    t_test tests[] = {
       {
            .desc = "Empty string with empty charset",
            .str = "",
            .charset = "",
            .expected = (char *[1]) {0},
        },
        {
            .desc = "Single-word string with empty charset",
            .str = "hello",
            .charset = "",
            .expected = (char *[2]) {"hello", 0},
        },
        {
            .desc = "String with leading and trailing separators",
            .str = ",,hello,world,,",
            .charset = ",",
            .expected = (char *[3]) {"hello", "world", 0},
        },
        {
            .desc = "String with multiple consecutive separators",
            .str = "hello,,,,world",
            .charset = ",",
            .expected = (char *[3]) {"hello", "world", 0},
        },
        {
            .desc = "String with repeated separators",
            .str = "aaabbbaaaccc",
            .charset = "ab",
            .expected = (char *[]){ "ccc", 0 },
        },
    };
    int count = sizeof(tests) / sizeof(tests[0]);

    return run_tests(tests, count);
}

int run_tests(t_test *tests, int count)
{
    int i;
    int error = 0;

    for (i = 0; i < count; i++)
    {
        char **result = ft_split(tests[i].str, tests[i].charset);

        if (!result && !tests[i].expected)
        {
            printf(GREEN CHECKMARK GREY " [%d] %s\n" DEFAULT, i + 1, tests[i].desc);
        }
        else if (!result || !tests[i].expected)
        {
            printf(RED "[%d] %s got \"", i + 1, tests[i].desc);
            if (result)
            {
                printf("%s", result[0]);
                for (int j = 1; result[j]; j++)
                {
                    printf("\", \"%s", result[j]);
                }
            }
            else
            {
                printf("(null)");
            }
            printf("\" instead of \"");
            if (tests[i].expected)
            {
                printf("%s", tests[i].expected[0]);
                for (int j = 1; tests[i].expected[j]; j++)
                {
                    printf("\", \"%s", tests[i].expected[j]);
                }
            }
            else
            {
                printf("(null)");
            }
            printf("\"\n" DEFAULT);
            error -= 1;
        }
        else
        {
            int j = 0;
            while (tests[i].expected[j] && result[j])
            {
                if (strcmp(tests[i].expected[j], result[j]) != 0)
                {
                    printf(RED "[%d] %s Element %d: expected \"%s\", got \"%s\"\n" DEFAULT, i + 1, tests[i].desc, j, tests[i].expected[j], result[j]);
                    error -= 1;
                    break;
                }
                j++;
            }

            if (tests[i].expected[j] != result[j])
            {
                printf(RED "[%d] %s got \"", i + 1, tests[i].desc);
                if (result)
                {
                    printf("%s", result[0]);
                    for (int j = 1; result[j]; j++)
                    {
                        printf("\", \"%s", result[j]);
                    }
                }
                else
                {
                    printf("(null)");
                }
                printf("\" instead of \"");
                if (tests[i].expected)
                {
                    printf("%s", tests[i].expected[0]);
                    for (int j = 1; tests[i].expected[j]; j++)
                    {
                        printf("\", \"%s", tests[i].expected[j]);
                    }
                }
                else
                {
                    printf("(null)");
                }
                printf("\"\n" DEFAULT);
                error -= 1;
            }
            else
            {
                printf(GREEN CHECKMARK GREY " [%d] %s got \"", i + 1, tests[i].desc);
                if (result)
                {
                    printf("%s", result[0]);
                    for (int j = 1; result[j]; j++)
                    {
                        printf("\", \"%s", result[j]);
                    }
                }
                printf("\" as expected\n" DEFAULT);
            }
        }

        if (result)
        {
            int j = 0;
            while (result[j])
            {
                free(result[j]);
                j++;
            }
            free(result);
        }
    }

    return (error);
}