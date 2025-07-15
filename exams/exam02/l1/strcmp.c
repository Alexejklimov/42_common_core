#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] !='\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}
#include <stdio.h>
int	main (void)
{
	int i;
	char *s = "qqq";
	char *q = "qqq";
	printf("s1-->%s<--\n s2-->%s<--\n", s, q);
	printf("%d", ft_strcmp(s, q));
	return (0);
}