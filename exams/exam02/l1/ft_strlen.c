#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}
#include <stdio.h>
int main (void)
{
	char *q = " ";
	int res = 0;

	res = ft_strlen(q);
	printf("-->%d", res);
	return (0);
}