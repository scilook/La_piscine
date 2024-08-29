#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int	ft_strlen(char *str)
{
	int	cnt;

	cnt = 0;
	while (*(str + cnt) != '\0')
		cnt++;
	return (cnt);
}

char	*ft_strdup(char *src)
{
	char	*p;
	int		i;

	i = 0;
	p = (char *)malloc(sizeof(src));
	while (src[i] != '\0')
	{
		p[i] = src[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
int main()
{
	char ch[100] = "google";
	char *c = ft_strdup(ch);
	printf("%s, %d, %d" , c, sizeof(ft_strdup(ch)), sizeof(ch));
}