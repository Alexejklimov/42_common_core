#include <unistd.h>
#include <stdio.h>

char	*ft_strpbrk(const char *s1, const char *s2)
{
	const char	*c;

	while (*s1)
	{
		c = s2;
		while (*c)
		{
			if (*s1 == *c)
				return ((char *)s1);
			c++;
		}
		s1++;
	}
	return (NULL);
}
#include <string.h>
int main (int ac, char **av)
{
	int i;

	i = ac;
	i++;
	printf("test -->%s\n", ft_strpbrk(av[1], av[2]));
	printf("orig -->%s\n", strpbrk(av[1], av[2]));
	return (0);
}