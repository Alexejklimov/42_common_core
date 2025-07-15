#include <unistd.h>
#include <string.h>

size_t	ft_strspn(const char *s, const char *charset)
{
	size_t	i;
	int	j;
	int	checker;

	i = 0;
	while (s[i] != '\0')
	{
		checker = 0;
		j = 0;
		while (charset[j] != '\0')
		{
			if (s[i] == charset[j])
				checker = 1;
			j++;
		}
		if (checker == 0)
			return (i);
		checker = 0;
		i++;
	}
	return (i);
}

#include <stdio.h>
int main(int ac, char **av)
{
	int i = ac;

	i++;
	printf("test--> %ld\n", ft_strspn(av[1], av[2]));
	printf("origin--> %ld\n", strspn(av[1], av[2]));
	return (0);
}
