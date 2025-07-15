#include <unistd.h>

int	main(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	if (ac != 2)
		return (write(1, "\n",1), 0);
	while (av[1][i] != '\0')
	{
		j = 0;
		if (av[1][i] >= 'a' && av[1][i] <= 'z')
		{
			while (j <= av[1][i] - 97)
			{
				write (1, &av[1][i], 1);
				j++;
			}
		}
		if (av[1][i] >= 'A' && av[1][i] <= 'Z')
		{
			while (j <= av[1][i] - 97)
			{
				write (1, &av[1][i], 1);
				j++;
			}
		}
		i++;
	}
	return (0);
}
