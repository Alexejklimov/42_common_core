#include <unistd.h>
#include <string.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	int		i;
	int		j;

	i = 0;
	if (s[i] == '\0')
		return (0);
	while (s[i] != '\0')
	{
		j = 0;
		while (reject[j] !='0')
		{
			if (s[i] == reject[j])
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}
#include <stdio.h>
int main(int ac, char **av)
{
	int i = ac;

	i++;
	printf("test--> %ld\n", ft_strcspn(av[1], av[2]));
	printf("origin--> %ld\n", strcspn(av[1], av[2]));
	return (0);
}